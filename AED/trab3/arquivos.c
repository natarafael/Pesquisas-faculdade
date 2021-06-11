#include "arquivos.h"

//Abre o arquivo, guarda a informacao que contem na primeira linha do arquivo[cabecalho] e entao o retorna
//parametro: arquvio a ser aberto
//pre: arquivo ja deve ter sido inicializado com as informacoes e o seu cabecalho deve ser do tipo correto
cabecalhoArvore* le_cabecalhoArvore(FILE* arq) {
    cabecalhoArvore * cab = (cabecalhoArvore*) malloc(sizeof(cabecalhoArvore));
    fseek(arq,0,SEEK_SET);
    fread(cab,sizeof(cabecalhoArvore),1,arq);
    return cab;
}

//Escreve a struct na primeira linha [cabecalho] do arquivo
//Parametro: arquivo a ser aberto
void escreve_cabecalhoArvore(FILE* arq, cabecalhoArvore* cab){
    fseek(arq,0,SEEK_SET);
    fwrite(cab,sizeof(cabecalhoArvore),1,arq);
}

//Inicializa o cabecalho do arquivo
//Parametro: arquivo a ser inicializado
void criaIndice(FILE* arq){
    cabecalhoArvore * cab = (cabecalhoArvore*) malloc(sizeof(cabecalhoArvore));
    cab->pos_raiz = 0;
    cab->pos_topo = 1;
    cab->pos_livre = -1;

    //cria um no ja na criacao do arquivo
    arvoreBMais* no = (arvoreBMais*) malloc(sizeof(arvoreBMais));
    no->eh_folha = 1;
    no->pai = 0;
    no->numChaves = 0;
    no->ponteiro[ORDEM] = -1;

    escreve_no_Arvore(arq, no, 0);
    escreve_cabecalhoArvore(arq,cab);
    free(cab);
    free(no);
}

//Retorna uma struct com o conteudo da pos informada
//Parametro: arquivo a ser aberto e a pos onde deve abrir
//Pre: posicao deve ser uma posicao valida
arvoreBMais* le_no_Indice(FILE* arq, int pos){
    arvoreBMais* x = (arvoreBMais*) malloc(sizeof(arvoreBMais));
    fseek(arq,sizeof(cabecalhoArvore) + pos * sizeof(arvoreBMais),SEEK_SET);
    fread(x,sizeof(arvoreBMais),1,arq);
    return x;
}

//Escreve no arquivo a informacao contida na struct na posicao informada
//Parametro: arquivo a ser aberto, struct com a informacao e a pos onde deve ser escrito
//Pre: arquivo valido, uma struct com informacoes e a posicao valida
//Pos: arquivo sera escrito ou sobrescrito com as informcoes obtidas
void escreve_no_Arvore(FILE* arq, arvoreBMais* x, int pos){
    fseek(arq,sizeof(cabecalhoArvore) + pos * sizeof(arvoreBMais),SEEK_SET);
    fwrite(x,sizeof(arvoreBMais),1,arq);
}

//Abre o arquivo, guarda a informacao que contem na primeira linha do arquivo[cabecalho] e entao o retorna
//parametro: arquvio a ser aberto
//pre: arquivo ja deve ter sido inicializado com as informacoes e o seu cabecalho deve ser do tipo correto
cabecalho_dados* le_cabecalho_Dados(FILE * arq) {
    cabecalho_dados * cab = (cabecalho_dados*) malloc(sizeof(cabecalho_dados));
    fseek(arq,0,SEEK_SET);
    fread(cab,sizeof(cabecalho_dados),1,arq);
    return cab;
}

//Escreve a struct na primeira linha [cabecalho] do arquivo
//Parametro: arquivo a ser aberto
void escreve_cabecalho_Dados(FILE* arq, cabecalho_dados* cab){
    fseek(arq,0,SEEK_SET);
    fwrite(cab,sizeof(cabecalho_dados),1,arq);
}

