#include "menus.h"
#include "modelo.h"
#include "structs.h"
#include "arquivos.h"

#include <stdio.h>
#include <stdlib.h>

//Menu com opcoes de alteracoes na biblioteca
//retorna o valor referente a escolha feita pelo usuario
int menu_cadastro(){


    printf("Escolha uma opcao.\n");
    printf("Digite 1 para inserir um livro na arvore.\n");
    printf("Digite 2 para remover um livro na arvore.\n");
    printf("Digite 3 para atualizar o numero de exemplares de um livro na arvore.\n");
    printf("Digite 4 para buscar os dados de um livro a partir de seu codigo.\n");
    printf("Digite 5 para imprimir o acervo.\n");
    printf("Digite 6 para imprimir a arvore.\n");
    printf("Digite 0 para voltar a tela anterior de escolha.\n");

    int escolha;

    scanf("%d%*c", &escolha);

    system("cls");

    return escolha;
}

//Com a escolha passada, encaminha o usuario para a funcao da opcao desejada
//Param Escolha para a funcao encaminhada arquivos de dados e indice, para repassar para as funcoes caso precisem
//Pre Escolha ja feita, arquivos inicializados
//Pos alguma modificao na arvore
void Encaminha(int Escolha, FILE* Indice, FILE* Dados){
    cabecalhoArvore* cab = le_cabecalhoArvore(Indice);
    dados_livro* livro = malloc(sizeof(dados_livro));
    int codigo;

    switch(Escolha){
        case 1:
            menu_insere(livro);
            
            insere_livro(livro, Indice, Dados);

            system("pause");
            break;
        case 2:
            codigo = menu_remover();
            setPai(Indice, cab->pos_raiz, cab->pos_raiz);
            remover(Indice, Dados, codigo);
            break;
        case 3:

            atualizar_exemplares(Dados, Indice);

            break;
        case 4:

            buscar_dadosLivro( Dados, Indice);

            break;
        case 5:
            imprime_acervo(Indice , Dados ,le_no_Indice(Indice,cab->pos_raiz));

            system("pause");
            break;
        case 6:
            imprimeArvore(Indice, le_no_Indice(Indice,cab->pos_raiz), cab->pos_raiz);

            system("pause");
            break;
        
    }

    free(cab);
    free(livro);

    system("cls");
}

//Menu rapido para escolher o codigo de remocao
//retorno codigo a ser removido
int menu_remover(){
    int codigo;
    printf("Digite o codigo do livro que deseja remover\n>");
    scanf("%d%*c", &codigo);
    return codigo;
}

//Menu rapido, para armazenar os dados do livro a ser armazenado
//Param ponteiro para o livro q vai ser inserido
//Pre alocado a memorio do ponteiro livro
//Pos ponteiro com livro preenchido
void menu_insere(dados_livro* livro){

    printf("Digite o codigo do livro:\n");
    scanf("%d%*c", &livro->codigo);

    printf("Digite o Titulo do livro:\n");
    scanf("%[^\n]%*c", livro->titulo);

    printf("Digite o nome do Autor:\n");
    scanf("%[^\n]%*c", livro->autor);

    printf("Digite o numero de exemplares:\n");
    scanf("%d%*c", &livro->num_exemplares);

    livro->prox.livre = -1;
}