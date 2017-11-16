#include <stdio.h>
#include <stdlib.h>
#include "tabela.c"

int main (int argc, char *argv[]){
    
    if(argc != 5){
        printf("Formato de entrada inválido.\n");
        return 1;
    }

    /*
    --------------------------------------------------------
    |           LEITURA DOS PARAMETROS INICIAIS            |
    --------------------------------------------------------
    */
    char *algoritmo_substituicao = argv[1];
    char *arquivo_entrada = argv[2];
    int tamanho_pagina = atoi(argv[3]);
    int tamanho_memoria = atoi(argv[4]);
    
    /*
    Abertura e controle dos parametros de entrada
    */
    FILE *arquivo = fopen(arquivo_entrada,"r");

    if(arquivo == NULL){
        printf("Arquivo de entrada não pode ser aberto\n");
        return 1;
    }

    
    //[TODO]CRIAR AQUI VERIFICAÇÃO SE O ALGORITIMO DE SUBSTITUIÇÃO É CORRETO
    //[TODO] VERIFICAR TAMANHO PAGINA E TAMANHO DA MEMORIA



    /*
    Criar a tabela de páginas de acordo com o tamanho especificado.
    */    
    tabela *tabela;

    criaTabela(tabela,tamanho_pagina);

    
    /*
    leitura dos acessos.
    */
    int tmpPOS;
    char tmpOP;

    int indice;


    int pageFaut = 0;
    

    while(fscanf(arquivo,"%x %c\n",&tmpPOS,&tmpOP) != EOF){
        indice = tmpPOS%tabela->num_entradas;
        //achei a pagina, agora vou acessar o conteudo dela
        if(tabela->paginas[indice].presente){
            //pagina esta na memoria principal e e seu endereço é a moldura com o deslocamento
            
        }else{
            //pagina nao esta na memoria principal
            pageFaut++;
            //inventar uma pagina e substituir usando o algoritmo de substituicao
            printf("%s\n",algoritmo_substituicao );
            if(algoritmo_substituicao == "fifo" || algoritmo_substituicao == "FIFO"){
                printf("FIFO\n");
            }

        }
        //printf("%d\n", indice);
        //break;
    }




    
    return 0;
}