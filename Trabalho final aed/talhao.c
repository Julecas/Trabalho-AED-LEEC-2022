#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "talhao.h"

#define MULT_PENALIZACAO -10

struct _talhao {
    int tesouro;
    int nEscavacoes;
};

talhao criaTalhao(int tesouro) {
talhao ta = (talhao) malloc(sizeof(struct _talhao)); 
ta->tesouro = tesouro;
ta->nEscavacoes = 0;
return ta;     
}
void destroiTalhao(talhao ta){
    free(ta);    
}

int riquezaTalhao(talhao ta){  
    return ta->tesouro;
}

int estadoTalhao(talhao ta){
    if(ta->tesouro == 0)
        return 0;
    return 1;     
}

int escavarTalhao(talhao ta) {
    //printf("A escavar talhão com %d de tesouro!\n",ta->tesouro);
    int pontosADar;
    if (ta->tesouro) {
        pontosADar = ta->tesouro;
        ta->tesouro = 0;
        ta->nEscavacoes++;
        return pontosADar;
    }
    else {
        if (!(ta->nEscavacoes)) {
            ta->nEscavacoes++;
            return 0;
        }
        else {
            pontosADar = ta->nEscavacoes * MULT_PENALIZACAO;
            ta->nEscavacoes++;
            return pontosADar;
        }
    }
}