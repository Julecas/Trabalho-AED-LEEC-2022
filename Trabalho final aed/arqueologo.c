#include "arqueologo.h"

#define SIZE 40

/* TAD simples */
struct _arqueologo {
    int pontos;
    char nome[SIZE];
    int i,j;        /*posição i - (linha), j - (coluna) do arqueologo*/ 
};

arqueologo criaArqueologo(char nome){
	
    arqueologo a = (arqueologo) malloc(sizeof(struct _arqueologo));
	if (a == NULL) return NULL;
    a->pontos=0;
    strpcy(a->nome,nome);
    a->i=0;
    a->j=0;
	
	return a;
}

void apagaArqueologo(arqueologo a){
    free(a);
}