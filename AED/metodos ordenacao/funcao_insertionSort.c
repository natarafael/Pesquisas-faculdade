insertionSort(int vet[], int n){

	int i, j, aux;

	for(i=1; i<n; i++){

		aux=vet[i];

		for(j=i-1; j>=0 && vet[j]>aux; j--)
			vet[j+1]=vet[j];

		vet[j+1]=aux;
	}

}