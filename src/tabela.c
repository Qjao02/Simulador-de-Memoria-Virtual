#include "tabela.h"

/*
Este arquivo será responsavel por implementar funções referentes a tabela de páginas.
*/

void criaTabela(tabela *tabela,int tamanho_pagina){
	tabela->num_entradas = 4194304/tamanho_pagina; //os enderecos fornecidos sao de 32 bits, logo temos 544288kb mapeados
    tabela->paginas = (pagina*) malloc(sizeof(pagina)*tabela->num_entradas);
    for(int i=0;i<tabela->num_entradas;i++){
    	tabela->paginas[i].presente = 0;
    	tabela->paginas[i].moldura = 0;
    }
}

void criaMoldura(moldura *moldura,int tamanho_moldura){
	moldura->num_entradas = tamanho_moldura;
	moldura->blocos = (bloco_moldura*) malloc(sizeof(bloco_moldura)*tamanho_moldura);
	for(int i=0;i<tamanho_moldura;i++){
		moldura->blocos[i].pagina = NULL;		
	}
}