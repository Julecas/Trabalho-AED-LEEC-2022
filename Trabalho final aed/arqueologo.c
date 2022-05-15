#include "arqueologo.h"

#define SIZE 40

/* TAD simples */
struct _arqueologo {
    int pontos;
    char nome[40];
    int i,j;        /*posição i - (linha), j - (coluna) do arqueologo*/ 
};