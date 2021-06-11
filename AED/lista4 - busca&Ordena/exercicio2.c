#include <stdio.h>

int pote(int k, int n){

	if(n==0)
		return 1;
	else 
		return k* pote(k, n-1);
}


int main(){

	int k, n, res;

	printf("digite os valores de k e n:");
	scanf("%d %d", &k, &n);
	printf("\n");

	res=pote(k, n);

	printf("resultado: %d\n",res);

	return 0;
}