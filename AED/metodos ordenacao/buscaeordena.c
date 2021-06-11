#include <stdio.h>
#include <stdlib.h>
#define MAX 5


//versão iterativa
//retorna a posição do elemento no vetor
int busca_binaria(int vet[], int n, int x){

	int e, m, d;
	e=-1; d=n;

	while(e<d-1){

		m=(e+d)/2;

			if(vet[m]<x)
				e=m;
			else
				d=m;
	}

	return d;
}



int busca_binaria_aux(int vet[], int e, int d, int x){

	if(e==d-1){

		return d;
	}
	else {


		int m=(e+d)/2;

			if(vet[m]<x)
				return busca_binaria_aux(vet, m, d, x);
			else 
				return busca_binaria_aux(vet, e, m, x);
	}
}

//versao recursiva 
//retorna a posição do elemento no vetor

int busca_binaria_rec(int vet[], int n, int x){

	return busca_binaria_aux(vet, -1, n, x);
}


void selectionsort(int vet[], int n){

	int min, aux;

	for (int i = 0; i < n-1; i++)
	{
		
		min=i;

		for(int j=i+1; j<n; j++)
			if(vet[j]<vet[min]) min=j;

		//realiza a troca de i por min
		aux=vet[i]; vet[i]=vet[min]; vet[min]=aux;
	}
}


void insertionSort(int vet[], int n){

	int aux, j, i;

	for(i=1; i<n; i++){

		aux=vet[i];

			for(j=i-1; j>=0 && vet[j]>aux; j--)
				vet[j+1] = vet[j];

			//coloca aux na posição correta
			vet[j+1]=aux;
	}

}


void intercala(int vet[], int e, int m, int d){

	int i, j, k, *vet_aux;

	vet_aux=malloc((d-e)*sizeof(int));

	i=e; j=m; k=0;

		while(i<m && j<d){

			if(vet[i] <= vet[j]) vet_aux[k++]=vet[i++];
			else vet_aux[k++]=vet[j++];
		}

	while(i<m) vet_aux[k++]= vet[i++];
	while(j<d) vet_aux[k++] =vet[j++];

	for(i=e; i<d; i++) vet[i]=vet_aux[i-e];

	free(vet_aux); 
}


void mergeSort(int vet[], int e, int d){

	if(e<d-1){

		int m=(e+d)/2;

		mergeSort(vet, e, m);
		mergeSort(vet, m, d);
		intercala(vet, e, m, d);
	}
}



int separa(int vet[], int e, int d){

	int pivo, j, k, temp;

	pivo = vet[d]; j=e;

		for(k=e; k<d; k++)
			if(vet[k]<=pivo){

				temp=vet[j]; vet[j]=vet[k]; vet[k]=temp;
				j++;
			}

		vet[d]=vet[j]; vet[j]=pivo;

		return j;
}


void quicksort(int vet[], int e, int d){

	int j;
	
	if(e<d){

		j=separa(vet,e, d);
		quicksort(vet, e, j-1);
		quicksort(vet, j+1, d);
	}

}


void printavet(int vet[], int n){


	printf("elementos do vetor: ");
	for (int j = 0; j < n; j++){

		printf(" %d ", vet[j]);
	}
	printf("\n");
}

void printaordenado(int vet[], int n){

	printf("vetor ordenado: ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ",vet[i]);
	}
	printf("\n");
}


void lervet(int vet[], int n){

	for (int i = 0; i < n; i++){

		printf("digite o elemento [%d] do vetor: ", i);
		scanf("%d", &vet[i]);
		printf("\n");
	}
}

int main(){

	int vet[MAX], n=MAX , x;

	lervet(vet, n);

	printavet(vet, n);

	//selectionsort(vet, n);

	//insertionSort(vet, n);

	//mergeSort(vet, 0, n);

	quicksort(vet, 0, n-1);

	printaordenado(vet, n);


	printf("digite o numero buscado: ");
	scanf("%d", &x);
	printf("\n");

	int posicao;

	//posicao=busca_binaria(vet, n, x);
	posicao=busca_binaria_rec(vet,n, x);

	printf("posicao: %d\n", posicao);


	return 0;
}