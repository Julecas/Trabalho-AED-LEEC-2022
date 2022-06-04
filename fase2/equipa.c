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
    int expulsao;
    char nome[SIZE];
    sequencia arqueologos;
    int arqAEscavar;
    //arqueologo proximoAEscavar
}; 

equipa criaEquipa(char nome[SIZE]){
   equipa e = (equipa) malloc(sizeof(struct _equipa));
	    if (e == NULL) return NULL;
    e->pontosTotais=0;
    e->expulsao=0;
    
    //e->proximoAEscavar = (arqueologo) malloc(sizeof(arqueologo)); 
    //e->proximoAEscavar = elementoPosSequencia(e->arqueologos, 1);
    
    e->arqAEscavar=1;
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
   
    iterador it = iteradorSequencia(e->arqueologos);
    arqueologo a;
    arqueologo estrela;

    while (temSeguinteIterador(it)) {
      estrela = seguinteIterador(it); // Guardar o primeiro arqueólogo da equipa na variável de estrela.
      if (!estaExpulsoArqueologo(estrela)) {
        break;
      }
    }
    
    while(temSeguinteIterador(it)){
	
	  a =	seguinteIterador(it);
    
    if(!estaExpulsoArqueologo(a)){
      
      if(pontosArqueologo(a) > pontosArqueologo(estrela)){
       estrela = a; 
       
      
      }
      if(pontosArqueologo(a) == pontosArqueologo(estrela)){
        if(numPenalizacoesArqueologo(a) < numPenalizacoesArqueologo(estrela)) {
          	estrela = a;   
        }
        if(numPenalizacoesArqueologo(a) == numPenalizacoesArqueologo(estrela)) {
          if(strcmp(nomeArqueologo(a),nomeArqueologo(estrela)) < 0){ // usar o compChaves() do chaves.c depois
            estrela = a;  
          }
           
        }
      }
    }
	}
  
  destroiIterador(it);
  return nomeArqueologo(estrela);

}

int estaExpulsaEquipa(equipa e) {
  return e->expulsao;
}
int escavarTerrenoEquipa(equipa e,int saltoL,int saltoC,int linhas,int colunas){
  
  while (1) {
    if(e->arqAEscavar > tamanhoSequencia(e->arqueologos)){
      e->arqAEscavar = 1;
    }

    arqueologo a = elementoPosSequencia(e->arqueologos,e->arqAEscavar);
    
    if (!estaExpulsoArqueologo(a)){
      e->arqAEscavar++;
      return saltoArqueologo(a,saltoL,saltoC,linhas,colunas);
    }
    else {
      e->arqAEscavar++;
    }
  }
}
int posColunaEquipa (equipa e) {
  return posColunaArqueologo((arqueologo)elementoPosSequencia(e->arqueologos,e->arqAEscavar - 1)); // É -1 porque queremos ver a posição do último arqueólogo que se mexeu.
}
int posLinhaEquipa (equipa e) {
  return posLinhaArqueologo((arqueologo)elementoPosSequencia(e->arqueologos,e->arqAEscavar - 1));
}
void darPontosArqueologoEquipa (equipa e, int pontos) {
  darPontosArqueologo((arqueologo)elementoPosSequencia(e->arqueologos,e->arqAEscavar - 1), pontos);
}
void verificarExpulsaoEquipa(equipa e) {
    iterador it = iteradorSequencia(e->arqueologos);
    arqueologo a;

    while (temSeguinteIterador(it)) {
      a = seguinteIterador(it); 
      if (!estaExpulsoArqueologo(a)) {
        return;
      }
    }
    e->expulsao = 1;
}
int existeArqueologoNaEquipa(equipa e, char* nome_arqueologo) {
    iterador it = iteradorSequencia(e->arqueologos);
    arqueologo a;

    while (temSeguinteIterador(it)) {
      a = seguinteIterador(it); 
      if (!strcmp(nomeArqueologo(a), nome_arqueologo)) {
        return 1;
      }
    }
    return 0;
}
int totalPontosEquipa(equipa e) {
  iterador it = iteradorSequencia(e->arqueologos);
  arqueologo a;
  int totalPontos = 0;

  while (temSeguinteIterador(it)) {
    a = seguinteIterador(it); 
    if (!estaExpulsoArqueologo(a)) {
        totalPontos += pontosArqueologo(a);
    }
  }

  return totalPontos;
}
int tamanhoEquipa (equipa e) {
  return tamanhoSequencia(e->arqueologos);
}
int quantosArqueologosExpulsosNaEquipa (equipa e) {
  iterador it = iteradorSequencia(e->arqueologos);
  arqueologo a;
  int count = 0;

  while (temSeguinteIterador(it)) {
    a = seguinteIterador(it); 

    if (estaExpulsoArqueologo(a)) {
        count++;
    }
  }

  return count;
}

int compEquipa(equipa primeira_equipa, equipa segunda_equipa) {
  if (totalPontosEquipa(primeira_equipa) > totalPontosEquipa(segunda_equipa)) {
    return 1;
  }

  if (totalPontosEquipa(primeira_equipa) == totalPontosEquipa(segunda_equipa)) {
    if (quantosArqueologosExpulsosNaEquipa(primeira_equipa) < quantosArqueologosExpulsosNaEquipa(segunda_equipa)) {
      return 1;
    }
    if (quantosArqueologosExpulsosNaEquipa(primeira_equipa) == quantosArqueologosExpulsosNaEquipa(segunda_equipa)) {
      // Ver quem tem menos arqueólogos em jogo
      if ((tamanhoEquipa(primeira_equipa) - quantosArqueologosExpulsosNaEquipa(primeira_equipa)) < (tamanhoEquipa(segunda_equipa) - quantosArqueologosExpulsosNaEquipa(segunda_equipa))) {
        return 1;
      }

      if ((tamanhoEquipa(primeira_equipa) - quantosArqueologosExpulsosNaEquipa(primeira_equipa)) == (tamanhoEquipa(segunda_equipa) - quantosArqueologosExpulsosNaEquipa(segunda_equipa))) {

        if(strcmp(nomeEquipa(primeira_equipa),nomeEquipa(segunda_equipa)) < 0) { // usar o compChaves() do chaves.c depois
          return 1;
        }
      }

    }
  }
  return 0;
}