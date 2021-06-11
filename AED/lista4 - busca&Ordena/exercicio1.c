#include <stdio.h>


int busca_rec_aux(int vet[], int e, int d, int x){

	if(e==d-1){
		if(vet[d]==x)
		return d;
		else return -1;
	}
	else{

		int m=(e+d)/2;

		if(vet[m]<x)
			return busca_rec_aux(vet, m, d, x);
		else
			return busca_rec_aux(vet, e, m, x);
	}

}


int busca_rec(int vet[], int n, int x){

	return busca_rec_aux(vet, -1, n, x);
}


int main(){

	int indice, vet[5]={1,2,3,4,5};
	int x;

		printf("digite o numero buscado: ");
		scanf("%d", &x);
		printf("\n");

	indice=busca_rec(vet, 5, x);


	printf("posicao do numero: %d\n", indice);

	return 0;
}