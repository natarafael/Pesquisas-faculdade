#ifndef STRUCTS_H
#define STRUCTS_H

#define ORDEM 5
#define MAX 100


typedef struct {

    int pos_raiz; 
    int pos_topo; 
    int pos_livre; 

}cabecalhoArvore;


typedef struct arvoreBMais{

    int codigo[ORDEM]; // vetor de chaves
    int ponteiro[ORDEM + 1]; // vetor de ponteiros
    int pai; // ponteiro para o no-pai
    int eh_folha; // diz se o no eh folha
    int numChaves; // numero de chaves no no

}arvoreBMais;



typedef struct cabecalho_dados{

    int pos_topo; 
    int pos_livre;

}cabecalho_dados;


typedef struct no{

    int livre;

}lista;


typedef struct dados_livro{

    int codigo;
    char titulo[MAX];
    char autor[MAX];
    int num_exemplares;
    lista prox;

}dados_livro;

#endif