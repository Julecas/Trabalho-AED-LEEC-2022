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
	e - equipa para adicionar
	a - arquiologo a adicionar
Retorno: void
Pré-condições: e != NULL, a != NULL
***********************************************/
void adicionaArqueologoEquipa(arqueologo a,equipa e);
/***********************************************
NomeEquipa - indica o nome da equipa dada.
Parâmetros:
	e - equipa 
Retorno: (char*) nome da equipa
Pré-condições: e != NULL
***********************************************/
char* nomeEquipa(equipa e);
/***********************************************
procuraEstrela - procura a estrela de uma dada equipa.
Parâmetros:
	e - equipa 
Retorno: (char*) nome da estrela
Pré-condições: e != NULL
***********************************************/
char* procuraEstrela(equipa e);
/***********************************************
estaEmJogoEquipa - indica se uma equipa ainda está em jogo.
Parâmetros:
	e - equipa 
Retorno: (int) Valor de expulsão da equipa, 1 se a equipa estiver expulsa, 0 caso contrario
Pré-condições: e != NULL
***********************************************/
int estaExpulsaEquipa(equipa e);
/***********************************************
escavarTerrenoEquipa - seleciona um arqueologo para fazer uma escavacao, indicando se o arqueologo que fez o salto foi desclassificado devido a esse salto.
Parâmetros:
	e - equipa 
	saltoL - salto na coordenada y do arqueologo
	saltoC - salto na coordenada x do arqueologo 
	linhas - linhas do terreno 
	colunas - colunas do terreno 
Retorno: (int) Valor de expulsão da equipa, 1 se o arqueologo foi expulso, 0 caso contrario
Pré-condições: e != NULL
***********************************************/
int escavarTerrenoEquipa(equipa e,int saltoL,int saltoC,int linhas,int colunas);
/***********************************************
posColunaEquipa - retorna a posicao de coluna do ultimo arqueologo que escavou
Parâmetros:
	e - equipa 
Retorno: (int) Valor de posição de coluna
Pré-condições: e != NULL
***********************************************/
int posColunaEquipa (equipa e);
/***********************************************
posLinhaEquipa - retorna a posicao de linha do ultimo arqueologo que escavou
Parâmetros:
	e - equipa 
Retorno: (int) Valor de posição de linha
Pré-condições: e != NULL
***********************************************/
int posLinhaEquipa (equipa e);
/***********************************************
darPontosArqueologoEquipa - soma os pontos dado pela escavação de um talhao ao arqueologo que o escavou, através da sua equipa.
Parâmetros:
	e - equipa para adicionar
	pontos - número de pontos
Retorno: void
Pré-condições: e != NULL
***********************************************/
void darPontosArqueologoEquipa(equipa e, int pontos);
/***********************************************
verificarExpulsaoEquipa - verificar se resta algum arqueologo de uma dada equipa em jogo. Caso todos os arqueologos estejam sem licença, expulsa também a equipa.
Parâmetros:
	e - equipa para adicionar
	pontos - número de pontos
Retorno: void
Pré-condições: e != NULL
***********************************************/
void verificarExpulsaoEquipa(equipa e);
/***********************************************
existeArqueologoNaEquipa - verifica se um dado arqueologo já existe na equipa.
Parâmetros:
	e - equipa para adicionar
	nome_arqueologo - nome do arqueologo a verificar
	
Retorno: (int) retorna 1 se existir, 0 caso contrario
Pré-condições: e != NULL
***********************************************/
int existeArqueologoNaEquipa(equipa e,char* nome_arqueologo);

#endif /* EQUIPA_H_ */