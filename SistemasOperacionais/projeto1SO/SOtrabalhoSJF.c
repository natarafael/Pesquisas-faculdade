#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//estrutura de dados para PCB, contendo no minimo 3 informaçoes sobre os processos
typedef struct PCB{
	
	int ID;
	int duracao;
	char estado[MAX];
	int tempo_espera;

}PCB;



//brief: função void para ler arquivo de entrada 
//Parametros: vetor de processos, arquivo de entrada e variavel para armazenar tamanho
//Pre: vetor criado, arquivo carregado
//Pos: nao retorna dados
void obtemProcess(PCB* process_list, FILE* file, int n){

	char linha[MAX]; int aux, aux1;

	
	for(int i=0; i<n;i++){

		fgets(linha, MAX, file);

		sscanf(linha, "%d %d", &process_list[i].ID, &process_list[i].duracao);

		strcpy(process_list[i].estado,"criado");
		
	}
	
}

//brief: função para preencher arquivo relatorio de saida
//Parametros: vetor de processos e arquivo de saida
//Pre: vetor carregado e arquivo criado
//Pos: nao retorna dados
void imprimeRelat( PCB* process_list, int n, FILE* f){

		for(int i=0; i<n; i++){

			fprintf(f, "ID: %d", process_list[i].ID );
			fprintf(f, "\t\t|\t\tDuração: %d", process_list[i].duracao );
			fprintf(f, "\t\t|\t\ttempo de espera: %d", process_list[i].tempo_espera );
			fprintf(f, "\t\t|\t\testado: %s\n", process_list[i].estado);			
		}

		fprintf(f, "-------------------------\n\n" );
}

//brief: procedimento para gerar arquivo de saida com informações dos procesos
//Parametros: vetor de dados PCB e arquivo 
//Pre: vetor carregado e arquivo criado
//Pos: nao retorna dados
void imprimeFirstRelat( PCB* process_list, int n, FILE* f){

		for(int i=0; i<n; i++){

			fprintf(f, "ID: %d", process_list[i].ID );
			fprintf(f, "\t\t|\t\tDuração: %d", process_list[i].duracao );
			//fprintf(f, "\t\t|\t\ttempo de espera: %d", process_list[i].tempo_espera );
			fprintf(f, "\t\t|\t\testado: %s\n", process_list[i].estado);			
		}

		fprintf(f, "-------------------------\n\n" );
}

//brief: função para ordenar de acordo com algoritmo 
//Parametros: vetor de PCB e numero de procesos
//Pre: vetor carregado
//Pos: retorna o medidor de qualidade do algoritmo
float SJFProcessOrder(PCB *process_list, int n){

	int i, j, x, aux;
	int te[n];
	float mediaTempoEspera, total=0;


	//algoritimo de ordenacao de processos
	for(i=0; i<n;i++){

		x=i;
		for(j=i+1; j<n;j++){
			if(process_list[j].duracao<process_list[x].duracao)
				x=j;
		}
		aux = process_list[i].duracao;
		process_list[i].duracao=process_list[x].duracao;
		process_list[x].duracao=aux;

		aux = process_list[i].ID;
		process_list[i].ID=process_list[x].ID;
		process_list[x].ID=aux;
		strcpy(process_list[i].estado,"pronto");

	}

	te[0]=0;

	for(i=1; i<n; i++){

		te[i]=0;
		for(j=0; j<i;j++)
			te[i]+=process_list[j].duracao;
			
		total+=te[i];
	}

	for (i = 0; i < n; ++i)
		process_list[i].tempo_espera=te[i];
	

	return mediaTempoEspera=total/n;
}

//brief: procedimento auxiliar para impressao em prompt de comando
//Parametros: vetor de processos
//Pre: vetor carregado
//Pos: nao retorna dados
void imprime(PCB *process_list, int n){

		for(int i=0; i<n;i++){

		printf("ID:%d duracao: %d estado: %s\n", process_list[i].ID, process_list[i].duracao, process_list[i].estado);
	}
}


//brief: função para simular algoritmo SJF 
//Parametros: vetor de processos, arquivo e variavel para armazenar criterio de qualidade
//Pre: vetor carregado, arquivo criado 
//Pos: nao retorna dados
void SJFProcess( PCB* process_list, int n, FILE* f, float mediaTempoEspera){

int i=0,j=0;
	
	while(n>0){
	
		strcpy(process_list[i].estado, "em execucao");
		imprimeRelat(process_list, n, f);
		strcpy(process_list[i].estado, "encerrado");
		imprimeRelat(process_list, n, f);
		
		for(j=i; j<n; ++j){


			process_list[j]=process_list[j+1];

		} n--;

	}

	fprintf(f, "Tempo medio de espera=%.2f\n",mediaTempoEspera);	
		
}



int main(){

	//vetor de estruturas que contem o numero de processos
	PCB *process_list;

	FILE *file = fopen("entrada_SJF.txt","r");
	FILE *f = fopen("Relat_SJF.txt","w");
	int n=0;
	float mediaTempoEspera;
	char linha[MAX];
	fgets(linha, MAX, file);
	sscanf(linha, "%d\n", &n);

	process_list = (PCB*)malloc(n*sizeof(PCB));

	//obterNprocess(&process_list, file);

	obtemProcess(process_list, file, n);

	imprimeFirstRelat(process_list, n, f);

	mediaTempoEspera=SJFProcessOrder(process_list, n);

	imprimeRelat(process_list, n, f);

	SJFProcess(process_list, n, f, mediaTempoEspera);


	fclose(file);
	fclose(f);
	free(process_list);
	return 0;
}