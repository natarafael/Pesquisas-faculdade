#include <stdio.h>
#include <stdlib.h>

struct no{

	int info;
	struct no* esq;
	struct no* dir;

};	typedef struct no* arvore;


int vazia(arvore r){
	return(r==NULL);
}


//a) inserir
arvore insere(arvore r, int x){


	if(vazia(r)){

		r=(struct no*)malloc(sizeof(struct no));
		r->info=x;
		r->esq=NULL;
		r->dir=NULL;
	}

	else
		if(x < r->info)
			r->esq=insere(r->esq, x);
		else
			r->dir=insere(r->dir, x);
}

void in_ordem(arvore r){

	if(!vazia(r)){

		in_ordem(r->esq);
		printf(" %d ",r->info);
		in_ordem(r->dir);

	}

}

void pre_ordem(arvore r){

	if(!vazia(r)){

		printf(" %d  ",r->info);
		in_ordem(r->esq);
		in_ordem(r->dir);

	}

}

void pos_ordem(arvore r){

	if(!vazia(r)){

		in_ordem(r->esq);
		in_ordem(r->dir);
		printf(" %d ",r->info);
	}

}


//f) maximo: retorna o valor da maior chave
//pre condicao nao pode ser vazia, assim nao precisa testar se é ou não
int maximo(arvore r){

	while(r->dir!=NULL) //enquanto o lado direito nao for vazio continua andando pela arvore, ja que o lado direito é sempre maior e maior
			r=r->dir;

		return r->info; 
}

int maximo_rec(arvore r){

	if(!vazia(r->dir)) return maximo_rec(r->dir);

	return r->info;
}



//g)retorna a menor chave da arvore, contrario da maior ne
//pre condição nao vazia
int minimo(arvore r){

	while(r->esq!=NULL)
	r=r->esq;

	return r->info;

}


int minimo_rec(arvore r){

	if(!vazia(r->esq)) return minimo_rec(r->esq);

	return r->info;

}


//h) altura da arvore, a altura é o tamanho da folha mais distante ate a primeira raiz
int altura(arvore r){

	if(vazia(r)) return 0;

	int altesq=altura(r->esq);
	int altdir=altura(r->dir);

	if(altesq>altdir) return (altesq+1);
	else return (altdir+1);
}




//i) soma de todas as chaves
int soma(arvore r){

	if(vazia(r))
		return 0;

	int result=r->info;
	
		result+=soma(r->esq);
		result+=soma(r->dir);

	return result;
}

int soma2(arvore r){

	if(vazia(r))
		return 0;

	int result=r->info;
	result+=soma2(r->esq)+soma2(r->dir);
	return result;

}

//auxiliar que imprime as info
void imprime_nivel(arvore r, int i){

	if(vazia(r)) return;

	if(i==1)
		printf(" %d ",r->info);

	else if(i>1){

	imprime_nivel(r->esq, i-1);
	imprime_nivel(r->dir, i-1);
	}
}

//auxiliar para saber ate onde imprimir
int altura_nivel(arvore r){

	if(vazia(r)) return 0;

	int altesq=altura_nivel(r->esq);
	int altdir=altura_nivel(r->dir);

	return ((altdir+altesq)+1);


}

//5) imprima por nivel
void imprime_por_nivel(arvore r){

	int h=altura_nivel(r);
	int i;

		for (i = 0; i < h; i++)
		{
			imprime_nivel(r, i);
			printf("\n");
		}


}


//verifica se uma arvore eh estritamente binaria, ou seja, tem 0 ou 2 folhas
int extremaBin(arvore r){


	if(vazia(r))
		return 0;

	int verEsq=0; int verDir=0;

	verEsq=extremaBin(r->esq);
	verDir=extremaBin(r->dir);

	if((r->esq && r->dir) || (r->esq==NULL && r->dir==NULL))
		return 1;

	return 0;

}


int somamenores(arvore r, int k){

	if(vazia(r))
		return 0;

	if(r->info<k)
		return r->info+somamenores(r->esq, k)+somamenores(r->dir, k);
	else
		return somamenores(r->esq, k);


}


int main(){


	arvore r=NULL;

	r=insere(r, 11);
	r=insere(r, 5);
	r=insere(r, 2);
	r=insere(r, 8);
	r=insere(r, 14);
	r=insere(r, 22);
	r=insere(r, 15);
	//r=insere(r, 25);

	//remover eh um trampo do caralho depois faço

	printf("in ordem\n");
	in_ordem(r);

	printf("\npre ordem\n");
	pre_ordem(r);

	printf("\n pos ordem\n");
	pos_ordem(r);

	int max= maximo_rec(r);
	printf("\nmaior valor da arvore: %d\n",max);


	int min=minimo(r);
	printf("menor valor da arvore %d\n",min);



	int alt=altura(r);
	printf("altura da arvore: %d\n", alt);


	int somas=soma(r);
	printf("soma de todas as chaves: %d\n",somas);

	somas=soma2(r);
	printf("soma2 de todas as chaves: %d\n",somas);


	printf("imprime por nivel: \n");
	imprime_por_nivel(r);


	if(extremaBin(r)) 
		printf("a avore eh estritamente binaria\n");
	else
		printf("a arvore nao eh estritamente binaria\n");



	int sm=somamenores(r, 13);
	printf(" soma dos valores menores q k: %d\n",sm);

	return 0; 
}