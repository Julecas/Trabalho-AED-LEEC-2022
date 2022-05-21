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
void adicionarEquipaDicOrdenadoPorNumTerreno(char *nome_equipa,int nr_equipa,terreno t);
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
/***********************************************
adicionaAoOutroDicionario - adiciona as equipas escolhidas pelo utilizador ao dicionario ordenado por nomes.
Parametros:
    nEquipa = número da equipa
	t = terreno a consultar
Retorno: void
Pre-condicoes: 
***********************************************/
void adicionaAoOutroDicionarioTerreno(int nEquipa,terreno t);
/***********************************************
imprimeEquipasTerreno - imprime todas as equipas em jogo.
Parametros:
	t = terreno a consultar
Retorno: (char*) nome da equipa
Pre-condicoes: 
**********************************************/
void imprimeEquipasTerreno(terreno t);
/***********************************************
tamanhoDicOrdenadoPorNumTerreno - Consulta o numero de elementos no dicionario ordenado por numeros, ou seja, o numero de equipas do ficheiro.
Parametros:
	t - terreno a consultar

Retorno: (int) numero de elementos no dicionario (numero de equipas do ficheiro)
Pre-condicoes:
***********************************************/
int tamanhoDicOrdenadoPorNumTerreno (terreno t);
/***********************************************
existeEquipaNoOutroDicTerreno - Verifica se existe uma dada equipa no dicionario ordenado por nome, independentemente de estar desclassificada ou nao.
Parametros:
	t - terreno a consultar
	nEquipa = número da equipa

Retorno: (int) 1 se a equipa existir, 0 caso contrario
Pre-condicoes:
***********************************************/
int existeEquipaNoOutroDicTerreno(terreno t, int nEquipa);
/***********************************************
existeEquipaEmJogoNoTerreno - Verifica se a equipa existe e esta em jogo.
Parametros:
	t - terreno a consultar
	nome_equipa - nome da equipa a consultar

Retorno: (int) 1 se a equipa estiver em jogo, 0 caso contrario
Pre-condicoes:
***********************************************/
int existeEquipaEmJogoNoTerreno(terreno t, char *nome_equipa);
/***********************************************
existeAlgumaEquipaEmJogoNoTerreno - Consulta se existe alguma equipa ainda em jogo.
Parametros:
	t - terreno a consultar

Retorno: (int) 1 se existir alguma equipa em jogo, 0 caso contrario
Pre-condicoes:
***********************************************/
int existeAlgumaEquipaEmJogoNoTerreno(terreno t);
/***********************************************
escavarTerreno - escava um talhão com base nas coordenasdas (saltoL+coord_x) (saltoC+coord_y) , essa escavação é associada a uma dada equipa.
Parametros:
	t - terreno a consultar
	nome_equipa - nome da equipa a escavar
	saltoL - salto na coordenada x
	saltoC - salto na coordenada y
Retorno: (void) 
Pre-condicoes:
***********************************************/
void escavarTerreno(terreno t, char* nome_equipa, int saltoL, int saltoC);
/***********************************************
procuraEquipa - procura uma equipa no dicionario em que a chave é o nome das equipas
	t - terreno a consultar
	nome_equipa - nome da equipa a consultar
	
Retorno: (equipa) equipa a consultar
Pre-condicoes:
***********************************************/
//equipa procuraEquipa(terreno t,char* nome_equipa);
/***********************************************
procuraEstrelaTerreno - procura a estrela de uma dada equipa.
Parâmetros:
	t - terreno 
	nome_equipa - nome da equipa a consultar estrela
Retorno: (char*) nome da estrela
Pré-condições: t != NULL
***********************************************/
char* procuraEstrelaTerreno(terreno t,char* nome_equipa);

#endif /* TERRENO_H_ */