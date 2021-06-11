#ifndef MODELO_H
#define MODELO_H

#include "structs.h"
#include "arquivos.h"


//Retorna falso[0] caso o char a ser verificado seja invalido
//Param: char a ser verificado
int verifica_espaco(char c);

//percorre uma string verificando retirando todos caracteres invalidos pelo programa
//Parametro: string para comparar
//Pos: string modificada, com apenas caracteres validos
void retirar_espaco(char s[]);

//Entrada: Dados da arvore, arquivo e posicoes auxiliares e mediana.
//Saida: Chave promovida.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: Realiza-se o split, promovendo uma chave.
arvoreBMais* split(FILE* arq , arvoreBMais* x, int *m, int pos_arq);

//Entrada: Struct contendo os dados da arvore.
//Saida: Chave com overflow.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave ou nó com overflow.
int overflow(arvoreBMais* r);

//Entrada: Struct contendo os dados da arvore.
//Saida: Chave com underflow.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave ou nó com underflow.
int underflow(arvoreBMais* r);

//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Posicao a ser buscada.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave contendo a posicao que se buca.
int buscaPos(arvoreBMais* r, int info, int * pos);

//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Remocao da chave.
//Descricao: retira a chave, puxando as outras chaves.
void retiraDireita(arvoreBMais* r, int pos);

//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: Adiciona-se a chave a direita.
void adicionaDireita(arvoreBMais* r, int pos, int codigo, int pos_ponteiro);

//Entrada:Arquivo binario, posicao do registro onde esta a struct e struct contendo os dados
//Saida: Nenhum
//Pre-condicao: arquivo deve ser carregado
//Pos-condicao: insere os dados do indice do arquivo
//Descricao: verifica se ha posicoes vazias para poder inserir senao adiciona na esquerda ou direita se for -1.
void insere_arvore_aux(FILE* arq, int pos_dados, int codigo, int pos_arq);

//Entrada:Arquivo binario, posicao do registro onde esta a struct e struct contendo os dados
//Saida: Nenhum
//Pre-condicao: arquivo deve ser carregado
//Pos-condicao: insere os dados do indice do arquivo
//Descricao: verifica se ha posicoes vazias para poder inserir senao adiciona na esquerda ou direita se for -1.
void insere_arvore(int codigo, int pos_dados, FILE* arq, int pos_raiz);

//Entrada: arquivo de Indice, pos do no, pos do no pai
//Pre: arvore previamente adicionada e a posicao da raiz
//Pos: pai de cada no setado
//Varre a arvore inteira dizendo para cada no quem eh seu pai
void setPai(FILE* arq, int pos, int pos_pai);

//Entrada: livro a ser adicionado, arquivos de indice e dados
//Pre: livro a ser inserido
//Pos: livro adicionado na arvore
//encaminha a insercao no arquivo de dados e no arquivo de indice
void insere_livro(dados_livro* livro, FILE* Indice, FILE* Dados);

//Entrada: arquivo com livros, indice e dados
//Pre: arquivo com livros
//Pos: livros do arquivo txt inseridos nos outros 2
//Insere os livros do txt na arvore
void armazena_bibliotecaTXT(FILE* arq, FILE* Indice, FILE* Dados);

//Entrada: no da arvore, codigo
//Saida: pos de uma chave
//retorna a posicao onde esta a primeira chave maior q o codigo
int SearchArray(arvoreBMais* r, int info);

//Entrada: arquivo de indice, posicao do no, codigo
//Pre: arvore inserida
//Pos: chaves da arvore B atualizadas
//Atualizacao de todas as chaves da arvore Indice
void arruma_arvore_indice(FILE* arq, int pos);

//Entrada: arquivo indice, posicao do no, posicao do irmao, posicao onde deve ser adicionado os valores de r no seu irmao, codigo
//Pre: posicoes do no, seu irmao e onde adicionar no irmao
//Pos: arvore modificada com a operacao de concatenacao
//tras todos os elementos do no q ira morrer para o irmao, caso nao seja folha, tras o do pai tbm e entao limpa os nos q sumirem
void Merge(FILE* arq, int pos_r, int pos_irmao, int lado_add, int codigo);

//Entrada: arquivo de indice, codigo, posicao da raiz
//Pre: codigo a ser removido
//Pos: codigo removido
//Saida: posicao onde o livro esta no arquivo de dados
//Faz o manejo da remocao de um codigo, (1) apenas remove sem alteracoes. (2) remove e consegue emprestar. (3) remove mas precisa concatenar
int remove_arvore_aux(FILE* arq, int codigo, int pos_raiz);

//Entrada: arquivos de indice e dados e o codigo do livro a ser removido
//Pre: codigo do livro a ser removido
//Pos: livro removido dos arquivos
//Faz as chamadas para remover o arquivo da arvore e do arquivo de dados
void remover(FILE* Indice, FILE* Dados, int codigo);

//Entrada: Arquivos de dados e da arvore.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Teste da impressao ordenada.
//Descricao: Exibi-se na tela os livros cadastrados e ordenados pelo codigo.
void imprime_acervo(FILE* Indice, FILE* Dados, arvoreBMais* r);

//Entrada: arquivo, no da arvore, contador para altura
//Saida: altura da arvore
//Pre: arvore inserida
//Descricao: Devolve a altura da arvore
int altura(FILE* arq ,arvoreBMais* r, int conta);

//Entrada: Arquivo, nivel a ser printado, contagem q comeca em 0 ate o nivel, no arvore
//Saida: Nenhuma
//Pre: arvore exista
//Descricao: imprime apenas os nos do nivel dado, ignorando os outros
void imprime_Arvore_aux(FILE* arq, int i, int conta, arvoreBMais* r);

//Entrada: Arquivo, dados da arvore e a posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Impressao da arvore pelos codigos inseridos em niveis.
//Descricao: A partir das funcoes auxiliares, é exibido na tela os codigos em formato de arvore em niveis.
void imprimeArvore(FILE* arq, arvoreBMais* r, int pos);

//Entrada: Arquivos dos dados da biblioteca e da arvore B+.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Teste de atualizacao dos exemplares cadastrados.
//Descricao: A partir do codigo do livro, o usuario atualiza o numero de exemplares disponiveis na biblioteca.
void atualizar_exemplares(FILE* arqDados, FILE* arqArv);

//Entrada: Arquivos dos dados da biblioteca e da arvore B+.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Retorna os dados buscados.
//Descricao: A partir do codigo, � feita a busca e retorna os dados do livro.
void buscar_dadosLivro(FILE* arqDados,FILE *arqArv);

#endif //MODEL_H