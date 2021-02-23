#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// =-=-=-= Insertion Sort  =-=-=-= //

void insertion(int vtr[],int tmnh)
{
	for (int i = 1; i < tmnh; i++) {
		int temp = vtr[i], j = i;
		while (j > 0 && vtr[j-1] > temp) {
			vtr[j] = vtr[j - 1];
			j = j - 1;
		}
		vtr[j] = temp;
	}
}

// =-=-=-= Selection Sort  =-=-=-= //


void troca(int vtr[], int antigo, int novo)
{
	int aux;
	aux = vtr[antigo];
	vtr[antigo] = vtr[novo];
	vtr[novo] = aux;

}

void selection(int vtr[], int tmnh)
{
	int indxMnr, aux;
	for (int i = 0; i < tmnh -1; i++) {
		indxMnr = i;
		for (int j = i+1;j < tmnh; j++) {
			if (vtr[j] < vtr[indxMnr]) {
				indxMnr = j;
				troca(vtr,i,j);
			}
		}
	}
}






// =-=-=-= Bubble Sort  =-=-=-= //

void bubble(int vtr[],int tmnh){
	int aux = 0;
	for (int i = 0; i < tmnh; i++) {
		for (int j = 0; j < (tmnh - i - 1); j++) {

			if (vtr[j] > vtr[j+1]) {
				aux = vtr[j];
				vtr[j] = vtr[j+1];
				vtr[j+1] = aux;

			}
		}
	}
}

// =-=-=-= Heap Sort  =-=-=-= //

void fazerHeap(int vtr[], int tmnh, int iAtual) {
	int esq, drta, pai, aux ;
	pai = iAtual;
	esq = (2*iAtual) ;
	drta = (2*iAtual) + 1;
	if(esq < tmnh && vtr[esq] > vtr[pai]) {
		pai = esq;

	} 
	if(drta < tmnh && vtr[drta] > vtr[pai]){
		pai = drta;
	}
	if(pai != iAtual){
		aux = vtr[iAtual];
		vtr[iAtual] = vtr[pai];
		vtr[pai] = aux;
		fazerHeap(vtr,tmnh,pai);
	}
}    

void heapSort(int vtr[], int tmnh) {
	int aux, tmnhAux;
	int i = (tmnh/2) - 1;
	tmnhAux = tmnh -1;
	
	for(i; i >= 0; i--){
		fazerHeap(vtr,tmnh,i);
	}
	for(tmnhAux; tmnhAux >= 0; tmnhAux--){
		aux = vtr[tmnhAux];
		vtr[tmnhAux] = vtr[0];
		vtr[0] = aux;
		fazerHeap(vtr,tmnhAux,0);

	}
}

// =-=-=-= Merge Sort =-=-=-= //

void merge(int vtr[],int esq, int met, int dir){
	int tmnhEsq, tmnhDrta, aux;
	int idxAuxEsq, idxAuxDrta;
	tmnhEsq = met - esq + 1;
	tmnhDrta = dir - met;
	idxAuxEsq = 0;
	idxAuxDrta = 0;
	aux = esq;
	int vtrEsq[tmnhEsq];
	int vtrDrta[tmnhDrta];

	for(int i = 0; i < tmnhEsq; i++){
		vtrEsq[i] = vtr[i+esq];
	}
	for(int j = 0; j < tmnhDrta; j++){
		vtrDrta[j] = vtr[met+1+j];

	}


	while((idxAuxEsq < tmnhEsq ) && (idxAuxDrta < tmnhDrta)){

		if(vtrEsq[idxAuxEsq] <= vtrDrta[idxAuxDrta]){
			vtr[aux] = vtrEsq[idxAuxEsq];
			idxAuxEsq++;
		} else {
			vtr[aux] = vtrDrta[idxAuxDrta];
			idxAuxDrta++;
		}
		aux++;
	}
	while(idxAuxEsq < tmnhEsq){
	  vtr[aux] = vtrEsq[idxAuxEsq];
	  idxAuxEsq++;
	  aux++;
	}

	while(idxAuxDrta < tmnhDrta){
	  vtr[aux] = vtrDrta[idxAuxDrta];
	  idxAuxDrta++;
	  aux++;
	}
  }


void mergeRecursiva(int vtr[], int idxEsq, int idxDrta ){
	if(idxEsq < idxDrta){
		int idxMetade;
		idxMetade = idxEsq + (idxDrta - idxEsq)/2;

		mergeRecursiva(vtr,idxEsq,idxMetade);
		mergeRecursiva(vtr,idxMetade+1,idxDrta);
		merge(vtr,idxEsq,idxMetade,idxDrta);
	}
}


