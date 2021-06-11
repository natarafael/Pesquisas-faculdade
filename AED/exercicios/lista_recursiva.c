#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

	int info;
	struct no *prox;

} Lista;

Lista* crialista(){

	return (Lista*)malloc(sizeof (Lista));
}

int vazia(Lista* l){

	return(l==NULL);
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

Lista* remover(Lista* l, int info){

	if(!vazia(l)){

		if(l->info==info){

			Lista* aux =l;
			l=l->prox;
			free(aux);

		}

		else{

			l->prox=remover(l->prox, info);
		}

	} 
	return l;
}

Lista* insere_(Lista* l, int info){


	Lista* aux=(Lista*)malloc(sizeof(Lista));
	aux->info=info;
	aux->prox=l;
	return aux;
}

Lista *insere_cabeca(Lista *l,int item){
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if(vazia(l)){
        nova->info = item;
        nova->prox = NULL;
        l = nova;
        return l;
    }
    nova->info = item;
    nova->prox = l;
    return nova;
}

Lista* inverte(Lista* l){

	Lista* inv=crialista();
	inv=NULL;

	if(!vazia(l)){

		inv=insere_cabeca(inv, l->info);

		inv->prox=inverte(l->prox);

	}

	return inv;
	
}



void imprime(Lista* l){

	if(!vazia(l)){

		printf("%d\n",l->info);

		imprime(l->prox);

	} else printf("\n");
}


Lista* concatena(Lista* l,Lista* l2){

	Lista* l3=(Lista*)malloc(sizeof (Lista));
	l3=NULL;

	if(!vazia(l)){

		l3=insere(l3, l->info);

		l3->prox=concatena(l->prox, l2);
	}

	else l3=l2;

	return l3;
}


Lista* merge(Lista* l, Lista* l2){

	Lista* l3=(Lista*)malloc(sizeof(Lista));
	l3=NULL;

	if(!vazia(l) && !vazia(l2)){

		l3=insere_(l3, l->info);
		l3=insere_(l3, l2->info);
	}




	return l3;
}

int main(){
	
	Lista* l=crialista(); 
	Lista* l2;
	Lista* l3; 

	l=NULL,l2=NULL;

	if(vazia(l)) printf("listita vaziazita :(\n");

	l=insere(l, 5);
	l=insere(l, 6);
	l=insere(l, 7);

	printf("lista 1\n");
	imprime(l);

	//l=remover(l, 6); 
	//imprime(l);

	l=inverte(l);
	printf("invertida\n");
	imprime(l);

	l2=insere(l2,20);
	l2=insere(l2,21);
	l2=insere(l2,22);

	printf("lista 2\n");
	imprime(l2);

	l3=concatena(l, l2);

	printf("concatenada\n");
	imprime(l3);


	//l3=merge(l, l2);

	//printf("mergida\n");
	//imprime(l3);

	free(l);
	free(l2);
	free(l3);
	return 0;
}