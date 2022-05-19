/*
 * talhao.h
 *
 */

#ifndef TALHAO_H_
#define TALHAO_H_

/* TAD simples */
typedef struct _talhao * talhao;

/***********************************************
criaTerreno - Criação de um talhao.
Parametros:
    tesouro - valor do tesouro do talhão criado
    
Retorno: apontador para a instância criada
Pre-condicoes: tesouro >= 0
***********************************************/
talhao criaTalhao(int tesouro);
/***********************************************
destroiTalhao - Liberta a memória ocupada pela instância da estrutura associada ao talhao.
Parâmetros:
	ta - talhao a destruir
Retorno: void
Pré-condições: t != NULL
***********************************************/
void destroiTalhao(talhao ta);
/***********************************************
riquezaTalhao - Consulta a riqueza de um dado talhao
Parametros:
    ta - talhão dado
    
Retorno: (int) valor da riqueza num dado talhão 
Pre-condicoes: 
***********************************************/
int riquezaTalhao(talhao ta);
/***********************************************
estadoTalhao - Consulta se existe ou não tesouro num dado talhão
Parametros:
    ta - talhão dado
    
Retorno: (int) 1 se o talhão contiver tesouro, 0 caso contrario
Pre-condicoes: 
***********************************************/
int estadoTalhao(talhao ta);

#endif /* TALHAO_H_ */