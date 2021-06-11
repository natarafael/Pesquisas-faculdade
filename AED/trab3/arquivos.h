#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "structs.h"

#include <stdio.h>
#include <stdlib.h>


//Le o cabecalho do arquivo de indice (arvore)
//Entrada: O arquivo de indices
//Retorno: Cabecalho preenchido
//Pre-condicao: Arquivo nao nulo
//Pos-condicao: Cabecalho lido
cabecalhoArvore* le_cabecalhoArvore(FILE* arq);

//Escreve o cabecalho no arquivo de indices
//Entrada: O arquivo de indices e o cabecalho que sera escrito
//Retorno: Nenhum
//Pre-condicao: Arquivo e cabecalhos nao nulos
//Pos-condicao: Cabecalho escrito no arquivo
void escreve_cabecalhoArvore(FILE* arq, cabecalhoArvore* cab);

//Cria o arquivo de indices com o cabecalho inicial
//Entrada: O arquivo de indices
//Retorno: Nenhum
//Pre-condicao: Arquivo nao nulo
//Pos-condicao: Arquivo inicializado
void criaIndice(FILE* arq);

//Le o no que esta na posicao desejada do arquivo
//Entrada: O arquivo de indices e a posicao que esta o no
//Retorno: Struct no com os dados preenchidos
//Pre-condicao: Arquivo nao nulo
//Pos-condicao: No lido
arvoreBMais* le_no_Indice(FILE* arq, int pos);

//Escreve no arquivo a informacao contida na struct na posicao informada
//Parametro: arquivo a ser aberto, struct com a informacao e a pos onde deve ser escrito
//Pre: arquivo valido, uma struct com informacoes e a posicao valida
//Pos: arquivo sera escrito ou sobrescrito com as informcoes obtidas
void escreve_no_Arvore(FILE* arq, arvoreBMais* x, int pos);

//Abre o arquivo, guarda a informacao que contem na primeira linha do arquivo[cabecalho] e entao o retorna
//parametro: arquvio a ser aberto
//pre: arquivo ja deve ter sido inicializado com as informacoes e o seu cabecalho deve ser do tipo correto
cabecalho_dados* le_cabecalho_Dados(FILE * arq);

//Escreve a struct na primeira linha [cabecalho] do arquivo
//Parametro: arquivo a ser aberto
void escreve_cabecalho_Dados(FILE* arq, cabecalho_dados* cab);

//Inicializa o cabecalho do arquivo
//Parametro: arquivo a ser inicializado
void cria_arquivo_Dados(FILE* arq);

//Retorna uma struct com o conteudo da pos informada
//Parametro: arquivo a ser aberto e a pos onde deve abrir
//Pre: posicao deve ser uma posicao valida
dados_livro* le_no_Dados(FILE* arq, int pos);

//Escreve no arquivo a informacao contida na struct na posicao informada
//Parametro: arquivo a ser aberto, struct com a informacao e a pos onde deve ser escrito
//Pre: arquivo valido, uma struct com informacoes e a posicao valida
//Pos: arquivo sera escrito ou sobrescrito com as informcoes obtidas
void escreve_no_Dados(FILE* arq, dados_livro* x, int pos);
//Entrada:Arquivo binario, posicao valida e struct contendo os dados do livro
//Saida: Nenhuma
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
//Descricao: Insere os dados da biblioteca no arquivo
int insere_arq_dados(FILE* arq , dados_livro* livro);

//Entrada:Arquivo binario, posicao valida e struct contendo os dados da arvore
//Saida: Posicao adicionada
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
//Descricao: Insere os dados da arvore no arvore
int insere_arq_indice(FILE* arq, arvoreBMais* r);

//Entrada: arquivo de indice, posicao do no
//Pre: posicao do no a ser removido
//Pos: posicao livre do cabecalho atualizada
//Libera um no do arquivo
void remove_arq_indice(FILE* arq, int pos);

//Entrada: arquivo de dados, posicao do livro
//Pre: posicao do no a ser removido
//Pos: posicao livre do cabecalho atualizada
//Libera um no do arquivo
void remove_arq_dados(FILE* arq, int pos_registro);

#endif //ARQUIVO_H"