#include <stdlib.h>
#include <string.h>
#include "terreno.h"
#include "talhao.h"
#include "tuplo.h"

#define CONSAASD 100

struct _terreno {
    int colunas;
    int linhas;
    talhao ** talhoes;
    tuplo equipas;
};

terreno criaTerreno(int l , int c , int** tesouro) {

    int i,j;

    terreno t = (terreno) malloc(sizeof(struct _terreno));
    t->colunas = c;
    t->linhas = l;

    t->talhoes = (talhao **) malloc (sizeof(talhao*) *l);

    for (i = 0; i < l ; i++) {
       t->talhoes[i] = (talhao*)malloc(sizeof(talhao)*c);
    }
    
    t->equipas = (tuplo) malloc (sizeof(tuplo));


    for(i = 0; i < l ; i++)
        for(j = 0; j < c ; j++)
            t->talhoes[i][j] = criaTalhao(tesouro[i][j]);
    return t;
}

int riquezaTerreno(terreno t){
    
    int riqueza=0;

    for(int i = 0; i < t->colunas ; i++)
        for(int j = 0; j < t->linhas ; j++)
         riqueza = riqueza + riquezaTalhao(t->talhoes[i][j]);

    return riqueza;     

}

int estadoTerreno(terreno t,int i,int j){
    
    return estadoTalhao(t->talhoes[i][j]);
}

int linhasTerreno(terreno t){
    return t->linhas;
}

int colunasTerreno(terreno t){
    return t->colunas;
}