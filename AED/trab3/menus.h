#ifndef MENUS_H
#define MENUS_H

#include "structs.h"

#include <stdio.h>

//Menu com opcoes de alteracoes na biblioteca
//retorna o valor referente a escolha feita pelo usuario
int menu_cadastro();

//Com a escolha passada, encaminha o usuario para a funcao da opcao desejada
//Param Escolha para a funcao encaminhada arquivos de dados e indice, para repassar para as funcoes caso precisem
//Pre Escolha ja feita, arquivos inicializados
//Pos alguma modificao na arvore
void Encaminha(int Escolha, FILE* Indice, FILE* Dados);

//Menu rapido para escolher o codigo de remocao
//retorno codigo a ser removido
int menu_remover();

//Menu rapido, para armazenar os dados do livro a ser armazenado
//Param ponteiro para o livro q vai ser inserido
//Pre alocado a memorio do ponteiro livro
//Pos ponteiro com livro preenchido
void menu_insere(dados_livro* livro);

#endif //VIEW_H