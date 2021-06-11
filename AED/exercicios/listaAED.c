//lista AED
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

 /*PRIMEIRO EXERCICIO

Projete uma função que receba um numero inteiro n e imprima todos os inteiros entre 0 d n em ordem crescente 


int ordem_cres(int n, int i){

	if(i==n) return 0;

	else{

		printf("%d ", i);
		ordem_cres(n, i+1);
	}

}

 int main(){

	int n,i=1,res=0;
	
	printf("digite o numero:");
	scanf("%d",&n);
	printf("\n");

	res=ordem_cres(n,i);

	printf("\n");

	return 0;
}



  /*SEGUNDO EXERCICIO 

	projete uma função recursiva que receba um numero inteiro n e imprima todos os inteiros entre 0 e n em ordem decrescente 

int ordem_decr(int n){

	if(n==0) return 0;

	else{

		printf("%d ", n);
		ordem_decr(n-1);
	}

}

 int main(){

	int n,i=1,res=0;
	
	printf("digite o numero:");
	scanf("%d",&n);
	printf("\n");

	res=ordem_decr(n-1);

	printf("\n");

	return 0;
} 

	3. Projete uma funcao recursiva que receba um numero inteiro n e calcule o somatorio dos numeros entre
	0 e n. 
 


int somatoria(int n){

	if(n>0){

		return n+somatoria(n-1);

	}	return 0;

}


int main(){

int n, soma=0;

	printf("informe o numero: ");
	scanf("%d",&n);
	printf("\n");

	soma = somatoria(n-1);

	printf("a soma total eh: %d\n",soma);

	return 0;
} 

	4. Projete uma fuņcao recursiva que receba um numero inteiro n e calcule seu superfatorial (sf), onde o
superfatorial de n e o produtos dos n primeiros fatoriais. Assim, por exemplo sf(5) = 1! × 2! × 3! × 4! × 5! = 34.560




int fatorial_rec ( int n){

    if(n>0){
        return n* fatorial_rec (n-1);
    }
    return 1;
}

int syperfatorial(int n){

	if(n>1){

		int fat=0;

		fat=fatorial_rec(n);

		return fat*syperfatorial(n-1);

	} return 1;


}


int main(){

	int n, sf=0;

	printf("digite o numero: ");
	scanf("%d",&n);
	printf("\n");

	sf=syperfatorial(n);

	printf("%d\n", sf);

	return 0;
}

 Projete uma funcao recursiva para calcular o fatorial exponencial de um inteiro n, calculado segundo a formula: fatexp(n) = n(n-1)(n-2)...




int fatexp(int n){

	if(n>0){

		return pow(n, fatexp(n-1));

	} 
	return 0;

}

int palindrome(char str[], int ini, int fin)
{
	if(fin<=ini) return 1;


	else if(str[ini] != str[fin]) 
		return 0;

		return palindrome(str, ini + 1, fin - 1);

} 


 int main(){

 	char str[100];
 	int nata, result=0;

 	printf("digite o numero: ");
 	scanf("%d",&n);
 	printf("\n");

 	result=fatexp(n);
 	printf("%d\n",result); 

 	gets(str);

 	result= palindrome(str, 0, strlen(str)-1);

 	if (result==1)

 	printf("eh palindrome\n");

 	else printf("num eh\n");
 }




9. Projete um algoritmo recursivo que inverta a ordem dos elementos de um vetor.




int invertevet(int *vet, int ini, int fin){

	if(fin-ini>0){

	int aux;

	aux=vet[ini];
	vet[ini]=vet[fin];
	vet[fin]=aux;

	return invertevet(vet, ini+1, fin-1);
	}
	else return 0;


}


 int main(){

 	int *vet;
 	int i,n;

 	scanf("%d",&n);

 	vet=malloc(sizeof (int)*n);

 	for(i=0; i<5; i++){

 		scanf("%d", &vet[i]);
 	}


 	invertevet(vet, 0, 5-1);

 	for(i=0; i<5; i++){

 		printf("%d ",vet[i]);

 	}

	free(vet);
 	return 0;
 }


11. Projete uma func̃ao recursiva que receba um numero inteiro n e calcule a soma dos dıgitos de n. Ex.:
para n = 327, o resultado  ́e 12 = 3 + 2 + 7.


*/

int somadig(int n){

	if(n>0){

		int aux=0;

		return aux+=(n%10)+somadig(n/10);

		
	}
	else return 0;

}


int main(){

	int n,res;


	scanf("%d",&n);

	res=somadig(n);

	printf("%d\n",res);

	return 0;
}

