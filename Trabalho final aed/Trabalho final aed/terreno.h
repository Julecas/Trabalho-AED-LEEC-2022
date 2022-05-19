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
terreno criaTerreno(int l ,int c,int tesouro[l][c]);
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
/***********************************************
adicionarEquipaDicOrdenadoPorNumTerreno - Adiciona uma nova equipa lida do ficheiro teams.txt ao dicionario de equipas.
Parametros:
	nome_equipa - nome da equipa a adicionar
    t = terreno a consultar
Retorno: void
Pre-condicoes: 
***********************************************/
void adicionarEquipaDicOrdenadoPorNomTerreno(char *nome_equipa,terreno t);
/***********************************************
adicionarEquipaDicOrdenadoPorNomTerreno - Adiciona uma nova equipa lida do ficheiro teams.txt ao dicionario de equipas.
Parametros:
	nome_equipa - nome da equipa a adicionar
    t = terreno a consultar
	nr_equipa = número da equipa
Retorno: void
Pre-condicoes: 
***********************************************/
void adicionarEquipaDicOrdenadoPorNumTerreno(char *nome_equipa,int nr_equipa,terreno t)
/***********************************************
adicionaArqueologoEquipaTerreno - adiciona um arqueologo a uma dada equipa.
Parametros:
	nomeArqueologo - nome do arqueologo a adicionar
    n_equipa = número da equipa
	t = terreno a consultar
Retorno: void
Pre-condicoes: 
***********************************************/
void adicionaArqueologoEquipaTerreno(char *nomeArqueologo,int n_equipa,terreno t);


#endif /* TERRENO_H_ */