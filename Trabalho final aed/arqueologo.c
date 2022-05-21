#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arqueologo.h"

#define SIZE 40

/* TAD simples */
struct _arqueologo {
    int pontos;
    int nPenalizacoes;
    int expulsao;
    char nome[SIZE];
    int i,j;        /*posição i - (linha), j - (coluna) do arqueologo*/ 
};

arqueologo criaArqueologo(char nome[SIZE]){
	
    arqueologo a = (arqueologo) malloc(sizeof(struct _arqueologo));
	if (a == NULL) return NULL;
    a->pontos=0;
    a->nPenalizacoes=0;
    a->expulsao=0;
    strcpy(a->nome,nome);
    a->i=-1;
    a->j=-1;
	
	return a;
}

void apagaArqueologo(arqueologo a){
    free(a);
}
void apagaArqueologoGen(void* a){
    apagaArqueologo((arqueologo)a);
}
char* nomeArqueologo(arqueologo a){
    return a->nome;
}
int pontosArqueologo(arqueologo a){
    return a->pontos;    
}
int estaExpulsoArqueologo(arqueologo a) {
    return a->expulsao;
}
int numPenalizacoesArqueologo(arqueologo a) {
    return a->nPenalizacoes;
}
int saltoArqueologo(arqueologo a, int saltoL, int saltoC, int linhas, int colunas) {
        a->i += saltoL;
        a->j += saltoC;

        if (a->i < 0 || a->j < 0 || a->i >= colunas || a->j >= linhas) {
            a->expulsao = 1;
            return 1;
        }
    return 0;
}

