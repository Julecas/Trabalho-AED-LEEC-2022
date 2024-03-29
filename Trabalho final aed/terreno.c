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
    destroiDicOrdenado(t->equipasPorNom); 
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

void adicionaAoOutroDicionarioTerreno(int nEquipa,terreno t) {
    
    adicionaElemDicOrdenado(t->equipasPorNom,nomeEquipa(elementoDicOrdenado(t->equipasPorNum,&nEquipa)),elementoDicOrdenado(t->equipasPorNum,&nEquipa));
    // 
}
void classificaEquipasTerreno(terreno t){ /*alterar funcao*/
    
    iterador it = iteradorDicOrdenado(t->equipasPorNom);
    equipa e;
	
    while(temSeguinteIterador(it))
	{
		e =	seguinteIterador(it);
        printf("%s\n",nomeEquipa(e));
	}
	
    destroiIterador(it);
	return; 
}

int tamanhoDicOrdenadoPorNumTerreno (terreno t) {
    return tamanhoDicOrdenado(t->equipasPorNum);
}

int existeEquipaNoOutroDicTerreno(terreno t, int nEquipa) {
    return existeElemDicOrdenado(t->equipasPorNom, nomeEquipa(elementoDicOrdenado(t->equipasPorNum,&nEquipa)));
}

int existeEquipaEmJogoNoTerreno(terreno t, char *nome_equipa) {
    if (existeElemDicOrdenado(t->equipasPorNom, nome_equipa)) {
        if (!estaExpulsaEquipa((equipa)elementoDicOrdenado(t->equipasPorNom,nome_equipa))) {
            return 1;
        }
    }
    return 0;
}

int existeAlgumaEquipaEmJogoNoTerreno(terreno t) {
    iterador it = iteradorDicOrdenado(t->equipasPorNom);
    equipa e;
	
    while(temSeguinteIterador(it))
	{
		e =	seguinteIterador(it);

        if (!estaExpulsaEquipa(e)) { // Retorna 1 caso encontre uma equipa ainda em jogo. Não precisa de verificar mais pois basta uma para verificar a condição.
            destroiIterador(it);
            return 1;
        }
	}

    destroiIterador(it);
	return 0;
}

void escavarTerreno(terreno t, char* nome_equipa, int saltoL,int saltoC){
    equipa e = elementoDicOrdenado(t->equipasPorNom,nome_equipa);
    int posC, posL;

    if(!escavarTerrenoEquipa(e, saltoL,saltoC, t->linhas, t->colunas)) {
        //printf("Saltou!\n");
        posC = posColunaEquipa(e);
        posL = posLinhaEquipa(e);
        darPontosArqueologoEquipa(e, escavarTalhao(t->talhoes[posL][posC]));
    }
    else {
        verificarExpulsaoEquipa(e);
    }
}
/*equipa procuraEquipa(terreno t,char* nome_equipa){
    equipa e = elementoDicOrdenado(t->equipasPorNom,nome_equipa);
    return e;
}*/
char* procuraEstrelaTerreno(terreno t,char* nome_equipa){
   return procuraEstrela((equipa)elementoDicOrdenado(t->equipasPorNom,nome_equipa));
}

int quantasEquipasEmJogoNoTerreno(terreno t){
    iterador it = iteradorDicOrdenado(t->equipasPorNom);
    equipa e;
    int count=0;
	
    while(temSeguinteIterador(it))
	{
		e =	seguinteIterador(it);

        if (!estaExpulsaEquipa(e)) { 
            count++;
        }
	}

    destroiIterador(it);
	return count;
}
int existeArqueologoNaEquipaTerreno (terreno t,char* nome_equipa, char* nome_arqueologo) {
    equipa e = elementoDicOrdenado(t->equipasPorNom,nome_equipa);
    return existeArqueologoNaEquipa(e,nome_arqueologo);
}

void adicionarReforcoEquipaTerreno(terreno t,char* nome_equipa, char* nome_arqueologo) {
    adicionaArqueologoEquipa(criaArqueologo(nome_arqueologo), (equipa)elementoDicOrdenado(t->equipasPorNom,nome_equipa));
}
int quantasEquipasNoTerreno(terreno t){
    return tamanhoDicOrdenado(t->equipasPorNom);
}

void * obterERemoverDoDicMelhorEquipaNoTerreno(terreno t) {
    iterador it = iteradorDicOrdenado(t->equipasPorNom);
    equipa e, melhor_equipa;

    while (temSeguinteIterador(it)) {
      melhor_equipa = seguinteIterador(it); // Guardar a primeira equipa não-expulsa na variável de melhor_equipa.
      if (!estaExpulsaEquipa(melhor_equipa)) {
        break;
      }
    }
	
    while(temSeguinteIterador(it))
	{
		e =	seguinteIterador(it);

        if (!estaExpulsaEquipa(e)) {
            if (totalPontosEquipa(e) > totalPontosEquipa(melhor_equipa)) {
                melhor_equipa = e;
            }

            if (totalPontosEquipa(e) == totalPontosEquipa(melhor_equipa)) {
                if (quantosArqueologosExpulsosNaEquipa(e) < quantosArqueologosExpulsosNaEquipa(melhor_equipa)) {
                    melhor_equipa = e;
                }
                if (quantosArqueologosExpulsosNaEquipa(e) == quantosArqueologosExpulsosNaEquipa(melhor_equipa)) {
                    if(strcmp(nomeEquipa(e),nomeEquipa(melhor_equipa)) < 0) { // usar o compChaves() do chaves.c depois
                        melhor_equipa = e;
                    }
                }
            }
        }
	}

    destroiIterador(it);

    //printf("%s: %d pts; %d descl.; %d com lic.\n", nomeEquipa(melhor_equipa), pontosTotaisEquipa(melhor_equipa), tamanhoEquipa(melhor_equipa) - quantosArqueologosEmJogoNaEquipa(melhor_equipa), quantosArqueologosEmJogoNaEquipa(melhor_equipa));

	return removeElemDicOrdenado(t->equipasPorNom, nomeEquipa(melhor_equipa));
}