void mergeSort(int vtr[], int tmnh){
	
	mergeRecursiva(vtr, 0, tmnh - 1);

}

// =-=-=-= Quick Sort =-=-=-= //

// troca = mesmo do selection

int particiona(int vtr[], int esq, int drta) {	
	int i = esq, j = drta ;
	int pivo;
	pivo = vtr[esq];

	while(i < j){
		while(vtr[i] <= pivo){
			i++;
		}
		while(vtr[j] > pivo){
			j--;
		}
		if(i < j){
			troca(vtr,i,j);
		}
	}
	troca(vtr,esq,j);
	return j;

}

void quickRecursiva(int vtr[], int esq, int drta) {
	int r =  0;
	if(drta >= esq) {
		r = particiona(vtr, esq, drta);
		quickRecursiva(vtr, esq, r-1);
		quickRecursiva(vtr, r+1, drta);
	}
}
void quickSort(int vtr[], int tmnh){
	
	quickRecursiva(vtr, 0, tmnh - 1);

}

// =-=-=-= Print Array =-=-=-= //

void imprimir(int vtr[], int tmnh) {

	for(int i = 0; i < tmnh ; i++){
			printf("%d ",vtr[i]);
	}

}   

// =-=-= Selecionar Arquivo =-=-= //

void selecionar_arquivo(int array[], int *tamanho) {
	
	printf("\n");
	printf("Selecione o arquivo que você deseja executar: \n");
	printf("1) 1000                                       \n");
	printf("2) 5000                                       \n");
	printf("3) 10000                                      \n");
	printf("4) 20000                                      \n");
	printf("5) 50000                                      \n");
	printf("6) 75000                                      \n");
	printf("7) 100000                                     \n");

	int arq;
	scanf("%d", &arq);
	FILE *arquivo;

	if (arq == 1) {

		arquivo = fopen("1000.txt", "r");
		*tamanho = 1000;

	} else if (arq == 2) {
		
		arquivo = fopen("5000.txt", "r");
		*tamanho = 5000;

	} else if (arq == 3) {

		arquivo = fopen("10000.txt", "r");
		*tamanho = 10000;
			
	} else if (arq == 4) {

		arquivo = fopen("20000.txt", "r");
		*tamanho = 20000;

	} else if (arq == 5){
	
		arquivo = fopen("50000.txt", "r");
		*tamanho = 50000;

	} else if (arq == 6) {
		
		arquivo = fopen("75000.txt", "r");
		*tamanho = 75000;

	} else if (arq == 7) {
		
		arquivo = fopen("100000.txt", "r");
		*tamanho = 100000;
	
	} else {
		
		printf("Valor inválido!");
	
	}

	int cont = 0;
	while (!feof(arquivo)) {

		fscanf(arquivo,"%d",&array[cont]);
		cont++;

	}

}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-= //

int main(void)
{

	printf("Selecione o algoritmo que você quer executar:  \n");
	printf("1) Insertion Sort                              \n");
	printf("2) Selection Sort                              \n");
	printf("3) Bubble Sort                                 \n");
	printf("4) Heap Sort                                   \n");
	printf("5) Merge Sort                                   \n");
	printf("6) Quick Sort                                   \n");
	
	int alg;
	scanf("%d", &alg);

	if (alg == 1) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		insertion(vetor, tamanho);
		imprimir(vetor, tamanho);
		
		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
		
		printf("\n\nTempo de execução: %g ms \n", Tempo);

	} else if (alg == 2) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		selection(vetor,tamanho);
		imprimir(vetor,tamanho);
		
		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

		printf("\n\nTempo de execução: %g ms \n", Tempo);

	} else if (alg == 3) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		bubble(vetor,tamanho);
		imprimir(vetor,tamanho);
		
		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

		printf("\n\nTempo de execução: %g ms \n", Tempo);

	} else if (alg == 4) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		heapSort(vetor, tamanho);
		imprimir(vetor, tamanho);
		
		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
		
		printf("\n\nTempo de execução: %g ms \n", Tempo);

	} else if (alg == 5) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		mergeSort(vetor, tamanho);
		imprimir(vetor, tamanho);
		
		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
		
		printf("\n\nTempo de execução: %g ms \n", Tempo);    
	} else if (alg == 6) {

		clock_t inicio, fim;
		inicio = clock();

		int tamanho = 0;
		int vetor[100000];
		selecionar_arquivo(vetor, &tamanho);
		quickSort(vetor, tamanho);
		imprimir(vetor, tamanho);

		fim = clock();
		double Tempo = (fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
		
		printf("\n\nTempo de execução: %g ms \n", Tempo);    
	} else {
		
		printf("Valor inválido!");

	}
	

}
