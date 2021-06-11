#include "trie.h"
#include "funcoes.h"

/**
 * @brief novaTrie função para criar uma arvore ou nó trie
 * @return retorna a nova arvore alocada
 */
Trie* novaTrie(){
	Trie* trie=(Trie*)malloc(sizeof(Trie));
	memset(trie, 0, sizeof(Trie));
	return trie;
}


/**
 * @brief proxPalavra obtem a primeira palavra contida na string, grava em palavra e remove de string
 * @param str string string de onde a palavra vai ser lida
 * @param palavra variavel que vai conter a palavra que deve ser inserida na arvore
 * @return retorna valor booleano dizendo se foi feita a operação
 */
int proxPalavra(char* str, char* palavra){

	char* origem = str;

	for(;;){

		//percorre ate o final ou ate achar uma letra que seja precedida de um separador
		char ultimo= ' ';
		while(*origem && (!ehLetra(*origem) || !ehseparador(ultimo))){
			ultimo = *origem;
			++origem;
		}

		//se chegou no final esvazia as duas strings e retorna falso
		if(!*origem){
			*palavra = *str = '\0';
			return 0;
		}

		//copia todas as letras consecutivas para string destino
		char* destino = palavra;
		while(ehLetra(*origem)){
			*destino=toLower(*origem);
			++origem;
			++destino;
		}
		*destino='\0';

		//se chegou ao final da string origem ou a um separador remove a parte lida da original
		if(!*origem || ehseparador(*origem)){
			strcpy(str, origem);
			return 1;
		}

		//atingiu um caractere invalido, percorre a string ate um separador ou ate o final
		while(*origem && !ehseparador(*origem)) ++origem;
	}
}

/**
 * @brief setaFinal seta nó como final de palavra
 * @param noh nó que va ser final de palavra
 */
void setaFinal(Trie* noh){
	noh->fim=1;
}

/**
 * @brief setaNaoFinal seta nó da arvore como não final de palavra
 * @param noh nó que será definido como não final
 */
void setaNaoFinal(Trie* noh){
	noh->fim=0;
}

/**
 * @brief noEhFinal teste se é nó final de uma palavra
 * @param noh no que vai ser testado
 * @return retorna booleano dizendo se é final ou não
 */
int noEhFinal(Trie* noh){
	return noh->fim;
}


/**
 * @brief adicionaTrie adiciona string a uma arvore ou nó trie
 * @param raiz onde será o inicio da palavra
 * @param str string que vai ser adicionada 
 * @return retorna booleano se a string foi adiciona na arvore
 */
int adicionaTrie(Trie* raiz, char str[]){

	if(!*str){
		int incr = !noEhFinal(raiz);
		setaFinal(raiz);
		if(incr) raiz->tam++;
		return incr;
	}
	int i = *str -'a';
	if(!raiz->filhos[i])
		raiz->filhos[i] = novaTrie();
	if(!adicionaTrie(raiz->filhos[i], str+1))
		return 0;
	++raiz->tam;
	return 1;

}


/**
 * @brief addArqTotrie adiciona arquivo de texto que contem as palavras a arvore trie
 * @param trie arvore trie
 * @param arq arquivo fonte, ja aberto para leitura
 */
void addArqTotrie(Trie* trie, FILE* arq){

	char palavra[200];
	char linha[1000];

	while(!feof(arq)){

		fgets(linha, 1000, arq);
		while(proxPalavra(linha, palavra)){
			adicionaTrie(trie, palavra);
		}

	}

}

/**
 * @brief strPush adiciona caractere na ultima posição de uma string
 * @param str string onde sera adicionado o caractere
 * @param ch caracter que sera adicionado
 */
void strPush(char str[], char ch) {
	int tam = strlen(str);
	str[tam] = ch;
	str[tam + 1] = '\0';
}

/**
 * @brief strPop retira ultimo caractere de uma string
 * @param str string que sera removido o caractere
 * @return retorna o caracter removido
 */
char strPop(char str[]) {
	int tam = strlen(str);
	char ch = str[tam - 1];
	str[tam - 1] = '\0';
	return ch;
}


/**
 * @brief printaNoh printa as palavras existentes a partir do no dado como prefixo
 * @param raiz raiz que sera printado a partir
 * @param prefixo variavel que diz a partir de onde sera printado
 */
void printaNoh(Trie* raiz, char *prefixo){

	if(noEhFinal(raiz)){
		printf("---------------------------------------------------------------------\n");
		printf("%s\n",prefixo);
	}
	int i;	
	for(i=0; i<26; ++i){
		if(raiz->filhos[i]){
			strPush(prefixo, 'a'+i);
			printaNoh(raiz->filhos[i], prefixo);
			strPop(prefixo);
		}
	}

}

/**
 * @brief printarTrie printa todas as palavras da arvore
 * @param raiz raiz que sera printada
 */
void printarTrie(Trie* raiz){

	char prefixo[200]="";
	printaNoh(raiz, prefixo);
}

