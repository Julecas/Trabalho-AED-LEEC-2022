/*
 * noSimples.h
 */

#ifndef NOSIMPLES_H_
#define NOSIMPLES_H_

/* Tipo do TAD noSimples */
typedef struct _noSimples * noSimples;

/* Prototipos das funcoes associadas a um aluno - TAD noSimples */

/***********************************************
criaNoSimples - Criacao da instancia da estrutura associada a um no simples.
Parametros:
	e - elemento a guardar no no (void *)
	seg - endereco do seguinte no
Retorno: apontador para a instancia criada
Pre-condicoes:
***********************************************/
noSimples criaNoSimples(void * e, noSimples seg);

/***********************************************
destroiNoSimples - Liberta a memoria ocupada pela instancia da estrutura associada ao no.
Parametros:
	n - no a destruir
Retorno:
Pre-condicoes: n != NULL
***********************************************/
void destroiNoSimples(noSimples n);

/***********************************************
destroiElemENoSimples - Liberta a memoria ocupada pela instancia da estrutura associada ao no.
Parametros:
	n - no a destruir
	destroi - funcao para destruir o elemento
Retorno:
Pre-condicoes: n != NULL
***********************************************/
void destroiElemENoSimples(noSimples n, void (*destroi)(void *));

/***********************************************
atribuiElemNoSimples - Guarda o elemento dado no no.
Parametros:
	n - no
	e - elemento (void *)
Retorno:
Pre-condicoes: n != NULL
***********************************************/
void atribuiElemNoSimples(noSimples n, void * e);

/***********************************************
atribuiSegNoSimples - Guarda o endereco do no seguinte dado no no.
Parametros:
	n - no
	seg - endereco do no seguinte
Retorno:
Pre-condicoes: n != NULL
***********************************************/
void atribuiSegNoSimples(noSimples n, noSimples seg);

/***********************************************
elemNoSimples - Retorna o elemento no no dado.
Parametros:
	n - no
Retorno: elemento (void *)
Pre-condicoes: n != NULL
***********************************************/
void * elemNoSimples(noSimples n);

/***********************************************
segNoSimples - Retorna o endereco do no seguinte ao no dado.
Parametros:
	n - no
Retorno: endereco do no seguinte
Pre-condicoes: n != NULL
***********************************************/
noSimples segNoSimples(noSimples n);

#endif /* NOSIMPLES_H_ */
