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





#ifdef __cplusplus
}
#endif

#endif /* TABELA_H */
