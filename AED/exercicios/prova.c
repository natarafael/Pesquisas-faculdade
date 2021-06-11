#include <stdio.h>
#include <stdlib.h>


typedef struct No 
{
	int info;
	struct No* prox;

}Lista;


int vazia(Lista* l){

	return(l==NULL);
}	


Lista* insere_rec(Lista* l, int info){

	if(vazia(l)){

		Lista* nova=(Lista*)malloc(sizeof (Lista));

		nova->info=info;
		nova->prox=NULL;
		l=nova;
		return l;
	}

	l->prox=insere_rec(l->prox, info);
	return l;
}

Lista* remover_it(Lista* l, int info){

	Lista* anterior=l;
	Lista* atual=l;

	while(atual!=NULL && l->info!=info){
		
		anterior=atual;

		atual=atual->prox;
	}

	if(atual!=NULL){
		
		if(atual==l)
			l=l->prox;
			
		else
			anterior->prox=atual->prox;

		free(atual);	
	}
	else
		printf("elemento nao encontrado\n");

	return l;
}	

Lista* remover_rec(Lista* l, int info){

	if(!vazia(l)){

		if(l->info==info){
			Lista* removido=l;
			l=l->prox;
			free(removido);
		}
		else
			l->prox=remover_rec(l->prox, info);
	}
	return l;
}

void imprimir(Lista *l){

	if(!vazia(l)){
		printf("%d\n", l->info);
		imprimir(l->prox);
	}
	else printf("----\n");
}

Lista* concatena(Lista* l, Lista* l2){

	Lista* l3=NULL;

	if(!vazia(l)){

		l3=insere_rec(l3, l->info);
		l3->prox=concatena(l->prox, l2);
	}

	else if(!vazia(l2)){

		l3=insere_rec(l3, l2->info);
		l3->prox=concatena(l, l2->prox);
	}

	return l3;
}

Lista* merge_it(Lista* l, Lista* l2){

	Lista* l3=NULL;

	while(l!=NULL && l2!=NULL){

		l3=insere_rec(l3, l->info);
		l3=insere_rec(l3, l2->info);

		l=l->prox;
		l2=l2->prox;
	}
	if(l!=NULL){

		while(l!=NULL){
			l3=insere_rec(l3, l->info);
			l=l->prox;
		}
	}
	else if(l2!=NULL){

		while(l2!=NULL){
			l3=insere_rec(l3, l2->info);
			l2=l2->prox;
		}

	}
	return l3;

}

Lista* merge_rec(Lista *l, Lista* l2){

	Lista* l3=NULL;

	if(!vazia(l) && !vazia(l2)){

		l3=insere_rec(l3, l->info);
		l3->prox=merge_rec(l2, l->prox);
	}
	else if(!vazia(l)){

		l3=insere_rec(l3, l->info);
		l3->prox=merge_rec(l->prox, l2);
	}
	else if(!vazia(l2)){

		l3=insere_rec(l3, l2->info);
		l3->prox=merge_rec(l, l2->prox);
	}

		return l3;
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

	Lista* invertida=NULL;

	Lista* aux=l;

	while(aux!=NULL){

		invertida=insere_cabeca(invertida, aux->info);
		aux=aux->prox;
	}

	return invertida;
}

Lista* remove_enesimo_rec(Lista* l, int n){

	int i=0;

	if(!vazia(l)){

		if(i==n){

			Lista* aux=l;
			l=l->prox;
			free(aux);
		}
		else{
			l->prox=remove_enesimo_rec(l->prox, n-1);
		}
		
	}
	return l;
}

Lista* remove_enesimo_it(Lista*l, int n){

	int i=0;
	Lista* aux=l;
	Lista* anterior=l;

	while(aux!=NULL && i!=n){
		anterior=aux;
		aux=aux->prox;
		i++;
	}

	if(aux!=NULL){

		if(aux==l)
			l=l->prox;
		else
			anterior->prox=aux->prox;
		free(aux);
	}
	else printf("elemento nao encontrado\n");

	return l;
}


int conta_ocorrencias_it(Lista* l, int info){

	int contador=0;

	while(l!=NULL){

		if(l->info==info)
			contador++;

		l=l->prox;
	}

	return contador;
}


int main(){

	Lista* l=NULL;
	Lista* l2=NULL;
	Lista* l3=NULL;

	l=insere_rec(l, 1);
	l=insere_rec(l, 2);
	l=insere_rec(l, 3);
	l=insere_rec(l, 4);

	imprimir(l);

	//l=remover_rec(l, 3);
	//imprimir(l);


	//l3=inverte(l);
	//imprimir(l3);

	l2=insere_rec(l2, 10);
	l2=insere_rec(l2, 11);
	l2=insere_rec(l2, 12);
	l2=insere_rec(l2, 13);

	//imprimir(l2);

	//l3=concatena(l, l2);
	//imprimir(l3);

	//l3=merge_rec(l, l2);
	//imprimir(l3); 

	//l=remove_enesimo_it(l, 1);
	//imprimir(l);

	//int ocorrencias=0;
	//ocorrencias=conta_ocorrencias_it(l, 2);
	//printf("ocorrencias do 2: %d\n",ocorrencias);

	free(l);
	free(l2);
	free(l3);

	return 0;
}