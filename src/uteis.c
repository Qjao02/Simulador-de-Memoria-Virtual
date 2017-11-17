#include "uteis.h"
#include <string.h>

int algoritmo_valido(char *algoritmo){
    if(!strcmp("fifo", algoritmo)) return 1;
    if(!strcmp("FIFO", algoritmo)) return 1;
    if(!strcmp("lru", algoritmo)) return 1;
    if(!strcmp("LRU", algoritmo)) return 1;
    if(!strcmp("random", algoritmo)) return 1;
    if(!strcmp("RANDOM", algoritmo)) return 1;
    return 0;
}
