void mergeSort(int v[], int e, int d){

	if(e<d-1){

		int m=(e+d)/2;

		mergeSort(vet, e, m);
		mergeSort(vet, m, d);
		intercala(vet, e, m, d);
	}
}


void intercala(int vet[], int e, int m, int d){

	int i, j, k, *vet_aux;

	vet_aux=malloc((d-e)*sizeof(int));

	i=e, j=m, k=0;

	while(i<m && j<d){

		if(vet[i] < vet[j]) vet_aux[k++]=vet[i++];
		else vet_aux[k++]=vet[j++];

	}

	while(i<m) vet_aux[k++]=vet[i++];
	while(j<d) vet_aux[k++]=vet[j++];


	for(i=e; i<d; i++) vet[i]=vet_aux[i-e];

		free(vet_aux);



}