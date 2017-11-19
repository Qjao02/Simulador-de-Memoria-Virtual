#ifndef TABELA_H
#define TABELA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pagina{
	char presente;
	unsigned int moldura;
} pagina;

typedef struct tabela{
	unsigned int num_entradas;
	pagina *paginas;
} tabela;

typedef struct moldura{
	pagina *pagina;
	unsigned int ultimo_acesso; //Os clocks podem ser considerados como a colocação da intrução lida
	unsigned int _carregamento; //O instante de carregamento para a memória
	char pagina_modificada;
} moldura;

typedef struct memoria_processo{
	unsigned int num_entradas;
	moldura *molduras;
} memoria_processo;

#ifdef __cplusplus
}
#endif

#endif /* TABELA_H */
