#include "modelo.h"

//Retorna falso[0] caso o char a ser verificado seja invalido
//Param: char a ser verificado
int verifica_espaco(char c){
	
    return c == ' ' || c == '\n' || c == '\t'; 
}

//percorre uma string verificando retirando todos caracteres invalidos pelo programa
//Parametro: string para comparar
//Pos: string modificada, com apenas caracteres validos
void retirar_espaco(char s[]){
    char *aux = s;
    char *aux1 = s;

    while(verifica_espaco(*aux1)){
        ++aux1;
    }

    while(*aux1){
        *aux++ = *aux1++;
    }

    if(aux>s){
        while(verifica_espaco(aux[-1])){
            --aux;
        }
    }
    *aux = '\0';
}
//Entrada: Dados da arvore, arquivo e posicoes auxiliares e mediana.
//Saida: Chave promovida.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: Realiza-se o split, promovendo uma chave.
arvoreBMais* split(FILE* arq , arvoreBMais* x, int *m, int pos_arq) {
	arvoreBMais* y = (arvoreBMais*) malloc(sizeof(arvoreBMais));

	int k = 0;

	y->eh_folha = (x->eh_folha) ? 1 : 0;
	k = !y->eh_folha;

	int q = x->numChaves/2;
	y->numChaves = x->numChaves - q - k;
	x->numChaves = q;
	*m = x->codigo[q]; // chave mediana

	y->ponteiro[0] = x->ponteiro[q + k];
	for(int i = 0; i < y->numChaves; i++){
		y->codigo[i] = x->codigo[q+i+k];
		y->ponteiro[i+1] = x->ponteiro[q+i+1+k];
	}

	escreve_no_Arvore(arq, x, pos_arq);

	return y;
}
//Entrada: Struct contendo os dados da arvore.
//Saida: Chave com overflow.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave ou nó com overflow.
int overflow(arvoreBMais* r){
	return r->numChaves == ORDEM;
}
//Entrada: Struct contendo os dados da arvore.
//Saida: Chave com underflow.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave ou nó com underflow.
int underflow(arvoreBMais* r){
	return r->numChaves == (ORDEM/2)-1;
}
//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Posicao a ser buscada.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: É retornada a chave contendo a posicao que se buca.
int buscaPos(arvoreBMais* r, int info, int * pos) {
	for((*pos)=0; (*pos) < r->numChaves; (*pos)++)
		if(info == r->ponteiro[(*pos)])
			return 1; // codigo ja esta no vetor
		else if(info < r->codigo[(*pos)])
			break; // info pode estar na sub arvore

	return 0;
}
//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Remocao da chave.
//Descricao: retira a chave, puxando as outras chaves.
void retiraDireita(arvoreBMais* r, int pos){
	int i = pos;

	for(i = pos; i < r->numChaves-1; i++){
		r->codigo[i] = r->codigo[i+1];
		r->ponteiro[i+1] = r->ponteiro[i+2];
	}
	r->numChaves--;
}
//Entrada: Struct contendo os dados da arvore, informacao e posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Inserção da chave.
//Descricao: Adiciona-se a chave a direita.
void adicionaDireita(arvoreBMais* r, int pos, int codigo, int pos_ponteiro){
	int i;

	int k = 1;
	if(r->eh_folha) k = 0;
	
	for(i = r->numChaves; i > pos; i--){
		r->codigo[i] = r->codigo[i-1];
		r->ponteiro[i+k] = r->ponteiro[i-1+k];
	}

	r->codigo[pos] = codigo;
	r->ponteiro[pos+k] = pos_ponteiro;
	r->numChaves++;
}
//Entrada:Arquivo binario, posicao do registro onde esta a struct e struct contendo os dados
//Saida: Nenhum
//Pre-condicao: arquivo deve ser carregado
//Pos-condicao: insere os dados do indice do arquivo
//Descricao: verifica se ha posicoes vazias para poder inserir senao adiciona na esquerda ou direita se for -1.
void insere_arvore_aux(FILE* arq, int pos_dados, int codigo, int pos_arq){

	arvoreBMais* r = le_no_Indice(arq, pos_arq);

	int pos_vetor;

	if(!buscaPos(r, codigo, &pos_vetor)){

		if(r->eh_folha){
			adicionaDireita(r, pos_vetor, codigo, pos_dados);
			escreve_no_Arvore( arq, r, pos_arq);
		} else {
			insere_arvore_aux(	arq, pos_dados, codigo, r->ponteiro[pos_vetor]);
			arvoreBMais* filho = le_no_Indice( arq , r->ponteiro[pos_vetor] );
			if( overflow( filho ) ){
				int m;
				arvoreBMais* aux = split(arq , filho, &m, r->ponteiro[pos_vetor]);
				int pos_add = insere_arq_indice(arq , aux);
				if(filho->eh_folha){
					aux->ponteiro[ORDEM] = filho->ponteiro[ORDEM];
					filho->ponteiro[ORDEM] = pos_add;
				}
				adicionaDireita(r, pos_vetor, m, pos_add);
				escreve_no_Arvore(arq, aux, pos_add);
				escreve_no_Arvore(arq, filho, r->ponteiro[pos_vetor]);
				escreve_no_Arvore(arq, r, pos_arq);
			}
		}
	}
}
//Entrada:Arquivo binario, posicao do registro onde esta a struct e struct contendo os dados
//Saida: Nenhum
//Pre-condicao: arquivo deve ser carregado
//Pos-condicao: insere os dados do indice do arquivo
//Descricao: verifica se ha posicoes vazias para poder inserir senao adiciona na esquerda ou direita se for -1.
void insere_arvore(int codigo, int pos_dados, FILE* arq, int pos_raiz){

	int adicionado;

	insere_arvore_aux( arq, pos_dados , codigo, pos_raiz);
	
	arvoreBMais* r = le_no_Indice(arq, pos_raiz);

	if(overflow(r)){
		int m;
		arvoreBMais* x = split(arq, r, &m, pos_raiz);
		int pos_add = insere_arq_indice(arq, x);
		if(r->eh_folha){
			x->ponteiro[ORDEM] = r->ponteiro[ORDEM];
			r->ponteiro[ORDEM] = pos_add;
		}
		cabecalhoArvore* cab = le_cabecalhoArvore(arq);
		arvoreBMais* novaRaiz = (arvoreBMais*) malloc(sizeof(arvoreBMais));
		novaRaiz->codigo[0] = m;
		novaRaiz->ponteiro[0] = cab->pos_raiz;
		novaRaiz->ponteiro[1] = pos_add;
		novaRaiz->numChaves = 1;
		novaRaiz->eh_folha = 0;

		cab->pos_raiz = novaRaiz->pai = (cab->pos_livre != -1) ? cab->pos_livre : cab->pos_topo;
		r->pai = x->pai = cab->pos_raiz;

		escreve_cabecalhoArvore(arq, cab);
		escreve_no_Arvore(arq, x, pos_add);
		escreve_no_Arvore(arq, r ,pos_raiz);
		insere_arq_indice(arq, novaRaiz);

		free(x);
		free(cab);
		free(novaRaiz);
	}

	free(r);
}
//Entrada: arquivo de Indice, pos do no, pos do no pai
//Pre: arvore previamente adicionada e a posicao da raiz
//Pos: pai de cada no setado
//Varre a arvore inteira dizendo para cada no quem eh seu pai
void setPai(FILE* arq, int pos, int pos_pai){
	
	arvoreBMais* r = le_no_Indice(arq, pos);

	r->pai = pos_pai;
	escreve_no_Arvore(arq, r, pos);

	if(!r->eh_folha)
		for(int i = 0; i <= r->numChaves; i++){
			setPai(arq, r->ponteiro[i], pos);
		}
	
	free(r);
}
//Entrada: livro a ser adicionado, arquivos de indice e dados
//Pre: livro a ser inserido
//Pos: livro adicionado na arvore
//encaminha a insercao no arquivo de dados e no arquivo de indice
void insere_livro(dados_livro* livro, FILE* Indice, FILE* Dados){

	cabecalhoArvore* cab = le_cabecalhoArvore(Indice);

	int pos_dados;

	pos_dados = insere_arq_dados(Dados, livro);

	insere_arvore(livro->codigo, pos_dados, Indice, cab->pos_raiz);

	free(cab);
}
//Entrada: arquivo com livros, indice e dados
//Pre: arquivo com livros
//Pos: livros do arquivo txt inseridos nos outros 2
//Insere os livros do txt na arvore
void armazena_bibliotecaTXT(FILE* arq, FILE* Indice, FILE* Dados){
    dados_livro* livro = (dados_livro*) malloc (sizeof(dados_livro));

    char aux[20];

    while(!feof(arq)){
        fscanf(arq, "%[^;];", aux);
        livro->codigo = atoi(aux);

        fscanf(arq, "%[^;];",livro->titulo);
        retirar_espaco(livro->titulo);

        fscanf(arq, "%[^;];",livro->autor);
        retirar_espaco(livro->autor);

        fscanf(arq, "%[^\n]%*c", aux);
        livro->num_exemplares = atoi(aux);

        livro->prox.livre = -1;

		insere_livro(livro, Indice, Dados);
    }
}
//Entrada: no da arvore, codigo
//Saida: pos de uma chave
//retorna a posicao onde esta a primeira chave maior q o codigo
int SearchArray(arvoreBMais* r, int info){
	int i;

	for(i = 0; i < r->numChaves; i++)
		if(r->codigo[i] > info) return i;

	return r->numChaves;
}
//Entrada: arquivo de indice e posicao de um no
//Pre: arvore inserida
//Saida: valor de uma chave
//Retorna o valor da menor chave de um no inicial
int minimo_arvoreBMais(FILE* arq, int pos){
	arvoreBMais* r = le_no_Indice(arq, pos);

	if(r->eh_folha)
		return r->codigo[0];
	
	return minimo_arvoreBMais(arq, r->ponteiro[0]);
}
//Entrada: arquivo de indice, posicao do no, codigo
//Pre: arvore inserida
//Pos: chaves da arvore B atualizadas
//Atualizacao de todas as chaves da arvore Indice
void arruma_arvore_indice(FILE* arq, int pos){
	arvoreBMais* r = le_no_Indice(arq, pos);
	int pos_vetor;
	int i;

	if(!r->eh_folha){
		for( i = 0; i < r->numChaves ;i++){
			r->codigo[i] = minimo_arvoreBMais(arq, r->ponteiro[i+1]);
			arruma_arvore_indice(arq, r->ponteiro[i]);
		}
		escreve_no_Arvore(arq, r, pos);
		arruma_arvore_indice(arq, r->ponteiro[r->numChaves]);
	}
}
//Entrada: arquivo de indice, posiscao do no, ponteiro do pai, posicao da chave do pai
//Pre: ponteiro do pai e a chave pai
//Pos: caso possivel, arvore modificada
//Caso seja possivel(irmao tenha chaves o suficiente para empresta), empresta uma chave do irmao para manter a ordem
int empresta_irmao(FILE* arq, int pos_r, arvoreBMais* pai, int pos_vetor_pai){

	arvoreBMais* r = le_no_Indice(arq, pos_r);
	arvoreBMais* irmao_esq = le_no_Indice(arq, pai->ponteiro[pos_vetor_pai-1]);
	arvoreBMais* irmao_dir = le_no_Indice(arq, pai->ponteiro[pos_vetor_pai+1]);

	if(irmao_esq->numChaves > ORDEM/2 && pos_vetor_pai > 0){
		int last_pos = irmao_esq->numChaves-1;
		//coloca o ultimo elemento do irmao nele msm
		adicionaDireita(r, 0, irmao_esq->codigo[last_pos], irmao_esq->ponteiro[last_pos]);
		escreve_no_Arvore(arq, r, pos_r);
		//retira o elemento do irmao
		retiraDireita(irmao_esq, last_pos);
		escreve_no_Arvore(arq, irmao_esq, pai->ponteiro[pos_vetor_pai-1]);

		return 1;
	}
	if(irmao_dir->numChaves > ORDEM/2 && pos_vetor_pai < r->numChaves){
		//coloca o primeiro elemento do irmao nele msm
		adicionaDireita(r, r->numChaves, irmao_dir->codigo[0], irmao_dir->ponteiro[0]);
		escreve_no_Arvore(arq, r, pos_r);
		//retira o elemento do irmao
		irmao_dir->ponteiro[0] = irmao_dir->ponteiro[1];
		retiraDireita(irmao_dir, 0);
		escreve_no_Arvore(arq, irmao_dir, pai->ponteiro[pos_vetor_pai+1]);

		return 1;
	}
	free(r);
	free(irmao_esq);
	free(irmao_dir);

	return 0;
}
//Entrada: arquivo indice, posicao do no, posicao do irmao, posicao onde deve ser adicionado os valores de r no seu irmao, codigo
//Pre: posicoes do no, seu irmao e onde adicionar no irmao
//Pos: arvore modificada com a operacao de concatenacao
//tras todos os elementos do no q ira morrer para o irmao, caso nao seja folha, tras o do pai tbm e entao limpa os nos q sumirem
void Merge(FILE* arq, int pos_r, int pos_irmao, int lado_add, int codigo){
	arvoreBMais* r = le_no_Indice(arq, pos_r);
	arvoreBMais* irmao = le_no_Indice(arq, pos_irmao);
	arvoreBMais* pai = le_no_Indice(arq, r->pai);

	int i;
	//faz a concatenacao dos 2 irmaos
	for(i = 0; i < r->numChaves; i++){
		adicionaDireita(irmao, lado_add, r->codigo[i], r->ponteiro[i]);
		if(lado_add != 0)
			lado_add++;
	}
	
	if(lado_add != 0 && irmao->eh_folha)
		irmao->ponteiro[ORDEM] = r->ponteiro[ORDEM];
	
	int k = (lado_add == 0)? 0:1;
	int pos_pai_vetor = SearchArray(pai, codigo);
	int valor_pai = pai->codigo[pos_pai_vetor-k];
	int pos_irmao_vetor = SearchArray(irmao, valor_pai);

	//caso o no nao seja folha, o pai desce para o irmao
	if(!r->eh_folha)
		adicionaDireita(irmao, pos_irmao_vetor, valor_pai, r->ponteiro[r->numChaves]);
	
	int temp;
	if(lado_add == 0)
		for(int j = 0; j <= i; j++){
			temp = irmao->ponteiro[j+1];
			irmao->ponteiro[j+1] = irmao->ponteiro[j];
			irmao->ponteiro[j] = temp;
		}
	else
		for(int j = irmao->numChaves; j >= r->ponteiro[r->numChaves]; j--){
			temp = irmao->ponteiro[j];
			irmao->ponteiro[j] = irmao->ponteiro[j-1];
			irmao->ponteiro[j-1] = temp;
		}		
		

	retiraDireita(pai, pos_pai_vetor-1);

	escreve_no_Arvore(arq, pai, irmao->pai);
	escreve_no_Arvore(arq, irmao, pos_irmao);
	remove_arq_indice(arq, pos_r);

	cabecalhoArvore* cab = le_cabecalhoArvore(arq);
	//verifica se ele eh a raiz
	if(pai->pai == cab->pos_raiz){
		//caso ele seja a raiz, verifica se ele foi zerado
		if(pai->numChaves == 0){
			cab->pos_raiz = pos_irmao;
			remove_arq_indice(arq, irmao->pai);
			escreve_cabecalhoArvore(arq, cab);
			free(cab);
		}
	}
	
	if( irmao->pai != cab->pos_raiz && underflow(pai)){
		arvoreBMais* pai_pai = le_no_Indice(arq, pai->pai);
		int pos_vetor_pai = SearchArray(pai_pai, codigo);


		if(!empresta_irmao(arq, irmao->pai, pai_pai, pos_vetor_pai)){
			if(pos_vetor_pai > 0){
				arvoreBMais* irmao_dir = le_no_Indice(arq, pai_pai->ponteiro[pos_vetor_pai + 1]);
				lado_add = irmao_dir->numChaves-1;
				pos_irmao = pai_pai->ponteiro[pos_vetor_pai - 1];
				free(irmao_dir);
			}
			else{
				lado_add = 0;
				pos_irmao = pai_pai->ponteiro[pos_vetor_pai + 1];
			}
			Merge(arq, irmao->pai, pos_irmao, lado_add, codigo);
		}
	}

}
//Entrada: arquivo de indice, codigo, posicao da raiz
//Pre: codigo a ser removido
//Pos: codigo removido
//Saida: posicao onde o livro esta no arquivo de dados
//Faz o manejo da remocao de um codigo, (1) apenas remove sem alteracoes. (2) remove e consegue emprestar. (3) remove mas precisa concatenar
int remove_arvore_aux(FILE* arq, int codigo, int pos_raiz){
	arvoreBMais* r = le_no_Indice(arq, pos_raiz);
	int pos_vetor;//posicao da chave em uso no vetor
	int pos_r;	//posicao do no em modificacao
	
	while(!r->eh_folha){
		pos_vetor = SearchArray(r, codigo);
		pos_r = r->ponteiro[pos_vetor];
		r = le_no_Indice(arq, pos_r);
	}
	pos_vetor = SearchArray(r, codigo);

	if(r->codigo[pos_vetor-1] != codigo)
		return -1;
	
	int registro = r->ponteiro[pos_vetor-1];

	retiraDireita(r, pos_vetor-1);
	escreve_no_Arvore(arq, r, pos_r);


	if(underflow(r)){
		arvoreBMais* pai = le_no_Indice(arq, r->pai);
		int pos_vetor_pai = SearchArray(pai, codigo) ;
		arvoreBMais* irmao_dir = le_no_Indice(arq, r->ponteiro[ORDEM]);
		arvoreBMais* irmao_esq = le_no_Indice(arq, r->ponteiro[pos_vetor_pai-1]);

		if(!empresta_irmao(arq, pos_r, pai, pos_vetor_pai)){
			int lado_add, pos_irmao;

			if(pos_vetor_pai > 0){
				lado_add = irmao_dir->numChaves;
				pos_irmao = pai->ponteiro[pos_vetor_pai - 1];//irmao escolhido para o merge e da esquerda

			}
			else{
				lado_add = 0;
				pos_irmao = pai->ponteiro[pos_vetor_pai + 1];//irmao escolhido para o merge e o da direita
				irmao_esq->ponteiro[ORDEM] = r->ponteiro[ORDEM];
				escreve_no_Arvore(arq, irmao_esq, r->ponteiro[pos_vetor_pai-1]);
			}

			Merge(arq, pos_r, pos_irmao,lado_add,codigo);
		}
		
	}
	
	arruma_arvore_indice(arq, pos_raiz);
	return registro;
}
//Entrada: arquivos de indice e dados e o codigo do livro a ser removido
//Pre: codigo do livro a ser removido
//Pos: livro removido dos arquivos
//Faz as chamadas para remover o arquivo da arvore e do arquivo de dados
void remover(FILE* Indice, FILE* Dados, int codigo){

	cabecalhoArvore* cab = le_cabecalhoArvore(Indice);

	int registro = remove_arvore_aux(Indice, codigo, cab->pos_raiz);
	
	if(registro == -1){
		printf("Codigo nao encontrado\n");
		system("pause");
	}else
		remove_arq_dados(Dados, registro);
}
//Entrada: Arquivos de dados e da arvore.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Teste da impressao ordenada.
//Descricao: Exibi-se na tela os livros cadastrados e ordenados pelo codigo.
void imprime_acervo(FILE* Indice, FILE* Dados, arvoreBMais* r){

	while(!r->eh_folha){
		r = le_no_Indice(Indice, r->ponteiro[0]);
	}

	dados_livro* livro;
	printf("----------------------------\n");
	while(1){
		for(int i = 0; i < r->numChaves;i++){
			livro = le_no_Dados(Dados, r->ponteiro[i]);

				printf("Codigo.......: %d\n", livro->codigo);
				printf("Titulo.......: %s\n", livro->titulo);
				printf("Autor........: %s\n", livro->autor);
				printf("n. exemplares: %d\n", livro->num_exemplares);
				printf("----------------------------\n");
			
		}

		
		if(r->ponteiro[ORDEM] == -1) break;
		
		r = le_no_Indice(Indice, r->ponteiro[ORDEM]);
	}
}
//Entrada: arquivo, no da arvore, contador para altura
//Saida: altura da arvore
//Pre: arvore inserida
//Descricao: Devolve a altura da arvore
int altura(FILE* arq ,arvoreBMais* r, int conta){
	
	if(r->eh_folha)
		return conta;

	conta++;

	altura(arq, le_no_Indice(arq, r->ponteiro[0]), conta);

}
//Entrada: Arquivo, nivel a ser printado, contagem q comeca em 0 ate o nivel, no arvore
//Saida: Nenhuma
//Pre: arvore exista
//Descricao: imprime apenas os nos do nivel dado, ignorando os outros
void imprime_Arvore_aux(FILE* arq, int i, int conta, arvoreBMais* r){

	if(conta == i){
		printf("[");
		for(int j = 0; j < r->numChaves; j++){
			printf("%d", r->codigo[j]);
			if(j < r->numChaves-1) printf(",");
		}
		printf("] ");
		return;
	}

	conta++;
	
	for(int j = 0; j <= r->numChaves; j++)
		imprime_Arvore_aux(arq, i, conta, le_no_Indice(arq, r->ponteiro[j]));
}
//Entrada: Arquivo, dados da arvore e a posicao.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Impressao da arvore pelos codigos inseridos em niveis.
//Descricao: A partir das funcoes auxiliares, é exibido na tela os codigos em formato de arvore em niveis.
void imprimeArvore(FILE* arq, arvoreBMais* r, int pos){
	cabecalhoArvore* cab = le_cabecalhoArvore(arq);

	if(r->numChaves != 0){
		int alt = altura(arq, r, 0);

		for(int i = 0; i <= alt; i++){
			imprime_Arvore_aux(arq, i, 0, r);
			printf("\n");
		}
	}else
		printf("Arvore vazia\n");
}

