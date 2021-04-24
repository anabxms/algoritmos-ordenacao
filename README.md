# Como utilizar

## Haskell

Antes de iniciar, instale a plataforma do Haskell em seu computador. Se você estiver no linux, basta copiar a seguinte linha no seu terminal:
```
$ sudo apt-get install haskell-platform
```

Clone este repositório:

```
$ git clone <https://github.com/anabxms/algoritmos-ordenacao>
```

Abra o **GHCI**, que é o modo interativo do Haskell 

```
$ ghci
```

Agora, você poderá carregar as funções digitando ```:l sorting_algorithms.hs```, desde que o arquivo esteja na mesma pasta na qual o ghci foi invocado.

## C

Clone este repositório:

```
$ git clone <https://github.com/anabxms/algoritmos-ordenacao>
```

Abra o terminal e compile o programa:

```
gcc-10 sorting_algorithms.c -o sorting_algorithms
./sorting_algorithms
```

# Como funcionam os algoritmos de ordenação?

## Insertion Sort

1. Pega o item e compara com o da esquerda.
2. Se o item é menor que o da esquerda, trocam de lugar.
3. Continua trocando até atingir um item menor que o item atual.
4. Repete até atingir o último elemento da direita.

- É muito eficiente para arrays parcialmente classificados, ou minúsculos (menos de 20 elementos);

## Selection Sort

1. Encontra o menor número do array.
2. Coloca ele no primeiro índice.
3. Encontra o próximo menor elemento e coloca no próximo índice.
4. Repete até a lista estar toda ordenada.

- Cada troca coloca um item em sua posição final, de modo que o número de trocas é N. Assim, o tempo de execução é denominado pelo número de comparações.
- A desvantagem em relação ao Insertion Sort é que enquanto o Insertion verifica apenas os elementos necessários para colocar o k + 1º elemento, o Selection verifica todos os elementos restantes para encontrar o k + 1º elemento.

## Bubble Sort

1. Se o elemento da esquerda for maior que o da direita, trocam de lugar
2. Repete até o fim do array.
3. Retorna pra o início e repete até o último elemento já ordenado.
4. Repete esse processo até todo o array estar ordenado.

- É muito lento, faz muitas comparações e leva muito tempo, porém é um algoritmo bastante fácil de entender. Pode ser útil se você não se preocupar com quanto tempo um algoritmo levará ou se você tiver um conjunto muito pequeno de dados para classificar.

## Heap Sort

1. Quando a raiz do node é o maior elemento, faz um buildMaxHeap
2. Troca a raiz do node com o elemento do último index
3. Remove o elemento e diminui o tamanho do heap em 1
4. Faz heapify, para que pegue novamente o maior elemento da raiz
5. Repete até que todos os elementos estejam ordenados

**Heapify** é o processo de criar uma estrutura de dados  heap a partir de uma árvore binária
1. Seleciona o array inserido
2. Transforma o array em  uma árvore binária
3. Cria um heap a partir da árvore binária

- Quando o espaço é muito apertado, é ótimo, porque pode ser implementado com poucas linhas, enquanto ainda tem um desempenho ideal, porém tem baixo desempenho de cache.
- Similar ao Selection Sort, mas enquanto o Selection tem performance em tempo quadrático, o Heap funciona em tempo logarítmico, pois árvores binárias são logarítmicas por natureza.

## Merge Sort

1. Divide a lista consecutivamente;
2. Une as listas, ordenando-as na ordem correta;

- Tende a ser muito mais fácil classificar duas listas menores e classificadas do que classificar uma única lista grande e não classificada.
- A complexidade de tempo do Merge Sort é uma combinação de tempos lineares e logarítmicos; isso é referido como tempo linearítmico;
- Como o Merge Sort é implementado como um algoritmo de classificação externo, ele pode fazer o trabalho de classificação fora da memória principal e, posteriormente, pode puxar os dados classificados de volta para a memória principal interna.

## Quick Sort

1. Define qual elemento será o pivô
2. Divide a lista em 2, os menores e os maiores que o pivô
3. Coloca os elementos menores a esquerda e os maiores na direita
4. Escolhe um novo pivô e repete até a lista estar ordenada

- O Quick Sort permite uma ordenação "in-place", ou seja, poupa muita memória durante sua execução. Esse é um dos principais motivos dele ser um dos algoritmos mais utilizados.
- Não é um bom algoritmo para arrays quase ou completamente classificados.
- É um algoritmo instável, o que significa que não é garantido que ele preservará a ordem dos elementos conforme ele reordena; dois elementos que são exatamente iguais no array não classificado podem aparecer em ordem reversa no classificado. A estabilidade acaba sendo o principal fator que faz com que as pessoas escolham o Merge Sort.

# Comparação entre os algoritmos

## Casos de teste

![Testes Gráfico](https://i.imgur.com/h2IGeQk.png)

## Complexidade

![Complexidade](https://i.imgur.com/9HZvDHG.png)
