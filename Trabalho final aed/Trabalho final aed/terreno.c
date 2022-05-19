#include <stdlib.h>
#include <string.h>

#include "terreno.h"
#include "talhao.h"
#include "dicOrdenado.h"
#include "equipa.h"

#define CONSAASD 100
#define ZERO 0
#define UM 1
#define NUMEQUIPAS 10

struct _terreno {
    int colunas;
    int linhas;
    talhao ** talhoes;      
    dicOrdenado equipasPorNum;
    dicOrdenado equipasPorNom;
   
};

terreno criaTerreno(int l , int c , int tesouro[l][c]){

    int i,j;

    terreno t = (terreno) malloc(sizeof(struct _terreno));
    t->colunas = c;
    t->linhas = l;

    t->talhoes = (talhao **) malloc (sizeof(talhao*) *l);

    for (i = 0; i < l ; i++) {
       t->talhoes[i] = (talhao*)malloc(sizeof(talhao)*c);
    }
    
    t->equipasPorNum = criaDicOrdenado(NUMEQUIPAS,ZERO);
    t->equipasPorNom = criaDicOrdenado(NUMEQUIPAS,UM);

    for(i = 0; i < l ; i++)
        for(j = 0; j < c ; j++)
            t->talhoes[i][j] = criaTalhao(tesouro[i][j]);
    
    return t;
}
void destroiTerreno(terreno t){
    int i,j;

    for(i = 0; i < t->linhas ; i++)
        for(j = 0; j < t->colunas ; j++)
            destroiTalhao(t->talhoes[i][j]);  
            
    for (i = 0; i < t->linhas ; i++) {
       free(t->talhoes[i]);
    }

    free(t->talhoes);
    destroiDicOrdEElems(t->equipasPorNum,destroiEquipaGen);
    destroiDicOrdEElems(t->equipasPorNom,destroiEquipaGen);
    free(t);
    return;

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

void adicionarEquipaDicOrdenadoPorNomTerreno(char *nome_equipa,terreno t){
    
    adicionaElemDicOrdenado(t->equipasPorNom,nome_equipa ,criaEquipa(nome_equipa)); 
}
void adicionarEquipaDicOrdenadoPorNumTerreno(char *nome_equipa,int nr_equipa,terreno t){
    
    adicionaElemDicOrdenado(t->equipasPorNom,&nr_equipa ,criaEquipa(nome_equipa)); 
}
void adicionaArqueologoEquipaTerreno(char *nomeArqueologo,int n_equipa,terreno t){

adicionaArqueologoEquipa(criaArqueologo(nomeArqueologo),elementoDicOrdenado(t->equipasPorNum,n_equipa));
}