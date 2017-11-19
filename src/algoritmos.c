#include "algoritmos.h"
#include "tabela.h"

/*
A função fifo_escolha vai me retornar o indice que deve ser inserido ou substituido baseado no algoritmo fifo
*/
int fifo_escolha(memoria_processo *memoria_processo, unsigned int pulso_clock_atual){
	int escolha;
	int primeiro_acesso = pulso_clock_atual;
	for(int i=0; i<memoria_processo->num_entradas; i++){
		if(memoria_processo->molduras[i]._carregamento < primeiro_acesso){
			escolha = i;
			primeiro_acesso = memoria_processo->molduras[i]._carregamento;
		}
	}
	return escolha;
}

int lru_escolha(memoria_processo *memoria_processo, unsigned int pulso_clock_atual){
	int escolha;
	int ultimo_acesso = pulso_clock_atual;
	for(int i=0; i<memoria_processo->num_entradas; i++){
		if(memoria_processo->molduras[i].ultimo_acesso < ultimo_acesso){
			escolha = i;
			ultimo_acesso = memoria_processo->molduras[i].ultimo_acesso;
		}
	}
	return escolha;
}

int random_escolha(unsigned int num_entradas){
	return rand() % num_entradas;
}
