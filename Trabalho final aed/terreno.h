/*
 * terreno.h
 *
 */

#ifndef TERRENO_H_
#define TERRENO_H_

/* TAD simples */
typedef struct _terreno * terreno;

/***********************************************
criaTerreno - Criação do terreno.
Parametros:
	l - número de linhas
    c - número de colunas
    tesouro - matriz de valores de tesouros em cada talhão
    
Retorno: apontador para a instância criada
Pre-condicoes: l > 0 e c > 0
***********************************************/
terreno criaTerreno(int l ,int c,int **tesouro);
/***********************************************
destroiTerrreno - Liberta a memória ocupada pela instância da estrutura associada ao terreno.
Parâmetros:
	t - terreno a destruir
Retorno: void
Pré-condições: t != NULL
***********************************************/
void destroiTerreno(terreno t);
/***********************************************
riquezaTerreno - Consulta a riqueza do terreno.
Parametros:
	t - terreno a consultar

Retorno: (int) valor da riqueza total do terreno
Pre-condicoes:
***********************************************/
int riquezaTerreno(terreno t);
/***********************************************
estadoTerreno - Consulta se os talhões tem ou não tesouros enterrados .
Parametros:
	t - terreno a consultar

Retorno: (int) 1 se tiver tesouro 0 caso contrario
Pre-condicoes:
***********************************************/
int estadoTerreno(terreno t,int i,int j);
/***********************************************
linhasTerreno - Consulta o número de linhas do terreno .
Parametros:
	t - terreno a consultar

Retorno: (int) número de linhas
Pre-condicoes:
***********************************************/
int linhasTerreno(terreno t);
/***********************************************
colunasTerreno - Consulta o número de colunas do terreno .
Parametros:
	t - terreno a consultar

Retorno: (int) número de colunas
Pre-condicoes:
***********************************************/
int colunasTerreno(terreno t);


#endif /* TERRENO_H_ */