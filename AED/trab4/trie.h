#ifndef TRIE_H
#define TRIE_H
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// estrutura da arvore trie
typedef struct Trie{
	
	int fim;
	int tam;
	struct Trie* filhos[26];

}Trie;

/**
 * @brief novaTrie função para criar uma arvore ou nó trie
 * @return retorna a nova arvore alocada
 */
Trie* novaTrie();

/**
 * @brief proxPalavra obtem a primeira palavra contida na string, grava em palavra e remove de string
 * @param str string string de onde a palavra vai ser lida
 * @param palavra variavel que vai conter a palavra que deve ser inserida na arvore
 * @return retorna valor booleano dizendo se foi feita a operação
 */
int proxPalavra(char* str, char* palavra);

/**
 * @brief noEhFinal teste se é nó final de uma palavra
 * @param noh no que vai ser testado
 * @return retorna booleano dizendo se é final ou não
 */
int noEhFinal(Trie* noh);

/**
 * @brief setaFinal seta nó como final de palavra
 * @param noh nó que va ser final de palavra
 */
void setaFinal(Trie* noh);

/**
 * @brief setaNaoFinal seta nó da arvore como não final de palavra
 * @param noh nó que será definido como não final
 */
void setaNaoFinal(Trie* noh);

/**
 * @brief adicionaTrie adiciona string a uma arvore ou nó trie
 * @param raiz onde será o inicio da palavra
 * @param str string que vai ser adicionada 
 * @return retorna booleano se a string foi adiciona na arvore
 */
int adicionaTrie(Trie* raiz, char str[]);

/**
 * @brief addArqTotrie adiciona arquivo de texto que contem as palavras a arvore trie
 * @param trie arvore trie
 * @param arq arquivo fonte, ja aberto para leitura
 */
void addArqTotrie(Trie* trie, FILE* arq);

/**
 * @brief printarTrie printa todas as palavras da arvore
 * @param raiz raiz que sera printada
 */
void printarTrie(Trie* raiz);

/**
 * @brief printaNoh printa as palavras existentes a partir do no dado como prefixo
 * @param raiz raiz que sera printado a partir
 * @param prefixo variavel que diz a partir de onde sera printado
 */
void printaNoh(Trie* raiz, char *prefixo);

/**
 * @brief strPop retira ultimo caractere de uma string
 * @param str string que sera removido o caractere
 * @return retorna o caracter removido
 */
char strPop(char str[]);

/**
 * @brief strPush adiciona caractere na ultima posição de uma string
 * @param str string onde sera adicionado o caractere
 * @param ch caracter que sera adicionado
 */
void strPush(char str[], char ch);

/**
 * @brief procuraNoh função que procura no na arvore
 * @param raiz raiz de onde a busca iniciará 
 * @param str string que sera buscada
 * @return retorna o nó ou null, caso nao encontrado
 */
Trie* procuraNoh(Trie* raiz, char *str);

/**
 * @brief printarTriePrefixo printa no a partir de um prefixo informado
 * @param raiz raiz onde será procurado no prefixo
 * @param prefixo parametro que informa qual nó quer printar
 */
void printarTriePrefixo(Trie* raiz, char *prefixo);

/**
 * @brief desalocaTrie desaloca a arvore trie da memoria
 * @param raiz raiz da arvore 
 */
void desalocaTrie(Trie* raiz);

/**
 * @brief printaTrieSimilar printa todos os nos similares de acordo com o prefixo informado
 * @param raiz raiz da arvore 
 * @param str 
 * @param dife numero que define o maximo de alterações nas similiaridades 
 */
void printaTrieSimilar(Trie* raiz, char *str, int dife);

/**
 * @brief semelhantes função que verifica se a string pode ser transformada em outras com base no numero maximo de modificações
 *  definido pela var def
 * @param str1 string que sera comparada
 * @param str2 segunda string que sera comparada
 * @param dife numero de modificações permitidas
 * @return booleano dizendo se são compativeis
 */
int semelhantes(char* str1, char* str2, int dife);

/**
 * @brief printaNohSimilar imprime palavras similares de acordo com o prefixo e numero de modificações
 * @param raiz raiz da arvore 
 * @param prefixo prefixo que determina a similaridade 
 * @param str string contendo palavras
 * @param dife numero maximo de modificações
 */
void printaNohSimilar(Trie* raiz, char *prefixo, char *str, int dife);

/**
 * @brief removerTrie remove string da arvore trie
 * @param raiz raiz de onde sera removido a string
 * @param str string que sera removida
 * @return retorna valor booleano se foi ou nao removida a palavra
 */
int removerTrie(Trie* raiz, char *str);

/**
 * @brief removeArquivo arquivo fonte de onde as palavras serão removidas da arvore
 * @param trie arvore trie 
 * @param arq arquivo fonte
 */
void removeArquivo(Trie* trie, FILE* arq);

#endif