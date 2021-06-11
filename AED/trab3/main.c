#include "arquivos.h"
#include "menus.h"
#include "modelo.h"


int main(int args, char* argv[]){
    int x;

    char nome_arq[MAX];
    
    FILE* f;
    FILE* Indice   = fopen("INDICE.bin", "wb+");
    FILE* Dados    = fopen("DADOS.bin", "wb+");

    criaIndice(Indice);
    cria_arquivo_Dados(Dados);

    printf("Digite 1 para carregar um arquivo txt.\n");
    printf("Digite 2 para ir ao menu de manipulacao da arvore.\n");
    printf("Digite 0 para encerrar o programa.\n");



    scanf("%d%*c", &x);

    while(x != 0){
        
        if(x == 1){

            printf("Digite o nome do arquivo txt.\n");

            scanf("%[^\n]%*c", nome_arq);

            f = fopen(nome_arq, "r");
            
            if(f != NULL){

                armazena_bibliotecaTXT(f, Indice, Dados);

				printf("Arquivo lido com sucesso.\n");

            }
            else{

                printf("Erro ao abrir o arquivo.\n");

                

            }

            system("cls");

        }
        
        if(x == 2){

            int Escolha;

           do{

                Escolha = menu_cadastro();

                Encaminha(Escolha, Indice, Dados);

            }while(Escolha);
        }

    printf("Digite 1 para carregar um arquivo txt.\n");
    printf("Digite 2 para ir ao menu de manipulacao da arvore.\n");
    printf("Digite 0 para encerrar o programa.\n");



    scanf("%d%*c", &x); 

	system("cls");

    }

    return 0;
}