int busca_bin_rec(int vet[], int n, int x){

	busca_bin_aux(vet, -1, n, x);

}

int busca_bin_aux(int vet[], int e, int d, int x){

	if(e==d-1)
		return d;
	else {

		int m=(e+d)/2;

		if(vet[m]<x)
			return busca_bin_aux(vet, m, d, x);
		else
			return busca_bin_aux(vet, e, m, x);
	}

}