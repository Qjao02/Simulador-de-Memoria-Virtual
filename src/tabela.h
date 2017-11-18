#ifndef TABELA_H
#define TABELA_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct pagina{
	int presente;
	int moldura;
} pagina;

typedef struct tabela{
	unsigned int num_entradas;
	pagina *paginas;
} tabela;

typedef struct bloco_moldura{
	pagina *pagina;
	clock_t ultimo_acesso;
	int pagina_alterada;
} bloco_moldura;

typedef struct moldura{
	unsigned int num_entradas;
	bloco_moldura *blocos;
} moldura;

#ifdef __cplusplus
}
#endif

#endif /* TABELA_H */
