#include <stdio.h>
#include <stdlib.h>


struct no{
		
	int info; //informação
	struct no* esq; //subarvore esquerda
	struct no* dir; //subarvore direita


}; typedef struct no* arvore;  //arvore é um ponteiro pra um no



//teste se é vazia
int vazia(arvore r){

	return (r==NULL);
}


arvore insere_arvore(arvore r, int info){

	if(vazia(r)){
		
		r=(struct no*)malloc(sizeof(struct no));
		r->info=info;
		r->esq=NULL;
		r->dir=NULL;
	}

	else if(info < r->info)
			r->esq=insere_arvore(r->esq, info);
		else// info>=r->info
			r->dir=insere_arvore(r->dir, info);

		return r;
}

void in_order(arvore r){

	if(!vazia(r)){

		in_order(r->esq);
		printf("%d\n",r->info);
		in_order(r->dir);
	}
}

void pre_order(arvore r){

	if(!vazia(r)){

		printf("%d\n",r->info);
		pre_order(r->esq);
		pre_order(r->dir);

	}

}

void pos_order(arvore r){

	if(!vazia(r)){

		pos_order(r->esq);
		pos_order(r->dir);
		printf("%d\n", r->info);

	}


}

int alturaAux(arvore r, int j, int k){

	arvore aux=r, aux2=r;

	while(aux!=NULL){
		j++;
		aux=aux->esq;
	}
	while(aux2!=NULL){
		k++;
		aux2=aux2->dir;
	}
	int res;
	free(aux2); free(aux);
	return res=(j>k)?j:k;


}

int altura(arvore r){

	if(vazia(r))
		return 0;
	if(r->dir==NULL && r->esq==NULL)
		return 1;

	int alt=alturaAux(r, 0,0);

	return alt;
}

int main(){


	arvore r=NULL;

	r=insere_arvore(r, 10);
	r=insere_arvore(r, 5);
	r=insere_arvore(r, 2);
	r=insere_arvore(r, 6);
	r=insere_arvore(r, 8);
	r=insere_arvore(r, 1);
	r=insere_arvore(r, 9);

	printf("in-order:\n");
	in_order(r);
	printf("pre-order\n");
	pre_order(r);
	printf("pos-order\n");
	pos_order(r);
	int x=altura(r);
	printf("altura %d\n",x);


	return 0; 
}