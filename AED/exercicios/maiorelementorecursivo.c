#include<stdio.h>



 exemplo para retornar maior elemento recursivamente

int maiorElem( int v[], int n){

	if (n==1)
		return v[0];

	else{

		int x= maiorElem(v,n-1);

		if(x> v[n-1])
			return x;

	}
	else return v[n-1];


}