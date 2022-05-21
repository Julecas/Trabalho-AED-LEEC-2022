/*
 * arqueologo.h
 *
 */

#ifndef ARQUEOLOGO_H_
#define ARQUEOLOGO_H_

#define SIZE 40

/* TAD simples */
typedef struct _arqueologo * arqueologo;

/***********************************************
criaArqueologo - Criação da instância da estrutura associada a um arqueologo.
Parâmetros:
	nome - nome do arqueologo
Retorno: apontador para a instância criada
***********************************************/
arqueologo criaArqueologo(char nome[SIZE]);
/***********************************************
apagaArqueologo - Liberta a memória ocupada pela instância da estrutura associada ao arqueologo.
Parâmetros:
	a - arqueologo a apagar
Retorno: void
Pré-condições: a != NULL
***********************************************/
void apagaArqueologo(arqueologo a);
/***********************************************
apagaArqueologoGen - Liberta a memória ocupada pela instância da estrutura associada ao arqueologo.
Parâmetros:
	a - arqueologo a apagar
Retorno: void
Pré-condições: a != NULL
***********************************************/
void apagaArqueologoGen(void* a);
/***********************************************
NomeArqueologo - retorna o nome do arqueologo dado.
Parâmetros:
	a - arqueologo 
Retorno: (char*) nome do arqueologo
Pré-condições: a != NULL
***********************************************/
char* nomeArqueologo(arqueologo a);
/***********************************************
pontosArqueologos - retorna os pontos do arqueologo dado.
Parâmetros:
	a - arqueologo 
Retorno: (int) pontos do arqueologo
Pré-condições: a != NULL
***********************************************/
int pontosArqueologo(arqueologo a);
/***********************************************
pontosArqueologos - retorna se o arqueologo esta expulso.
Parâmetros:
	a - arqueologo 
Retorno: (int) 1 se estiver expulso
Pré-condições: a != NULL
***********************************************/
int estaExpulsoArqueologo(arqueologo a);
/***********************************************
numPenalizacoesArqueologo - indica o numero de penalizações de um dado arqueologo.
Parâmetros:
	a - arqueologo 

Retorno: (int) número de penalizações de um dado arqueologo
Pré-condições:
***********************************************/
int numPenalizacoesArqueologo(arqueologo a);
/***********************************************
saltoArqueologo - efetua um salto de um dado arqueologo, retornando se foi desclassificado ou não.
Parâmetros:
	a - arqueologo 
	saltoL - salto na coordenada y
	saltoC - salto na coordenada x
Retorno: (int) 1 se foi expulso, 0 em contrário
Pré-condições: arqueologo (a) não está expulso
***********************************************/
int saltoArqueologo(arqueologo a, int saltoL, int saltoC, int l, int c);

#endif /* ARQUEOLOGO_H_ */