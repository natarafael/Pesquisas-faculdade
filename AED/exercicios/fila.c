#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
	int info;
	struct no* prox;

} No;

typedef struct fila
{
	No* primeiro;
	No* ultimo;

} Fila;

Fila* crialista(){

	Fila* f=(Fila*)malloc(sizeof(Fila));

	f->primeiro=NULL;
	f->ultimo=NULL;
	return f;
}

int vazia(Fila* f){

	return(f->primeiro==NULL);
}

void enqueue(Fila* f, int info){

	No* aux=(No*)malloc(sizeof(No));

	aux->info=info;
	aux->prox=NULL;

	if(vazia(f))
		f->primeiro=aux;
	else
		f->ultimo->prox=aux;

	f->ultimo=aux;
}

void dequeue(Fila* f){

	No* aux=(No*)malloc(sizeof(No));

	aux=f->primeiro;

	if(f->primeiro==f->ultimo)
		f->ultimo=NULL;

	f->primeiro=f->primeiro->prox;
	free(aux);
}

void imprime(Fila* f){

	while(f->primeiro!=NULL){

		printf("%d\n", f->primeiro->info);

		f->primeiro=f->primeiro->prox;

	}
	printf("----\n");
}

int main(){

	Fila* f;
	f=crialista();

	enqueue(f, 1);
	enqueue(f, 2);
	enqueue(f, 3);

	imprime(f);

	dequeue(f);
	imprime(f);

	free(f);
	return 0;
}