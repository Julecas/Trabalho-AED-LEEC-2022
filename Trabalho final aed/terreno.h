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
Pre-condicoes: t != NULL
***********************************************/
int riquezaTerreno(terreno t);
/***********************************************
estadoTerreno - Consulta se os talhões tem ou não tesouros enterrados .
Parametros:
	t - terreno a consultar

Retorno: (int) 1 se tiver tesouro 0 caso contrario
Pre-condicoes: t != NULL
***********************************************/
int estadoTerreno(terreno t,int i,int j);
/***********************************************
linhasTerreno - Consulta o número de linhas do terreno .
Parametros:
	t - terreno a consultar

Retorno: (int) número de linhas
Pre-condicoes: t != NULL
***********************************************/
int linhasTerreno(terreno t);
/***********************************************
colunasTerreno - Consulta o número de colunas do terreno .
Parametros:
	t - terreno a consultar

Retorno: (int) número de colunas
Pre-condicoes: t != NULL
***********************************************/
int colunasTerreno(terreno t);
/***********************************************
adicionarEquipaDicOrdenadoPorNumTerreno - Adiciona uma nova equipa lida do ficheiro teams.txt ao dicionario de equipas.
Parametros:
	nome_equipa - nome da equipa a adicionar
    t = terreno a consultar
Retorno: void
Pre-condicoes: t != NULL
***********************************************/
void adicionarEquipaDicOrdenadoPorNumTerreno(char *nome_equipa,int nr_equipa,terreno t);
/***********************************************
adicionaArqueologoEquipaTerreno - adiciona um arqueologo a uma dada equipa.
Parametros:
	nomeArqueologo - nome do arqueologo a adicionar
    n_equipa = número da equipa
	t = terreno a consultar
Retorno: void
Pre-condicoes: t != NULL
***********************************************/
void adicionaArqueologoEquipaTerreno(char *nomeArqueologo,int n_equipa,terreno t);
/***********************************************
adicionaAoOutroDicionario - adiciona as equipas escolhidas pelo utilizador ao dicionario ordenado por nomes.
Parametros:
    nEquipa = número da equipa
	t = terreno a consultar
Retorno: void
Pre-condicoes:  t != NULL
***********************************************/
void adicionaAoOutroDicionarioTerreno(int nEquipa,terreno t);
/***********************************************
classificaEquipasTerreno - classifica todas as equipas em jogo.
Parametros:
	t = terreno a consultar
Retorno: (char*) nome da equipa
Pre-condicoes:  t != NULL
**********************************************/
void classificaEquipasTerreno(terreno t);
/***********************************************
tamanhoDicOrdenadoPorNumTerreno - Consulta o numero de elementos no dicionario ordenado por numeros, ou seja, o numero de equipas do ficheiro.
Parametros:
	t - terreno a consultar

Retorno: (int) numero de elementos no dicionario (numero de equipas do ficheiro)
Pre-condicoes: t != NULL
***********************************************/
int tamanhoDicOrdenadoPorNumTerreno (terreno t);
/***********************************************
existeEquipaNoOutroDicTerreno - Verifica se existe uma dada equipa no dicionario ordenado por nome, independentemente de estar desclassificada ou nao.
Parametros:
	t - terreno a consultar
	nEquipa = número da equipa

Retorno: (int) 1 se a equipa existir, 0 caso contrario
Pre-condicoes: t != NULL
***********************************************/
int existeEquipaNoOutroDicTerreno(terreno t, int nEquipa);
/***********************************************
existeEquipaEmJogoNoTerreno - Verifica se a equipa existe e esta em jogo.
Parametros:
	t - terreno a consultar
	nome_equipa - nome da equipa a consultar

Retorno: (int) 1 se a equipa estiver em jogo, 0 caso contrario
Pre-condicoes: t != NULL
***********************************************/
int existeEquipaEmJogoNoTerreno(terreno t, char *nome_equipa);
/***********************************************
existeAlgumaEquipaEmJogoNoTerreno - Consulta se existe alguma equipa ainda em jogo.
Parametros:
	t - terreno a consultar

Retorno: (int) 1 se existir alguma equipa em jogo, 0 caso contrario
Pre-condicoes: t != NULL
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
Pre-condicoes: t != NULL
***********************************************/
void escavarTerreno(terreno t, char* nome_equipa, int saltoL, int saltoC);
/***********************************************
procuraEquipa - procura uma equipa no dicionario em que a chave é o nome das equipas
	t - terreno a consultar
	nome_equipa - nome da equipa a consultar
	
Retorno: (equipa) equipa a consultar
Pre-condicoes: t != NULL
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
/***********************************************
quantasEquipaEmJogoNoTerreno - Consulta quantas equipas ainda estão em jogo.
Parametros:
	t - terreno a consultar

Retorno: (int) número de equipas em jogo
Pre-condicoes: t != NULL
***********************************************/
int quantasEquipaEmJogoNoTerreno(terreno t);
/***********************************************
existeArqueologoNaEquipaTerreno - verifica se existe um dado arqueologo numa dada equipa.
Parametros:
	t - terreno a consultar
	nome_equipa - nome da equipa a verificar
	nome_arqueologo - nome do arqueologo a verificar
Retorno: (int) número de equipas em jogo
Pre-condicoes: t != NULL
***********************************************/
int existeArqueologoNaEquipaTerreno (terreno t,char* nome_equipa, char* nome_arqueologo);
/***********************************************
adicionarReforcoEquipaTerreno - adiciona um novo arqueologo a uma equipa existente.
Parametros:
	t - terreno a consultar
	nome_equipa - nome da equipa existente
	nome_arqueologo - nome do arqueologo a adicionar
Retorno: (void)
Pre-condicoes: t != NULL , nome_equipa tem que existir no DicOrdnado, nome_arqueologo não pode existir na lista de arqueologos(ser repetido)  
***********************************************/
void adicionarReforcoEquipaTerreno(terreno t,char* nome_equipa, char* nome_arqueologo);

#endif /* TERRENO_H_ */