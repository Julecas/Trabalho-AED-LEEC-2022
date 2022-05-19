/*
 * equipa.h
 *
 */

#ifndef EQUIPA_H_
#define EQUIPA_H_

#include"arqueologo.h"

#define SIZE 40

/* TAD simples */
typedef struct _equipa * equipa;

/***********************************************
criaEquipa - Criação da instância da estrutura associada a uma Equipa.
Parâmetros:
	nome - nome da equipa
Retorno: apontador para a instância criada
***********************************************/
equipa criaEquipa(char nome[SIZE]);
/***********************************************
destroiEquipa - Liberta a memória ocupada pela instância da estrutura associada à equipa.
Parâmetros:
	e - equipa a destruir
Retorno:
Pré-condições: e != NULL
***********************************************/
void destroiEquipa(equipa e);
/***********************************************
destroiEquipaGen - Liberta a memória ocupada pela instância da estrutura associada à equipa.
Parâmetros:
	e - equipa a destruir
Retorno:
Pré-condições: e != NULL
***********************************************/
void destroiEquipaGen(void* e);
/***********************************************
adicionaArqueologoEquipa - adiciona um arqueologo á equipa dada.
Parâmetros:
	a - equipa para adicionar
	e - arquiologo a adicionar
Retorno: void
Pré-condições: e != NULL, a != NULL
***********************************************/
void adicionaArqueologoEquipa(arqueologo a,equipa e);



#endif /* EQUIPA_H_ */