//Entrada: Arquivos dos dados da biblioteca e da arvore B+.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Teste de atualizacao dos exemplares cadastrados.
//Descricao: A partir do codigo do livro, o usuario atualiza o numero de exemplares disponiveis na biblioteca.
void atualizar_exemplares(FILE* arqDados, FILE* arqArv) {
  int cod_buscar, escolha,i;
    int cont=0;

    printf("Insira aqui o codigo do livro que deseja atualizar:");
    scanf("%d", &cod_buscar);

    cabecalhoArvore *cab = le_cabecalhoArvore(arqArv);
    int pos_aux = cab->pos_raiz;
    arvoreBMais *r = le_no_Indice(arqArv, pos_aux);
    dados_livro* livro = le_no_Dados(arqDados,r->ponteiro[ORDEM]);

    while(!r->eh_folha){
        r = le_no_Indice(arqArv, r->ponteiro[0]);
    }

    while(1){
		for ( i = 0; i < r->numChaves; i++){
			livro = le_no_Dados(arqDados,r->ponteiro[i]);
			if(cod_buscar == r->codigo[i]){
				printf("Numero de exemplares: %d\n", livro->num_exemplares);
				printf("\nNovo numero de exemplares:");
				scanf("%d", &livro->num_exemplares);
				escreve_no_Dados(arqDados,livro,r->ponteiro[i]);
				cont = 1;
			}

		}

		if(r->ponteiro[ORDEM] == -1) break;

		r = le_no_Indice(arqArv, r->ponteiro[ORDEM]);
    }
    
	if(cont == 0) printf("Livro nao encontrado!\n\n");
}

