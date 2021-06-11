//lista 2

#include <stdio.h>
#include <stdlib.h>


typedef struct no{

	int info;
	struct no *prox;

} Lista;


Lista* crialista(){

	return (Lista*)malloc(sizeof(Lista));
}

int vazia(Lista *l){

	return(l==NULL);
}

Lista* insere(Lista *l, int info){

	Lista* aux = (Lista*)malloc(sizeof (Lista));

	aux->info=info;
	aux->prox = l;

	return aux;
	}


Lista* insere1(Lista* l,int info){


	if(vazia(l)){

		l=(Lista*)malloc(sizeof(Lista));

		l->info=info;
		l->prox=NULL;

		return l;
	}
	else{
		Lista* nova=(Lista*)malloc(sizeof(Lista));
		Lista* aux = l;

		while(aux!=NULL){

			aux=aux->prox;
		}

		nova->info=info;
		nova->prox=NULL;
		aux->prox=nova;

		return l;
	}

}



Lista *remover (Lista* l, int info){

	Lista* anterior = l;
	Lista* atual = l;

	while( atual != NULL && atual->info != info){

		anterior=atual;

		atual=atual->prox;
	}

	if(atual!=NULL){

		if(atual==l)
			l=l->prox;
		else
			anterior->prox = atual->prox;

		free(atual);
	}
	else printf("elemento nao encontrado\n");

	return l;
}

void imprime(Lista* l){

	while(l!=NULL){

	printf("%d\n", l->info);

	l=l->prox;

	}
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

Lista *inverte(Lista *l){
    if(vazia(l)){
        printf("ata\n");
    }else{
        Lista *aux = NULL;
        Lista *aux2 = (Lista*)malloc(sizeof(Lista));

        aux2 = l;

        for(; aux2!=NULL ; aux2 = aux2->prox){
            aux = insere_cabeca(aux,aux2->info);
        }
        return aux;
    }
}


Lista* concatena(Lista* l, Lista* l2){

	Lista* l3=crialista();
	l3=NULL;

	while(l!=NULL){

		l3=insere1(l3, l->info);

		l=l->prox;
	}

	while(l2!=NULL){

		l3=insere1(l3, l2->info);

		l2=l2->prox;
	}

	return l3;
}

Lista* merge(Lista* l, Lista* l2){

	Lista* l3=crialista();
	l3=NULL;

	while(l!=NULL && l2!=NULL){

		l3=insere1(l3, l->info);
		l3=insere1(l3, l2->info);

		l=l->prox;
		l2=l2->prox;
	}

		if(l!=NULL){

			while(l!=NULL){

			l3=insere1(l3, l->info);

			l=l->prox;
			}	

		}
		else if(l2!=NULL){
			l3=insere1(l3, l2->info);

			l2=l2->prox;
		}
	
	return l3;
}


int main(){

	Lista *l;

	l=crialista();
	l=NULL;

	if(vazia(l))
		printf("Lista vazia\n");

	
	l=insere1(l, 13);
	l=insere1(l,21);
	l=insere1(l, 10);
	l=insere1(l, 11);

	imprime(l);

	printf("------------------\n");
	printf("removendo item\n");

	l=remover(l, 10);

	imprime(l);

	printf("------------------\n");
	printf("invertendo lista\n");

	l=inverte(l);

	imprime(l);

	printf("------------------\n");

	Lista* l2 = crialista();
	Lista* l3;
	l2=NULL;

	l2=insere1(l2, 101);
	l2=insere1(l2, 102);
	l2=insere1(l2, 103);
	l2=insere1(l2, 104);

	printf("lista 2:\n");
	imprime(l2);
	printf("------------------\n");

	printf("listas concatenadas:\n");

	l3=concatena(l, l2);

	imprime(l3);
	printf("------------------\n");	

	printf("listas intercaladas\n");

	l3=merge(l,l2);

	imprime(l3);
	printf("------------------\n");	

	free(l);
	free(l2);
	free(l3);
	return 0;
}