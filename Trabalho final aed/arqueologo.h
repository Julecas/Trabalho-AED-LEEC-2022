/*
 * arqueologo.h
 *
 */

#ifndef ARQUEOLOGO_H_
#define ARQUEOLOGO_H_

/* TAD simples */
typedef struct _arqueologo * arqueologo;

/***********************************************
criaArqueologo - Criação da instância da estrutura associada a um arqueologo.
Parâmetros:
	nome - nome do arqueologo
Retorno: apontador para a instância criada
***********************************************/
arqueologo criaArqueologo(char nome);
/***********************************************
apagaArqueologo - Liberta a memória ocupada pela instância da estrutura associada ao arqueologo.
Parâmetros:
	a - arqueologo a apagar
Retorno: void
Pré-condições: a != NULL
***********************************************/
void apagaArqueologo(arqueologo a);




#endif /* ARQUEOLOGO_H_ */