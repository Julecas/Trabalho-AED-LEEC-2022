#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "equipa.h"
#include "sequencia.h"
#include "arqueologo.h"
#include "iterador.h"


#define SIZE 40

/* TAD sequencia em lista */
struct _equipa {
    int pontosTotais;
    char nome[SIZE];
    sequencia arqueologos;
};

equipa criaEquipa(char nome[SIZE]){
   equipa e = (equipa) malloc(sizeof(struct _equipa));
	if (e == NULL) return NULL;
    e->pontosTotais=0;
    strcpy(e->nome,nome);
    e->arqueologos = criaSequencia();  

    if ( e->arqueologos == NULL){
      free(e);
      return NULL;
    }
    return e;    
}
void destroiEquipa(equipa e){
  destroiSeqElems(e->arqueologos,apagaArqueologoGen);
  free(e);
}

void destroiEquipaGen(void* e){
  destroiEquipa((equipa)e);
}
void adicionaArqueologoEquipa(arqueologo a,equipa e){
  adicionaPosSequencia(e->arqueologos,a,tamanhoSequencia(e->arqueologos)+1);    
}
char* nomeEquipa(equipa e){
  return e->nome;
}
char* procuraEstrela(equipa e){
    char chave[SIZE];
    
    iterador it = iteradorSequencia(e->arqueologos);
    arqueologo a;

    while(temSeguinteIterador(it))
	{
	  a =	seguinteIterador(it);
     // if()
    
    printf("%s\n",nomeEquipa(e));
	}
	
  destroiIterador(it);
	return; 

}