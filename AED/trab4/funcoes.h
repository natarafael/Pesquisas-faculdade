#ifndef FUNCOES_H
#define FUNCOES_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/**
 * @brief lerNome Obtem nome do arquivo texto
 * @param argv argumento de entrada no cmd
 * @return nenhum
 */
char *lerNome(const char *argv[]);

/**
 * @brief menu 
 * @return nenhum
 */
int menu();

/**
 * @brief ehLetra verifica se char é uma letra do alfabeto minusculo
 * @param ch char contendo letra que está sendo analizada
 * @return retorna booleano se é letra ou nao
 */
int ehLetra(char ch);

/**
 * @brief toLower transforma letra em minuscula
 * @param ch char que vai ser transformado
 * @return retorna letra minuscula
 */
char toLower(char ch);

/**
 * @brief ehseparador verifica se o caractere é um separador
 * @param ch char que vai ser restado
 * @return booleano dizendo se é separador ou não
 */
int ehseparador(char ch);





#endif