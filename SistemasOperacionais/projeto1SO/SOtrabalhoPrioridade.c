#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

//estrutura para definir os dados do PCB	
typedef struct PCB{

	int id;
	int prioridade;
	int chegada;
	char estado[MAX];
	int tempoEspera;

}PCB;


//brief: função para alocar e inserir os processos na estrutura do PCB
//Parametros: estrutura de dados PCB, arquivo de entrada e variavel pro numero de dados lidos
//Pre: arquivo carregado 
//Pos: retorna estrura de dados ja alocada na memoria e retorna tamanho do N lido do arquivo
PCB* inserirPcs(PCB* process, FILE* file, int *t){

	char linha[MAX];
	int i=0,n=0;

	fgets(linha, MAX, file);
	sscanf(linha, "%d", &n);
	process=(PCB*)malloc(n*sizeof(PCB));


	while(i<n){

		fgets(linha, MAX, file);
		sscanf(linha, "%d %d %d", &process[i].id, &process[i].chegada, &process[i].prioridade);
		strcpy(process[i].estado,"criado");
	
		i++;
	}

	*t=n;
	return process;
}


//brief: atualiza estado dos processos
//Parametros: vetor e numero de processos
//Pre:  vetor criado
//Pos: null
void AttEstado(PCB* process, int n){

	for (int i = 0; i < n; ++i)
	{
		strcpy(process[i].estado,"pronto");
	}

}


//brief: ordena os processos de acordo com a filosofia do algoritimo implementado
//Parametros: vetor e numero de processos
//Pre: vetor alocado
//Pos: retorna medidas de qualidade
float processOrder(PCB* process, int n){

	int i, aux, aux1, aux2, j, teTotal=0;
	int te[n];
	float TMTE=2;

	//função para ordenar processos de acordo com a prioridade, metodo estavel para preservar processos de mesma prioridade
	for(i=1; i<n; i++){

		aux=process[i].prioridade;
		aux1=process[i].chegada;
		aux2=process[i].id;
		j=i-1;

		while(j>=0 && process[j].prioridade> aux){
			process[j+1].prioridade= process[j].prioridade;
			process[j+1].id= process[j].id;
			process[j+1].chegada= process[j].chegada;
			j=j-1;
		}
		process[j+1].prioridade=aux;
		process[j+1].id=aux2;
		process[j+1].chegada=aux1;
	}

	AttEstado(process, n);

	//funções e dados auxiliares para obter calculos de medição de qualidade
	te[0]=0;
		for(i=1; i<n; i++)
			te[i]= process[i-1].chegada + te[i-1];

	for (i = 0; i < n; i++)
		teTotal+=te[i];
		

	for ( i = 0; i < n; ++i)
		process[i].tempoEspera=te[i];

	return TMTE= (float)teTotal/(float)n;
	
}

//brief: imprime resultados no prompt de comando, auxiliar para programação
//Parametros: vetor contendo processos, numero total de processos
//Pre: vetor carregado
//Pos: null
void imprime(PCB* process, int n){


	for (int i = 0; i < n; ++i){
		
		printf("ID: %d ", process[i].id);
		printf("chegada: %d ", process[i].chegada);
		printf("prioridade: %d ", process[i].prioridade);
		printf("Estado: prioridade: %s\n", process[i].estado);
		printf("------------\n");
	}

}


//brief: função para imprimir relatorio final em txt
//Parametros: vetor com processos, numero total de processos e arquivo de saida
//Pre: vetor carregado e arquivo criado
//Pos: nao retorna dados mas preenche arquivo de saida
void imprimeRelat( PCB* process, int n, FILE* f){

		for(int i=0; i<n; i++){

			fprintf(f, "ID: %d", process[i].id );
			fprintf(f, "\t\t|\t\tPrioridade: %d", process[i].prioridade );
			fprintf(f, "\t\t|\t\tTempo de chegada: %d", process[i].chegada );
			fprintf(f, "\t\t|\t\tTempo de espera: %d",  process[i].tempoEspera);
			fprintf(f, "\t\t|\t\tEstado: %s\n", process[i].estado);			
		}

		fprintf(f, "-------------------------\n\n" );
}

//brief: função auxiliar para imprimir no arquivo de saida dados sem o tempo de espera
//Parametros: vetor de processos, numero total de processos e arquivo de saida
//Pre: vetor carregado e arquivo criado 
//Pos: nao retorna dados mas preenche arquivo de saida
void imprimeFirstRelat( PCB* process, int n, FILE* f){

		for(int i=0; i<n; i++){

			fprintf(f, "ID: %d", process[i].id );
			fprintf(f, "\t\t|\t\tPrioridade: %d", process[i].prioridade );
			fprintf(f, "\t\t|\t\tTempo de chegada: %d", process[i].chegada );
			fprintf(f, "\t\t|\t\tEstado: %s\n", process[i].estado);			
		}

		fprintf(f, "-------------------------\n\n" );
}

//brief: função para simular processamento de dados de acordo com o algoritmo
//Parametros: vetor de processos, numero total de processos e arquivo
//Pre: vetor e arquivo carregado
//Pos:
void PriorityProcess( PCB* process,int n, FILE* f){

int i=0,j=0;
	
	while(n>0){
	
		strcpy(process[i].estado, "em execucao");
		imprimeRelat(process, n, f);
		strcpy(process[i].estado, "encerrado");
		imprimeRelat(process, n, f);
		
		for(j=i; j<n; ++j){

			process[j]=process[j+1];

		} n--;

	}

		
		
}



int main(){
	
	int n=0;
	float TMTE=0;
	FILE* file=fopen("entrada_priority.txt", "r");
	PCB* process;
	FILE *f = fopen("relat_priority.txt","w");
	

	process=inserirPcs(process, file, &n);

	imprimeFirstRelat(process, n, f);

	//imprime(process, n);
	
	TMTE=processOrder(process,n);

	imprimeRelat(process,n, f);

	PriorityProcess(process,n, f);

	fprintf(f, "Tempo medio de espera = %.2f\n",TMTE);
	//imprime(process, n);


	free(process);
	fclose(file);
	fclose(f);

	return 0;
}