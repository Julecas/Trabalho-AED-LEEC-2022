#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TADs usados */
#include "terreno.h"
#include "talhao.h"
#include "dicOrdenado.h"
#include "equipa.h"

#define SIZE 15
#define TAMANHO_INPUT_TESOURO 180

/* protótipos das funções usadas no main */

terreno parametrosIniciais();

void interpretador(terreno t);

int riquezaTerreno(terreno t);

void lerEquipas(terreno t);


int main(void){
	terreno t = parametrosIniciais();
    lerEquipas(t);
	interpretador(t);
	destroiTerreno(t);
	return 0;
}


terreno parametrosIniciais(){

int c,l,i, j, x, y, n, numeroaux;
char stringaux[10], linha[100];

fgets(linha, 100, stdin);
sscanf(linha,"%d %d",&l,&c);

int tesouro[l][c];

    for (i = 0; i < l; i++) {
      fgets(linha, 100, stdin);
      linha[strlen(linha) - 1] = '\0';
      for (x = 0, y = 0, j = 0, n = 0; n < c; x++, y++) {
          if (linha[x] == ' ' || linha[x] == '\0') {

              //scanf("%d", &tesouro[i][j]);
              stringaux[y] = '\0';
              numeroaux = atoi(stringaux);
              tesouro[i][j] = numeroaux;
              x++;
              j++;
              n++;
              y = 0;
              if (linha[x] == '\0') {
                  break;
              }
          }
          stringaux[y] = linha[x];
      }
    }
terreno t = criaTerreno(l,c,tesouro); 
return t; 
}

void lerEquipas(terreno t){
     char linha[100];
    int nEquipas;

    fgets(linha, 100, stdin);   /*ler o ficheiro*/
    sscanf(linha," %d",&nEquipas);
    
    FILE *fp;
    int n_membros, n_equipa = 1, opcao, i, j, x, y, n, numeroaux;
    int matriz[nEquipas];
    char stringaux[10], linha[100];
    char nome_equipa[100];
    char nomeArqueologo[SIZE];

    printf("Quais as equipas? ");
    fgets(linha, 100, stdin);
    linha[strlen(linha) - 1] = '\0';

    for(i = 0, j = 0, x = 0, n = 0; n < nEquipas; i++, j++) {
        if (linha[i] == ' ' || linha[i] == '\0') {
            stringaux[j] = '\0';
            numeroaux = atoi(stringaux);
            /*printf("Processou %s, converteu para %d\n", stringaux, numeroaux);*/
            matriz[x] = numeroaux;
            /*printf("Guardou %d (%d)\n", matriz[x], x);*/
            i++;
            x++;
            n++;
            j = 0;
            if (linha[i] == '\0') {
                break;
            }
        }
        stringaux[j] = linha[i];
    }

    for (x = 0; x < nEquipas; x++) {
      fp = fopen("teams.txt", "r");
      while (n_equipa - 1 < matriz[x]) 
      {
        fgets(linha, 10, fp);
        n_membros = atoi(linha);

        fgets(nome_equipa, 100, fp);
        nome_equipa[strlen(nome_equipa) - 1] = '\0';

        /* GUARDAR NOME DA EQUIPA NA TAD */

        if (n_equipa == matriz[x]) {
            
            printf("Equipa %s:\n", nome_equipa);
            adicionarEquipaDicOrdenadoPorNumTerreno(nome_equipa,n_equipa,t); /*MANTER OU ADAPTAR PARTE , BY:JULINHO*/
                
                for(i=0; i<n_membros;i++){
                    adicionaArqueologoEquipaTerreno(nomeArqueologo,n_equipa,t);
                }
          /* CRIAR EQUIPA - PARÂMETRO: NOME DA EQUIPA */            
        }                                                                     

        /*printf("Equipa %d, com o nome %s\n", n_equipa, nome_equipa);*/
        for (int i = 0; i < n_membros; i++) {
          fgets(linha, 200, fp);
          linha[strlen(linha) - 1] = '\0';
          if (n_equipa == matriz[x]) {
            printf("%s\n", linha);
          }
        }
        n_equipa++;
      }
      printf("\n");
      fclose(fp);
      n_equipa = 1;
    }

}

void interpretador(terreno t){

    int num_equipa, coord_x, coord_y;
    char primeiro_comando[10], string[100], nome_equipa[100], nome_arqueologo[100];
    
    while(1){   /*Repete até o utilizador usar COMANDO-SAIR*/
        printf("Introduza o comando: ");
        fgets(string, 100, stdin);
        string[strlen(string) - 1] = '\0';

        /*printf("\nO input foi: %s\n", linha);*/

        sscanf(string, "%s", primeiro_comando);

        /*printf("Processou a primeira parte como: -%s-\n", primeiro_comando);*/

        if(!strcmp("riqueza",primeiro_comando)){
            printf("Riqueza enterrada: %d\n",riquezaTerreno(t));
                    /* COMANDO-RIQUEZA*/
            /* COMANDO-RIQUEZA: não precisa de nenhum argumento extra*/
        }
        else if(!strcmp("terreno",primeiro_comando)){
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
                /* COMANDO-TERRENO: não precisa de nenhum argumento extra*/
        }
        else if(!strcmp("estrela",primeiro_comando)){
            printf("\nEXECUTAR COMANDO ESTRELA\n");
            /* COMANDO-ESTRELA: o argumento é o nome da equipa*/
            sscanf(string, "%s %[^\n]", primeiro_comando, nome_equipa);
            printf("\nEstrela de %s: (nome)\n", nome_equipa);
        }
        else if(!strcmp("escavacao",primeiro_comando)){
            printf("\nEXECUTAR COMANDO ESCAVACAO\n");
            /*COMANDO-ESCAVAÇÃO: os argumentos são o par de coordenadas e o nome da equipa*/
            sscanf(string, "%s %d %d %[^\n]", primeiro_comando, &coord_x, &coord_y, nome_equipa);
            printf("Equipa %s a fazer %s nas coordenadas (%d,%d)\n", nome_equipa, primeiro_comando, coord_x, coord_y);
        }
        else if(!strcmp("reforco",primeiro_comando)){
            printf("\nEXECUTAR COMANDO REFORCO\n");
            /*COMANDO-REFORÇO: inicialmente, apenas se escreve "reforco" na primeira linha, escrevendo individualmente cada argumento depois*/
            printf("Introduza a equipa: ");
            fgets(nome_equipa, 100, stdin);
            nome_equipa[strlen(nome_equipa) - 1] = '\0';


            printf("Introduza o arqueologo: ");
            fgets(nome_arqueologo, 100, stdin);
            nome_arqueologo[strlen(nome_arqueologo) - 1] = '\0';

            printf("Introduzido reforço com nome %s na equipa %s\n", nome_arqueologo, nome_equipa);
        }
        else if(!strcmp("equipa",primeiro_comando)){
            printf("\nEXECUTAR COMANDO EQUIPA\n");
            /*COMANDO-EQUIPA: o argumento é um inteiro com o número da equipa*/
            sscanf(string, "%s %d", primeiro_comando, &num_equipa);
            printf("\nAdicionada equipa %d\n", num_equipa);
        }
        else if(!strcmp("sair",primeiro_comando)){
            printf("\nEXECUTAR SAIDA\n");
            /*COMANDO-SAIR*/
        }
        else{
            printf("Comando invalido\n");
        }
    }
}


