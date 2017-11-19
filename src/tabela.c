#include "tabela.h"
#include <math.h>
/*
Este arquivo será responsavel por implementar funções referentes a tabela de páginas.
*/

void criaTabela(tabela *tabela, int tamanho_pagina){
	tabela->num_entradas = 4194304 / tamanho_pagina; //os enderecos fornecidos sao de 32 bits, logo temos 544288kb mapeados 
    tabela->paginas = (pagina*) malloc(sizeof(pagina) * tabela->num_entradas);
    for(int i = 0; i < tabela->num_entradas; i++){
    	tabela->paginas[i].presente = 0;
		tabela->paginas[i].moldura = 0;
		tabela->paginas[i].endereco_virtual_base = -1;
    }
}

void criaMemoriaProcesso(memoria_processo *memoria_processo, int tamanho_processo){
	memoria_processo->num_entradas = tamanho_processo;
	memoria_processo->molduras = (moldura*) malloc(sizeof(moldura)*tamanho_processo);
	for(int i=0;i<tamanho_processo;i++){
		memoria_processo->molduras[i].pagina = NULL;
		memoria_processo->molduras[i].pagina_modificada = 0;		
	}
}