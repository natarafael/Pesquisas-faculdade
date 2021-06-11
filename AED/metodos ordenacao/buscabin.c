#include <stdio.h>


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





int main(){

	int vet[10], n, x;

	n=10;

	for (int i = 0; i < n; i++){

		printf("digite o elemento [%d] do vetor: ", i);
		scanf("%d", &vet[i]);
		printf("\n");
	}

	printf("elementos do vetor: ");
	for (int i = 0; i < n; i++){

		printf(" %d ", vet[i]);
	}
	printf("\n");

	printf("digite o numero buscado: ");
	scanf("%d", &x);
	printf("\n");

	int posicao;

	//posicao=busca_binaria(vet, n, x);


	posicao=busca_binaria_rec(vet,n, x);

	printf("posicao: %d\n", posicao);


	return 0;
}