#include <stdio.h>
#include <stdlib.h>

typedef struct no{

	int info;
	struct no* prox;	

}Lista;

Lista* crialista(){

	return (Lista*)malloc(sizeof (Lista));
}
int vazia(Lista* l){

	return (l==NULL);
}

Lista* insere(Lista* l, int info){

	

	if(vazia(l)){
		
		Lista* nova=crialista();
		nova->info=info;
		nova->prox=NULL;
		l=nova;
		return l;
	}

	l->prox=insere(l->prox, info);
	return l; 
}

void imprime(Lista* l){

	if(!vazia(l)){

		printf("%d\n",l->info);

		imprime(l->prox);

	} else printf("\n");
}



void insertionSort(int vet[], int n){

	int x,i,j;

		for(i=1; i<n; i++){

			x=vet[i];

				for(j=i-1; j>=0 && vet[j]>x; j--)
					vet[j+1]=vet[j];

				vet[j+1]=x;
		}
}


void insertionSort_lista(Lista* l){


	Lista *atual=l;
	Lista* anterior=l;
	int x;

	while(atual!=NULL){

		anterior=atual;
		atual=atual->prox;
		x=atual->info;

				



	}


}


int main(){

	Lista* l=crialista();
	l=NULL;

		l=insere(l, 5);
		l=insere(l, 8);
		l=insere(l, 10);
		l=insere(l, 1);
		l=insere(l, 4);

		printf("lista:\n");
		imprime(l);
		

	return 0;
}