//Entrada: Arquivos dos dados da biblioteca e da arvore B+.
//Saida: Nenhuma.
//Pre-Condicao: Arquivo carregado.
//Pos-Condicao: Retorna os dados buscados.
//Descricao: A partir do codigo, � feita a busca e retorna os dados do livro.
void buscar_dadosLivro(FILE* arqDados,FILE *arqArv){
    int cod_buscar, escolha,i;
    int cont=0;

    printf("Insira aqui o codigo do livro que deseja buscar:");
    scanf("%d", &cod_buscar);

    cabecalhoArvore *cab = le_cabecalhoArvore(arqArv);
    int pos_aux = cab->pos_raiz;
    arvoreBMais *r = le_no_Indice(arqArv, pos_aux);
    dados_livro* livro = le_no_Dados(arqDados,r->ponteiro[ORDEM]);

    while(!r->eh_folha){
        r = le_no_Indice(arqArv, r->ponteiro[0]);
    }

    while(1){
        for ( i = 0; i < r->numChaves; i++){
            livro = le_no_Dados(arqDados,r->ponteiro[i]);
            if(cod_buscar == r->codigo[i]){
                printf("Codigo: %d\n", livro->codigo);
                printf("Titulo: %s\n", livro->titulo);
                printf("Autor: %s\n", livro->autor);
                printf("Numero de exemplares: %d\n\n", livro->num_exemplares);
                cont = 1;
				system("pause");
            }

        }

        if(r->ponteiro[ORDEM] == -1) break;

        r = le_no_Indice(arqArv, r->ponteiro[ORDEM]);
    }
    if(cont == 0) printf("Livro nao encontrado!\n\n");

}