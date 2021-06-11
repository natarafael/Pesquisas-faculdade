#include "funcoes.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]){
	
	int choice, dife;
	char* nomeArq;
	char nomeArqRemovido[100];
	char prefixo[100];
	FILE* arquivo;
	FILE* arquivo2;
	Trie* trie = novaTrie();


	choice = menu();


	while(choice){

		switch(choice){
 
			case 1:

				nomeArq=lerNome(argv+1);
				arquivo=fopen(nomeArq, "r");
				if(arquivo==NULL){
					printf("nao foi possivel abrir arquivo...\n");
					return 0;
				}
				else{

					addArqTotrie(trie, arquivo);
					printf("O arquivo foi carregado na arvore\n\n");
					system("pause");
					system("cls");
				}
				fclose(arquivo);
			break;

			case 2:

				printf("Todas palavras: \n");
				printarTrie(trie);
				printf("---------------------------------------------------------------------\n");
				printf("Total de palavras: %d\n",trie->tam);

				system("pause");
				system("cls");
			break;

			case 3:

				printf("digite o prefixo: ");
				gets(prefixo);
				printf("\n");

				printf("todas palavras com o prefixo %s:\n", prefixo);
				printarTriePrefixo(trie, prefixo);
				printf("---------------------------------------------------------------------\n");

				system("pause");
				system("cls");
			break;

			case 4:

				printf("similares ha: ");
				gets(prefixo);
				printf("\nNumero maximo de alteracoes: \n");
				scanf("%d%*c", &dife);

				printaTrieSimilar(trie, prefixo, dife);
				printf("---------------------------------------------------------------------\n");

				system("pause");
				system("cls");

			break;

			case 5:

				printf("digite o nome do arquivo: \n");
				gets(nomeArqRemovido);
				arquivo2 = fopen(nomeArqRemovido, "r");

				if(arquivo2 == NULL){
					printf("nao foi possivel ler arquivo\n");
					return 0;
				}else{
				
					removeArquivo(trie, arquivo2);
					printf("O arquivo foi carregado \n\n");
					system("pause");
					system("cls");
				}
				
				fclose(arquivo2);
			break;
		}

	choice = menu();
	}

	desalocaTrie(trie);


	return 0;
}