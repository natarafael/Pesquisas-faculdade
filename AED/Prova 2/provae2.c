
int somamenores(arvore r, int k){

	if(vazia(r))
		return 0;

	if(r->info<k)
		return r->info+somamenores(r->esq, k)+somamenores(r->dir, k);
	else
		return somamenores(r->esq, k);
}