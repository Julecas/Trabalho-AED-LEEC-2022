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
int pontosArqueologos(arqueologo a);




#endif /* ARQUEOLOGO_H_ */