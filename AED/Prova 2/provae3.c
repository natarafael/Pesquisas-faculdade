
void imprime_por_nivel(arvore r){

	int h=altura(r);
	int i;

		for(i=0; i<h; i++){

			imprime_nivel(r, i);
			printf("\n");
		}
}

void imprime_nivel(arvore r, int i){

	if(vazia(r))
		return;

	if(i==1)
		printf(" %d ",r->info);
	else
		if(i>1){
			imprime_nivel(r->esq, i-1);
			imprime_nivel(r->dir, i-i);
		}
}

int altura(arvore r){

	if(vazia(r))
		return 0;

	int altEsq=(r->esq);
	int altDir=(r->dir);

	return ((altEsq+altDir)+1);
}