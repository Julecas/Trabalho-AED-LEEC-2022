#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "equipa.h"
#include "sequencia.h"

#define SIZE 40

/* TAD sequencia em lista */
struct _equipa {
    int pontosTotais;
    char nome[SIZE];
    sequencia arqueologos
};

equipa criaEquipa(char nome){
   equipa e = (equipa) malloc(sizeof(struct _equipa));
	if (e == NULL) return NULL;
    e->pontosTotais=0;
    strpcy(e->nome,nome);
    e->arqueologos = criaSequencia();  

    if ( e->arqueologos == NULL){
		free(e);
		return NULL;
    return e;    
}
