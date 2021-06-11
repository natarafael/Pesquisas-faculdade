#include <stdio.h>
#include <stdlib.h>


typedef struct no{

	int info;
	struct no* prox;
}No;


typedef struct lista{

	No*cabeca;
	No*cauda;

}Lista;


int vazia(Lista* l){

	return(l->cabeca==NULL);
}

Lista* crialista(){

	Lista* l=(Lista*)malloc(sizeof(Lista));
	l->cabeca=NULL;
	l->cauda=NULL;
	return l;
}

Lista* insere_cauda(Lista* l, int info){

	No* aux=(No*)malloc(sizeof(No));
	aux->info=info;
	aux->prox=NULL;

	if(vazia(l)){

	l->cabeca=aux;
	l->cauda=aux;

	}

	else
		l->cauda->prox=aux;

	return l;
}

Lista* remover(Lista* l, int info){

	No* aux=l->cabeca;
	No* anterior=l->cabeca;

	while(aux!=NULL && aux->info!=info){

		anterior=aux;
		aux=aux->prox;
	}

	if(aux!=NULL){

			if(aux==l->cabeca)
				l->cabeca=l->cabeca->prox;

			else
				anterior->prox=aux->prox;

			free(aux);
	}

	return l;
}

void imprime(Lista* l){

	while(l->cabeca!=NULL){

		printf("%d->", l->cabeca->info);

		l->cabeca=l->cabeca->prox;
	}
	printf("\n");

}

	
int main(){

	Lista* l;

	l=crialista();

	l=insere_cauda(l, 1);

	return 0;
}