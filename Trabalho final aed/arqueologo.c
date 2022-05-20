#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arqueologo.h"

#define SIZE 40

/* TAD simples */
struct _arqueologo {
    int pontos;
    int nPenalizacoes;
    char nome[SIZE];
    int i,j;        /*posição i - (linha), j - (coluna) do arqueologo*/ 
};

arqueologo criaArqueologo(char nome[SIZE]){
	
    arqueologo a = (arqueologo) malloc(sizeof(struct _arqueologo));
	if (a == NULL) return NULL;
    a->pontos=0;
    strcpy(a->nome,nome);
    a->i=0;
    a->j=0;
	
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
int pontosArqueologos(arqueologo a){
    return a->pontos;    
}

