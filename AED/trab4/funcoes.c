#ifndef FUNCOES_C
#define FUNCOES_C
#include "funcoes.h"

/**
 * @brief lerNome Obtem nome do arquivo texto
 * @param argv argumento de entrada no cmd
 * @return nenhum
 */
char *lerNome(const char *argv[]);
char *lerNome(const char *argv[]){

    return ((char*)argv[0]);

}

/**
 * @brief menu 
 * @return nenhum
 */

int menu(){

	int choice;

	printf("\nDigite a opcao desejada\n\n");
	printf("[1] Carregar palavras de um arquivo\n");
	printf("[2] Printar todas palavras\n");
	printf("[3] Printar por prefixo\n");
	printf("[4] Printar similares\n");
	printf("[5] Remover a partir de arquivo\n");
	printf("[0] Sair\n");


	printf("opcao: ");
	scanf("%d%*c",&choice);
	printf("\n");

	return choice;
}

/**
 * @brief ehLetra verifica se char é uma letra do alfabeto minusculo
 * @param ch char contendo letra que está sendo analizada
 * @return retorna booleano se é letra ou nao
 */
char toLower(char ch){

	if(ch >='A' && ch <='Z')
		return ch=tolower(ch);

	return ch;
}

/**
 * @brief toLower transforma letra em minuscula
 * @param ch char que vai ser transformado
 * @return retorna letra minuscula
 */
int ehLetra(char ch){

	if (ch >= 'A' && ch <= 'Z') return 1;
	if (ch >= 'a' && ch <= 'z') return 1;
	return 0;
}


char separadores[] = " \n\r\t.!?,:;()";

/**
 * @brief ehseparador verifica se o caractere é um separador
 * @param ch char que vai ser restado
 * @return booleano dizendo se é separador ou não
 */
int ehseparador(char ch){

	return strchr(separadores, ch) !=NULL;
}


#endif

