#include <stdio.h>


void selectionSort(int vet[], int n){

	int min, aux;

		for(int i=0; i<n-1; i++){

			min=i;

				for(int j=i+1; j<n; j++)
					if(vet[j]<vet[min]) min=j;

				aux=vet[i]; vet[i]=vet[min]; vet[min]=aux;
		}
}


void selectionSort_rec(int vet[], int i, int n){

	int min, aux;

		min=i;

			for(int j=i+1; j<n; j++)
				if(vet[j]<vet[min]) min=j;

		aux=vet[i]; vet[i]=vet[min]; vet[min]=aux;

		if(i+1<n)
			selectionSort_rec(vet, i+1, n);

}


void insertSort(int vet[], int n){

	int x,i, j;

		for(i=1; i<n; i++){

			x=vet[i];

				for(j=i-1; j>=0 && vet[j]>x; j--)
					vet[j+1]=vet[j];

				vet[j+1]=x;
		}
}


void insertSort_rec(int vet[], int i, int n){


	int x, j;

		x=vet[i];

			for(j=i-1; j>=0 && vet[j]>x; j--)
				vet[j+1]=vet[j];

			vet[j+1]=x;

			if(i<n)
				selectionSort_rec(vet, i+1, n);
}

int main(){


	int vet[5]={3, 2, 6, 9, 1};


	//selectionSort(vet, 5);

	selectionSort_rec(vet, 0, 5);

	//insertSort(vet, 5);

	//insertSort_rec(vet, 1, 5);



	for (int i = 0; i < 5; i++)
	{
		printf(" %d ", vet[i]);
	}
	printf("\n");

	return 0;
}