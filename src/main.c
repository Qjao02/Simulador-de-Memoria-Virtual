#include <stdio.h>
#include <stdlib.h>
#include "tabela.c"
#include "uteis.c"
#include "algoritmos.c"

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

  	//Verificando se a política de substituição é válida
  	if(!algoritmo_valido(algoritmo_substituicao)){
  			printf("Política de substituição inválida!\n");
  			return 0;
  	}


    //Verificando se os tamanhos de pagina e memória são válidos
  	if((tamanho_pagina % 2 || tamanho_pagina <= 0)){
  		printf("Tamano da página especificada é inválido\n");
  		return 0;
  	}
  	if((tamanho_memoria % 2 || tamanho_memoria <= 0)){
  		printf("Tamanho da memória especificada é inválido\n");
  		return 0;
  	}


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
    int pageFault = 0;

    while(fscanf(arquivo,"%x %c\n",&tmpPOS,&tmpOP) != EOF){
        indice = tmpPOS%tabela->num_entradas;
        //achei a pagina, agora vou acessar o conteudo dela
        if(tabela->paginas[indice].presente){
            //pagina esta na memoria principal e seu endereço é a moldura com o deslocamento

        }else{
            //pagina nao esta na memoria principal
            pageFault++;
            /*inventar uma pagina e substituir usando o algoritmo de substituicao*/
            //pagina criada
            //pagina *p = malloc(sizeof(pagina));
            //p->moldura = p->presente = 1;

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
