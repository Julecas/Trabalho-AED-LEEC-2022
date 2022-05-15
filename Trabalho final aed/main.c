#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TADs usados */
#include "terreno.h"
#include "talhao.h"

#define SIZE 15
#define TAMANHO_INPUT_TESOURO 180

/* protótipos das funções usadas no main */

terreno parametrosIniciais();

void interpretador(terreno t);

int riquezaTerreno(terreno t);



int main(void){
	terreno t = parametrosIniciais();
	interpretador(t);

	return 0;
}


terreno parametrosIniciais(){

int linha[SIZE], linha_input[TAMANHO_INPUT_TESOURO];
int c,l,tesouroInput, i, j, x, y;


sscanf(linha,"%d %d",&l,&c);

int tesouro[l][c];

/*for(int i=0; i<l ;i++){
        for(int j=0; j<c ;j++){
                 sscanf(linha,"%s",&tesouroInput);
                    tesouro[i][j] = tesouroInput;
                }
            } */

int i, j, x, y, n, numeroaux;
    int matriz[l][c];
    char stringaux[10], linha[1000]; // CUIDADO!

    for (x = 0; x < l; x++) {
      fgets(linha, 100, stdin);
      for (i = 0, j = 0, y = 0, n = 0; n < c; i++, j++) {
          if (linha[i] == ' ' || linha[i] == '\0') {
              stringaux[j] = '\0';
              numeroaux = atoi(stringaux);
              printf("Processou %s, converteu para %d\n", stringaux, numeroaux);
              matriz[x][y] = numeroaux;
              i++;
              y++;
              n++;
              j = 0;
              if (linha[i] == '\0') {
                  break;
              }
          }
          printf(".");
          stringaux[j] = linha[i];
      }
    }
terreno t = criaTerreno(l,c,tesouro);
return t;
}

void interpretador(terreno t){

    char linha[SIZE];

    while(1){   /*Repete até o utilizador usar COMANDO-SAIR*/

        fgets(linha,SIZE,stdin);

        if(!strcmp("riqueza",linha)){
        printf("Riqueza enterrada: %d\n",riquezaTerreno(t));
            /* COMANDO-RIQUEZA*/
        }
        else if(!strcmp("terreno",linha)){

            for(int i=0; i<linhasTerreno(t) ;i++){
                for(int j=0; j<colunasTerreno(t) ;j++){

                    if(estadoTerreno(t,i,j)){
                        printf("*");
                    } else
                        printf("-");
                }
             printf("\n") ;
               /* COMANDO-TERRENO*/
            }
        }
        else if(!strcmp("estrela",linha)){
            /* COMANDO-ESTRELA*/
        }
        else if(!strcmp("escavacao",linha)){
            /*COMANDO-ESCAVAÇÃO*/
        }
        else if(!strcmp("reforco",linha)){
            /*COMANDO-REFORÇO*/
        }
        else if(!strcmp("equipa",linha)){
            /*COMANDO-EQUIPA*/
        }
        else if(!strcmp("sair",linha)){
            /*COMANDO-SAIR*/
        }
        else{
            printf("Comando invalido\n");
        }
    }
}
