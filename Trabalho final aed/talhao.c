#include <stdlib.h>
#include <string.h>
#include "talhao.h"

#define CONS 100

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

int riquezaTalhao(talhao ta){
    return ta->tesouro;
}

int estadoTalhao(talhao ta){
    if(ta->tesouro == 0)
        return 0;
    return 1;     
}