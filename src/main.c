#include <stdio.h>
#include <stdlib.h>





int main (int argc, char *argv[]){
    
    FILE *fp = fopen("/home/juaumpc/Dev/SO/TP2/Simulador-de-Memoria-Virtual/Arquivos Complementares/Entradas_TP2_2017/compilador.log","r");
    
    if(fp == NULL){
        printf("erro na abertura do arquivo");
    }


    while(!feof(fp)){
        
        unsigned addr;
        char rw;
        fscanf(fp,"%x %c", &addr,&rw);
        printf("%x %c\n",addr,rw);

        switch(&argv[1]):
            
            case "lru":


    }




    return 0;
}