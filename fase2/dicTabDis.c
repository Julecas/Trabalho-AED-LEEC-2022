/*
 * dicTabDis.c
 *
 *  Created on: 12 de Abr de 2014
 *      Author: fernanda
 */

#include <stdlib.h>

#include "iterador.h"
#include "dicionario.h"
#include "chaves.h"
#include "noSimples.h"
#include "tuplo.h"


/*  Estrutura de dados do tipo de dados: dicionario ---> os elementos não podem ser repetidos com base num identificador (chave) dos elementos */
struct _dicionario{
	noSimples * elems; // apontador para vector de noSimples (lista com cabeça)
	int numElems;
	int capacidade; // capacidade prevista
	int tamanho; // tamanho do vector criado
	int tipoCh; // 0-inteiro; 1-string
};

/* Prototipos das funcoes associadas a um dicionario */

/* função auxiliar para calcular o primo maior ou igual a n */
int verificaSeEPrimo(int n) 
{
    int i;
    if(n==1)
        return 0;
    for(i=2; i<n; i++)
    {
        if(!(n % i))
            return 0;
    }
    return 1; //quando é primo
}

int primo(int n){
	//FAZER
	while(!verificaSeEPrimo(n)) //quando n é primo para o while
        n++;
    return n;
}

dicionario criaDicionario(int cap, int tipoChave){
	dicionario d;
	int i;
	d = (dicionario) malloc(sizeof(struct _dicionario));
	if ( d == NULL) return NULL;
	d->tamanho = primo(2*cap);
	d->elems = (noSimples*)malloc(sizeof(noSimples) * d->tamanho);
	if (d->elems == NULL){
		free(d);
		return NULL;
	}
	for (i=0;i<d->tamanho;i++)
		d->elems[i] = NULL;
	d->numElems = 0;
	d->capacidade = cap;
	d->tipoCh =tipoChave;
	return d;
}

void destroiDicionario (dicionario d ){
	int i = 0;
	noSimples  aux;
	tuplo t;
	for(;i<d->tamanho;i++){
		aux = d->elems[i];
		while (aux != NULL){
			d->elems[i] = segNoSimples(aux);
			t = (tuplo) elemNoSimples(aux);
			destroiNoSimples(aux);
			destroiTuplo(t);
			aux = d->elems[i];
		}
	}
	free(d);
}


void destroiDicEElems(dicionario d, void (*destroi)(void *) ){
	int i = 0;
	noSimples  aux;
	tuplo t;
	for(;i<d->tamanho;i++){
		aux = d->elems[i];
		while (aux != NULL){
			d->elems[i] = segNoSimples(aux);
			t = elemNoSimples(aux);
			destroi(segTuplo(t));
			destroiNoSimples(aux);
			destroiTuplo(t);
			aux = d->elems[i];
		}
	}
	free(d);
}

int vazioDicionario(dicionario d){
	if (d->numElems == 0)
		return 1;
	return 0;
}

int tamanhoDicionario(dicionario d){
	return d->numElems;
}

int existeElemDicionario(dicionario d, void * ch){
	if (elementoDicionario(d,ch) != NULL)
		return 1;
	return 0;
}

void * elementoDicionario(dicionario d, void * ch){
	tuplo t;
	noSimples auxNo;
	int pos = dispersao(ch,d->tamanho,d->tipoCh);
	auxNo = d->elems[pos];
	while (auxNo != NULL){
		t = elemNoSimples(auxNo);
		if (igualChaves(priTuplo(t), ch,d->tipoCh) == 1)
			return segTuplo(t);
		auxNo = segNoSimples(auxNo);
	}
	return NULL;
}

int adicionaElemDicionario(dicionario d, void * ch, void * elem){
	int pos;
	noSimples noAux;
	if (existeElemDicionario(d,ch) == 1)
		return 0;
	pos = dispersao(ch,d->tamanho,d->tipoCh);
	//FAZER INSERÇAO NA LISTA DE COLISAO DA POSIÇAO POS
	tuplo t = criaTuplo(d->tipoCh, ch, elem); //lista ligada de tuplos
    noAux = criaNoSimples(t, NULL);
    if (d->elems[pos]==NULL) {
        d->elems[pos] = noAux;
    }
    else{
        atribuiSegNoSimples(noAux, d->elems[pos]);
        d->elems[pos] = noAux;
    }
	d->numElems++;
	return 1;
}

void * removeElemDicionario(dicionario d, void * ch){
	tuplo t;
	void * elem;
	//void * auxCh;
	noSimples auxNo, antNo = NULL;
	int pos = dispersao(ch,d->tamanho,d->tipoCh);
	auxNo = d->elems[pos];
	if (auxNo == NULL)
		return 0;
	//FAZER REMOÇAO NA LISTA DE COLISAO DA POSIÇAO POS
	else{
        while(auxNo!=NULL){
            t = elemNoSimples(auxNo);
            if(igualChaves(priTuplo(t), ch, d->tipoCh) == 1){
                elem = segTuplo(t);
                break;
            }
            antNo = auxNo;
            auxNo = segNoSimples(auxNo);
        }
        if(antNo != NULL){
            atribuiSegNoSimples(antNo, segNoSimples(auxNo));
            destroiNoSimples(auxNo);
            d->numElems--;
            return elem;
        }
        else{
            d->elems[pos] = segNoSimples(auxNo);
            destroiNoSimples(auxNo);
            d->numElems--;
            return elem;
        }
    }
	return NULL;
}

iterador iteradorDicionario(dicionario d){
	void * * vector = malloc(sizeof(void*)* d->numElems);
	//COPIAR OS ELEMENTOS PARA O VECTOR
	int j=0;
	noSimples noAux;
	void * elem;
    for(int i=0;i<d->tamanho;i++){
        noAux = d->elems[i];
        while(noAux != NULL){
            elem = elemNoSimples(noAux);
            vector[j] = segTuplo(elem);
            noAux = segNoSimples(noAux);
            j++;
        }
    }
	return criaIterador(vector,d->numElems);
}


iterador iteradorChaveDicionario(dicionario d){
	void * * vector = malloc(sizeof(void*)* d->numElems);
	//COPIAR AS CHAVES DOS ELEMENTOS PARA O VECTOR
	int j=0;
	noSimples noAux;
	void * elem;
    for(int i=0;i<d->tamanho;i++){
        noAux = d->elems[i];
        while(noAux != NULL){
            elem = elemNoSimples(noAux);
            vector[j] = priTuplo(elem);
            noAux = segNoSimples(noAux);
            j++;
        }
    }
	return criaIterador(vector,d->numElems);
}