//Inicializa o cabecalho do arquivo
//Parametro: arquivo a ser inicializado
void cria_arquivo_Dados(FILE* arq){
    cabecalho_dados* cab = (cabecalho_dados*) malloc(sizeof(cabecalho_dados));
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho_Dados(arq,cab);
    free(cab);
}

//Retorna uma struct com o conteudo da pos informada
//Parametro: arquivo a ser aberto e a pos onde deve abrir
//Pre: posicao deve ser uma posicao valida
dados_livro* le_no_Dados(FILE* arq, int pos) {
    dados_livro* x = (dados_livro*)malloc(sizeof(dados_livro));
    fseek(arq,sizeof(cabecalho_dados) + pos * sizeof(dados_livro),SEEK_SET);
    fread(x,sizeof(dados_livro),1,arq);
    return x;
}

//Escreve no arquivo a informacao contida na struct na posicao informada
//Parametro: arquivo a ser aberto, struct com a informacao e a pos onde deve ser escrito
//Pre: arquivo valido, uma struct com informacoes e a posicao valida
//Pos: arquivo sera escrito ou sobrescrito com as informcoes obtidas
void escreve_no_Dados(FILE* arq, dados_livro* x, int pos){
    fseek(arq,sizeof(cabecalho_dados) + pos * sizeof(dados_livro),SEEK_SET);
    fwrite(x,sizeof(dados_livro),1,arq);
}
//Entrada:Arquivo binario, posicao valida e struct contendo os dados do livro
//Saida: Nenhuma
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
//Descricao: Insere os dados da biblioteca no arquivo
int insere_arq_dados(FILE* arq , dados_livro* livro){

	cabecalho_dados* cab = le_cabecalho_Dados(arq);

	int pos_add;

	if(cab->pos_livre != -1){
		pos_add = cab->pos_livre;
		dados_livro* aux = le_no_Dados(arq, cab->pos_livre);
		cab->pos_livre = aux->prox.livre;
		free(aux);
	}else
		pos_add = cab->pos_topo++;

	escreve_no_Dados(arq, livro, pos_add);
	escreve_cabecalho_Dados(arq, cab);

	free(cab);

	return pos_add;
}
//Entrada:Arquivo binario, posicao valida e struct contendo os dados da arvore
//Saida: Posicao adicionada
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
//Descricao: Insere os dados da arvore no arvore
int insere_arq_indice(FILE* arq, arvoreBMais* r){

	cabecalhoArvore* cab = le_cabecalhoArvore(arq);

	int pos_add;

	if(cab->pos_livre != -1){ 
		pos_add = cab->pos_livre;
		arvoreBMais* aux = le_no_Indice(arq , cab->pos_livre);
		cab->pos_livre = aux->ponteiro[0];
		free(aux);
	}else
		pos_add = cab->pos_topo++;

	escreve_no_Arvore(arq, r, pos_add);
	escreve_cabecalhoArvore(arq, cab);

	free(cab);

	return pos_add;
}

//Entrada: arquivo de indice, posicao do no
//Pre: posicao do no a ser removido
//Pos: posicao livre do cabecalho atualizada
//Libera um no do arquivo
void remove_arq_indice(FILE* arq, int pos){
    
    cabecalhoArvore* cab = le_cabecalhoArvore(arq);
	arvoreBMais* aux = le_no_Indice(arq, pos);

	aux->ponteiro[0] = cab->pos_livre;
	cab->pos_livre = pos;

	escreve_cabecalhoArvore(arq, cab);
	escreve_no_Arvore(arq, aux, pos);

	free(aux);
	free(cab);
}
//Entrada: arquivo de dados, posicao do livro
//Pre: posicao do no a ser removido
//Pos: posicao livre do cabecalho atualizada
//Libera um no do arquivo
void remove_arq_dados(FILE* arq, int pos_registro){

	cabecalho_dados* cab = le_cabecalho_Dados(arq);
	dados_livro* aux = le_no_Dados(arq, pos_registro);

	aux->prox.livre = cab->pos_livre;
	cab->pos_livre = pos_registro;

	escreve_cabecalho_Dados(arq, cab);
	escreve_no_Dados(arq, aux, pos_registro);

	free(aux);
	free(cab);
}