
void selecionSort(int v[], int n){

	int min, aux;


	for(int i=0; i<n-1;i++){

		min=i;

			for(int j=i+1; j<n; j++)
				if(vet[j]<vet[min]) min=j;

			//troca a posicao i com a min
			aux=vet[i]; vet[i]=vet[min]; vet[min]=aux;
	}
}