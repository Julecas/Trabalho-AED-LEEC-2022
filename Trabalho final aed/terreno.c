#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "terreno.h"
#include "talhao.h"
#include "dicOrdenado.h"
#include "equipa.h"

#define CONSAASD 100
#define ZERO 0
#define UM 1
#define VAL_DIC_NUM 10
#define VAL_DIC_NOM 15

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
    
    t->equipasPorNum = criaDicOrdenado(VAL_DIC_NUM,ZERO);
    t->equipasPorNom = criaDicOrdenado(VAL_DIC_NOM,UM);

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

    for(int i = 0; i < t->linhas ; i++)
        for(int j = 0; j < t->colunas ; j++)
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


void adicionarEquipaDicOrdenadoPorNumTerreno(char *nome_equipa,int nr_equipa,terreno t){
    
    adicionaElemDicOrdenado(t->equipasPorNum,&nr_equipa ,criaEquipa(nome_equipa)); 
}
void adicionaArqueologoEquipaTerreno(char *nomeArqueologo,int n_equipa,terreno t){

    adicionaArqueologoEquipa(criaArqueologo(nomeArqueologo),(equipa)elementoDicOrdenado(t->equipasPorNum,&n_equipa));
}

void adicionaAoOutroDicionarioTerreno(int nEquipa,terreno t){
    
    adicionaElemDicOrdenado(t->equipasPorNom,nomeEquipa(elementoDicOrdenado(t->equipasPorNum,&nEquipa)),elementoDicOrdenado(t->equipasPorNum,&nEquipa));
    // 
}
void imprimeEquipasTerreno(terreno t){
    
    iterador it = iteradorDicOrdenado(t->equipasPorNom);
	
    while(temSeguinteIterador(it))
	{
		equipa e =	seguinteIterador(it);
        printf("%s\n",nomeEquipa(e));
	}
	
    destroiIterador(it);
	return; 
}

/* FAZER ITERADOR DE ARQUEOLOGOS PARA PROCURAR A ESTRELAR*/
