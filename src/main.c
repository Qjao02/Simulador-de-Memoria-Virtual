#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.c"
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
    int pulso_clock = 0;
	
	//Função interna para validação do algorítmo recebido por parametro em main()
	int algoritmo_valido(){
		if(!strcmp("fifo", algoritmo_substituicao)) return 1;
		if(!strcmp("FIFO", algoritmo_substituicao)) return 1;
		if(!strcmp("lru", algoritmo_substituicao)) return 1;
		if(!strcmp("LRU", algoritmo_substituicao)) return 1;
		if(!strcmp("random", algoritmo_substituicao)) return 1;
		if(!strcmp("RANDOM", algoritmo_substituicao)) return 1;
		return 0;
	}
	
	
    /*
    Abertura e controle dos parametros de entrada
    */
    FILE *arquivo = fopen(arquivo_entrada,"r");

    if(arquivo == NULL){
        printf("Arquivo de entrada não pode ser aberto\n");
        return 1;
    }

  	//Verificando se a política de substituição é válida
  	if(!algoritmo_valido()){
  			printf("Política de substituição inválida!\n");
  			return 0;
  	}


    //Verificando se os tamanhos de pagina e memória são válidos
  	if((tamanho_pagina % 2 || tamanho_pagina <= 0)){
  		printf("Tamano da página especificada é inválido\n");
  		return 0;
  	}
	if(tamanho_pagina < 2 || tamanho_pagina > 64){
		printf("O tamanho da página não é rasoável para a execução, entre com valor | 2 <= x <= 64");
		return 0;
	}
  	if((tamanho_memoria % 2 || tamanho_memoria <= 0)){
  		printf("Tamanho da memória especificada é inválido\n");
  		return 0;
  	}
	if(tamanho_memoria < 128 || tamanho_memoria > 16384){
		printf("O tamanho da memória disponível para o processo não é rasoável para a execução, entre com valor | 128 <= x <= 16384");
		return 0;
	}


    /*
    Criar a tabela de páginas de acordo com o tamanho especificado.
    */
    tabela tabela;
    criaTabela(&tabela, tamanho_pagina);
    
    /*
    Aloca memória para o processo
    */
    memoria_processo memoria_processo;
    criaMemoriaProcesso(&memoria_processo, tamanho_memoria);

    /*
    leitura dos acessos.
    */
    unsigned int tmpPOS;
    char tmpOP;
    int tamanho_pagina_real = tamanho_pagina * pow(2, 10); //tamanho da página em bytes

    unsigned int indice;
    unsigned int pageFault = 0;
    unsigned int paginas_lidas = 0;
    unsigned int paginas_escritas = 0;

    printf("Executando simulador ...\n");

    while(fscanf(arquivo,"%x %c\n", &tmpPOS, &tmpOP) != EOF){
        pulso_clock++;
        //incrementa o número de instruções lidas (semelhante aos pulsos de clock)
        indice = tmpPOS % tabela.num_entradas;
        //achei a pagina, agora vou acessar o conteudo dela
        paginas_lidas += tmpOP == 'R' ? 1 : 0;
        paginas_escritas += tmpOP == 'W' ? 1 : 0;
        if(tabela.paginas[indice].presente){
            //pagina esta na memoria principal e seu endereço é a moldura
            //redefinindo último acesso
            memoria_processo.molduras[tabela.paginas[indice].moldura].ultimo_acesso = pulso_clock;
            //página modificada
            memoria_processo.molduras[tabela.paginas[indice].moldura].pagina_modificada = tmpOP == 'W' ? 1 : 0; 
        }else{
            //pagina nao esta na memoria principal
            pageFault++;
            unsigned int indice_moldura;
            if(!strcmp("fifo", algoritmo_substituicao) || !strcmp("FIFO", algoritmo_substituicao)){
                //fifo, me dê a posição da moldura que eu possa fazer a substituição
                indice_moldura = fifo_escolha(&memoria_processo, pulso_clock);
            }else if(!strcmp("lru", algoritmo_substituicao) || !strcmp("LRU", algoritmo_substituicao)){
                //lru, me dê a posição da moldura que eu possa fazer a substituição
                indice_moldura = lru_escolha(&memoria_processo, pulso_clock);
            }else if(!strcmp("random", algoritmo_substituicao) || !strcmp("RANDOM", algoritmo_substituicao)){
                 //random, me dê a posição da moldura que eu possa fazer a substituição
                indice_moldura = random_escolha(memoria_processo.num_entradas);
            }
            //a página que ocupava esta moldura não está mais presente
            if(memoria_processo.molduras[indice_moldura].pagina){
                memoria_processo.molduras[indice_moldura].pagina->presente = 0;
                memoria_processo.molduras[indice_moldura].pagina_modificada = 0;
            }
            //a página referenciada pelo endereço agora esta presente
            tabela.paginas[indice].presente = 1;
            //a moldura recebe a página e atualiza seus temporizadores
            memoria_processo.molduras[indice_moldura].pagina = &tabela.paginas[indice];
            memoria_processo.molduras[indice_moldura]._carregamento = pulso_clock;
            memoria_processo.molduras[indice_moldura].ultimo_acesso = pulso_clock;

        }
    }

    printf("Arquivo de entrada: %s\n", arquivo_entrada);
    printf("Tamanho da memoria: %d KB\n", tamanho_memoria);
    printf("Tamanho das páginas: %d KB\n", tamanho_pagina);
    printf("Tecnica de substiuição: %s\n", algoritmo_substituicao);
    printf("Páginas lidas: %d\n", paginas_lidas);
    printf("Paginas escritas: %d\n", paginas_escritas);
    printf("Faltas de pagina: %d\n\n", pageFault);

    return 0;
}
