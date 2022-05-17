/*
 * equipa.h
 *
 */

#ifndef EQUIPA_H_
#define EQUIPA_H_

/* TAD simples */
typedef struct _equipa * equipa;

/***********************************************
criaEquipa - Criação da instância da estrutura associada a uma Equipa.
Parâmetros:
	nome - nome da equipa
Retorno: apontador para a instância criada
***********************************************/
equipa criaEquipa(char nome);
/***********************************************
destroiEquipa - Liberta a memória ocupada pela instância da estrutura associada à equipa.
Parâmetros:
	e - equipa a destruir
Retorno:
Pré-condições: e != NULL
***********************************************/
void destroiEquipa(equipa e);



#endif /* EQUIPA_H_ */