/**
 * @brief procuraNoh função que procura no na arvore
 * @param raiz raiz de onde a busca iniciará 
 * @param str string que sera buscada
 * @return retorna o nó ou null, caso nao encontrado
 */
Trie* procuraNoh(Trie* raiz, char *str){

	if(!raiz) return NULL;
	if(!*str) return raiz;
	int i = *str - 'a';
	return procuraNoh(raiz->filhos[i], str+1);

}

/**
 * @brief printarTriePrefixo printa no a partir de um prefixo informado
 * @param raiz raiz onde será procurado no prefixo
 * @param prefixo parametro que informa qual nó quer printar
 */
void printarTriePrefixo(Trie* raiz, char *prefixo){

 	raiz= procuraNoh(raiz, prefixo);
 	if(raiz) printaNoh(raiz, prefixo);
}

/**
 * @brief desalocaTrie desaloca a arvore trie da memoria
 * @param raiz raiz da arvore 
 */
void desalocaTrie(Trie* raiz){

	for(int i=0;i<26;++i){
		if(raiz->filhos[i]){
			desalocaTrie(raiz->filhos[i]);
		}
	}
	free(raiz);
}


/**
 * @brief semelhantes função que verifica se a string pode ser transformada em outras com base no numero maximo de modificações
 *  definido pela var def
 * @param str1 string que sera comparada
 * @param str2 segunda string que sera comparada
 * @param dife numero de modificações permitidas
 * @return booleano dizendo se são compativeis
 */
int semelhantes(char* str1, char* str2, int dife){

	//ultrapassou o limite de diferenças
	if(dife<0)
		return 0;

	//duas strings vazias sao compativeis
	if(!*str1 && !*str2)
		return 1;

	//caso str1 esteja vazia sera compativel com str2 se a quantidade de caracteres em str2 for menor ou
	//igual ao limite de modificacoes
	if(!*str1)
		return strlen(str2) <=dife;

	//inverso
	if(!*str2)
		return strlen(str1) <= dife;

	//caso str1 e str2 comecem com o mesmo caractere a resposta sera a compatibilidade do restante das strings
	if(*str1 == *str2)
		return semelhantes(str1+1, str2+1, dife);

	//eh necessario testar a compatibilidade com uma alteracao, diminuindo o limite
	--dife;

	//tenta remover um caractere de str2
	if(semelhantes(str1, str2+1, dife))
		return 1;
	//contrario
	if(semelhantes(str1+1, str2, dife))
		return 1;

	if(semelhantes(str1+1, str2+1, dife))
		return 1;

	return 0;
}

/**
 * @brief printaNohSimilar imprime palavras similares de acordo com o prefixo e numero de modificações
 * @param raiz raiz da arvore 
 * @param prefixo prefixo que determina a similaridade 
 * @param str string contendo palavras
 * @param dife numero maximo de modificações
 */
void printaNohSimilar(Trie* raiz, char *prefixo, char *str, int dife){

	if(noEhFinal(raiz) && semelhantes(prefixo, str, dife)){
		printf("%s\n", prefixo);
	}

	for(int i=0; i<26;++i){

		if(raiz->filhos[i]){
			strPush(prefixo, 'a'+ i);
			printaNohSimilar(raiz->filhos[i], prefixo, str, dife);
			strPop(prefixo);
		}
	}
}


/**
 * @brief printaTrieSimilar printa todos os nos similares de acordo com o prefixo informado
 * @param raiz raiz da arvore 
 * @param str 
 * @param dife numero que define o maximo de alterações nas similiaridades 
 */
void printaTrieSimilar(Trie* raiz, char *str, int dife){

	char prefixo[256]="";
	printaNohSimilar(raiz, prefixo, str, dife);

}

/**
 * @brief removerTrie remove string da arvore trie
 * @param raiz raiz de onde sera removido a string
 * @param str string que sera removida
 * @return retorna valor booleano se foi ou nao removida a palavra
 */
int removerTrie(Trie* raiz, char *str){

	if(!*str){
		if(!noEhFinal(raiz))
			return 0;
		setaNaoFinal(raiz);
		return 1;
	}

	int i = *str - 'a';
	if(raiz->filhos[i]==NULL)
		return 0;
	if(!removerTrie(raiz->filhos[i], str+1))
		return 0;
	if(raiz->filhos[i]->tam==0){
		free(raiz->filhos[i]);
		raiz->filhos[i]=NULL;

	}

	--raiz->tam;
	return 1;
}


/**
 * @brief removeArquivo arquivo fonte de onde as palavras serão removidas da arvore
 * @param trie arvore trie 
 * @param arq arquivo fonte
 */
void removeArquivo(Trie* trie, FILE* arq){

	char palavra[200];
	char linha[100];

	while(!feof(arq)){
		fgets(linha, 1000, arq);
		while(proxPalavra(linha, palavra)){
			removerTrie(trie, palavra);
		}
	}
}