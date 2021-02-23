{-# LANGUAGE BangPatterns #-}
import Control.DeepSeq
import Text.Printf
import System.IO
import System.CPUTime
import Control.Exception
import Data.Time.Clock

main :: IO()
main = do
    
    putStrLn "Selecione o algoritmo que você quer executar:"
    putStrLn "1) Insertion Sort"
    putStrLn "2) Selection Sort"
    putStrLn "3) Bubble Sort"
    putStrLn "4) Heap Sort"
    putStrLn "5) Merge Sort"
    putStrLn "6) Quick Sort"

    algoritmo <- getLine
    let escolha | algoritmo == "1" = insertion
                | algoritmo == "2" = selection
                | algoritmo == "3" = bubble
                | algoritmo == "4" = heap
                | algoritmo == "5" = merge
                | algoritmo == "6" = quick

    putStrLn "Selecione o algoritmo que você quer executar:"
    putStrLn "1) 1000"
    putStrLn "2) 5000"
    putStrLn "3) 10000"
    putStrLn "4) 20000"
    putStrLn "5) 50000"
    putStrLn "6) 75000"
    putStrLn "7) 100000"

    arq <- getLine
    let arquivo | arq == "1" = "1000.txt"
                | arq == "2" = "5000.txt"
                | arq == "3" = "10000.txt"
                | arq == "4" = "20000.txt"
                | arq == "5" = "50000.txt"
                | arq == "6" = "75000.txt"
                | arq == "7" = "100000.txt"
    conteudo <- readFile arquivo
    let qtd_numeros = map (\x -> read x::Int) (words conteudo)

    inicio <- getCPUTime
    let !sortMap = rnf $ escolha qtd_numeros
    fim <- getCPUTime
    let tempo = fromIntegral(fim - inicio) / (10 ^ 12)
    printf "Tempo de execução: %0.5f ms\n" (tempo :: Double)


-- Insertion Sort

insertion ::(Ord a) => [a] -> [a]
insertion [] = []
insertion (x:xs) = ordenar x (insertion xs)

ordenar::(Ord a) => a -> [a] -> [a]
ordenar r [] = [r]
ordenar r (x:xs) | r <= x = r:x:xs
                 | otherwise = x : ordenar r xs  

-- Selection Sort

menor :: (Ord a) => [a] -> a
menor [r] = r
menor (r:x:xs) | r <= x = menor(r:xs)
               | otherwise = menor(x:xs)


selection :: (Ord a) => [a] -> [a]
selection [] = []
selection xs = let  x = menor xs  
           in  x : selection (excluir x xs) 


excluir :: (Ord a) => a -> [a] -> [a]
excluir _ [] = []
excluir r (x:xs)    | r == x = xs
                    | otherwise = x : excluir  r xs

-- Bubble Sort

bubble :: (Ord a) => [a] -> [a]
bubble [] = []
bubble [r] = [r]
bubble (r:x:xs)    | ordenado par = par 
                   | otherwise =  bubble par
    where par = menor' r x : bubble (maior r x : xs) 
 
ordenado :: (Ord a) => [a] -> Bool
ordenado [] = True
ordenado [r] = True
ordenado (r:x:xs) |  r <= x = ordenado (x:xs)
                  | otherwise =  False  


menor' :: (Ord a) => a -> a -> a
menor' r x  | r <= x = r
           | otherwise = x

maior :: (Ord a) => a -> a -> a
maior r x  | r >= x = r
           | otherwise = x

-- Heap Sort

trocar :: [Int] -> Int -> Int -> [Int]
trocar x a b | a == b = x
             | b < a = trocar x b a
             | otherwise = take a x ++ [x !! b] ++ drop (a + 1) (take b x) ++ [x !! a] ++ drop (b + 1) x

excluirUltimo :: [Int] -> [Int]
excluirUltimo [x] = []
excluirUltimo [] = []
excluirUltimo x = take (length x-1) x


ordenarArvore :: [Int] -> Int -> [Int]
ordenarArvore x i | direita i < length x && (x !! direita i >= x !! esquerda i) && (x !! direita i > x !! i) = ordenarArvore (trocar x i (direita i)) (direita i)
                  | esquerda i < length x && (x !! esquerda i > x !! i) = ordenarArvore (trocar x i (esquerda i)) (esquerda i)
                  | otherwise = x
                    where esquerda t = 2 * t + 1
                          direita t = 2 * t + 2

maxHeapify :: [Int] -> [Int]
maxHeapify [x] = [x]
maxHeapify [] = []
maxHeapify (x:xs) = maxHeapify (ordenarArvore (last xs : excluirUltimo xs) 0) ++ [x]

buildMaxHeap :: [Int] -> Int -> [Int]
buildMaxHeap x y | y >= 0 = buildMaxHeap (ordenarArvore x y) (y - 1)
                 | otherwise = x


heap :: [Int] -> [Int]
heap x = maxHeapify (buildMaxHeap x ((length x-2) `div` 2))

-- Merge Sort

intercala :: Ord a => [a] -> [a] -> [a]
intercala  x [ ] = x
intercala [ ] y  = y
intercala (x:xs) (y:ys) | x <= y    = x : intercala xs (y:ys)
                        | otherwise = y : intercala (x:xs) ys

inicio :: [a] -> [a]
inicio xs = take (length xs `div` 2) xs

fim :: [a] -> [a]
fim xs = drop (length xs `div` 2) xs
                        
merge :: Ord a => [a] -> [a]
merge [ ] = [ ]
merge [x] = [x]
merge xs  = intercala (merge (inicio xs)) (merge (fim xs))

                  
-- Quick Sort


left :: (Ord a) => [a] -> [a]
left [] = []
left (x:xs) = filter (<x) xs

right :: (Ord a) => [a] -> [a]
right [] = []
right (x:xs) = filter (>=x) xs

quick :: (Ord a) => [a] -> [a]
quick [] = []
quick (x:xs) = quick (left (x:xs)) ++ [x] ++ quick (right (x:xs))
