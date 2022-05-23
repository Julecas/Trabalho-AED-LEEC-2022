#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TADs usados */
#include "terreno.h"
#include "talhao.h"
#include "dicOrdenado.h"
#include "equipa.h"

// #define SIZE 15 DEFINIR UM STRING PARA NÃO USAR O 100 NA LINHA, POR EXEMPLO!!!
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
    //printf("Saiu do interpretador!\n");
	destroiTerreno(t);
    //printf("Destruiu terreno!\n");
	return 0;
}


terreno parametrosIniciais(){

int c,l,i,j;
char linha[100];

fgets(linha, 100, stdin);
sscanf(linha,"%d %d",&l,&c);

int tesouro[l][c]; // caso dê erro no mooshak mudar para malloc

for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
        scanf(" %d", &tesouro[i][j]);
    }
}

/*for (i = 0; i < l; i++) {
      for (j = 0; j < c; j++) {
        printf("%d ", tesouro[i][j]);
      }
      printf("\n");
    }*/
  
terreno t = criaTerreno(l,c,tesouro); 
return t; 
}

void lerEquipas(terreno t){
    FILE *fp;
    int nEquipasTotal, n_membros, n_equipa = 1, i;
    char linha[100];
    char nome_equipa[100];

    fp = fopen("teams.txt", "r");

    while (fscanf(fp, "%d\n", &n_membros) != EOF) {
      fscanf(fp, "%[^\n]\n", nome_equipa);   
      
      adicionarEquipaDicOrdenadoPorNumTerreno(nome_equipa,n_equipa,t);
      
      // printf("Equipa %s: (%d membros)\n", nome_equipa, n_membros);

      for (i = 0; i < n_membros; i++) {
        fscanf(fp, "%[^\n]\n", linha);
        adicionaArqueologoEquipaTerreno(linha,n_equipa,t);

        //printf("%s\n", linha);
      }
      n_equipa++;
      //printf("\n");
    }
    fclose(fp);

    
    //printf("Quantas equipas? ");
    
    /*fgets(linha, 100, stdin);   //ler o ficheiro
    sscanf(linha," %d",&nEquipasTotal);*/

    scanf(" %d", &nEquipasTotal);
    //printf("Leu %d\n", nEquipasTotal);

        int matriz[nEquipasTotal]; // SE FOR PRECISO USAR MALLOC CASO DÊ MAL NO MOOSHAK

    //printf("Quais as equipas?\n ");

    for (i = 0; i < nEquipasTotal; i++) {
      // DAR FLUSH ERA BACANO PARA NÃO EXISTIR OVERFLOW DE OUTRAS LINHAS
      scanf(" %d", &matriz[i]);
      /*printf("\nMATRIZ:\n");
      printf("%d ", matriz[i]);*/

      adicionaAoOutroDicionarioTerreno(matriz[i],t);
    } // daqui sai (1, 3, 5) por exemplo
    scanf("\n"); // 
    /*printf("\nMATRIZ:");
    for (i = 0; i < nEquipasTotal; i++) {
        printf("%d ", matriz[i])
    }*/
}

void interpretador(terreno t){

    int num_equipa, saltoL, saltoC;
    char primeiro_comando[10], string[100], nome_equipa[100], nome_arqueologo[100];
    
    while(1){   /*Repete até o utilizador usar COMANDO-SAIR*/
        //printf("Introduza o comando:\n");
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
            //printf("\nEXECUTAR COMANDO ESTRELA\n");
            /* COMANDO-ESTRELA: o argumento é o nome da equipa*/
            sscanf(string, "%s %[^\n]", primeiro_comando, nome_equipa);
            //printf("\nEstrela de %s: (nome)\n", nome_equipa);
            if (existeEquipaEmJogoNoTerreno(t, nome_equipa)) {
                printf("Estrela de %s: %s\n", nome_equipa,  procuraEstrelaTerreno(t,nome_equipa));
            }
            else {
                printf("Equipa invalida\n");
            }
        }
        else if(!strcmp("escavacao",primeiro_comando)){
            //printf("\nEXECUTAR COMANDO ESCAVACAO\n");
            /*COMANDO-ESCAVAÇÃO: os argumentos são o par de coordenadas e o nome da equipa*/
            sscanf(string, "%s %d %d %[^\n]", primeiro_comando, &saltoL, &saltoC, nome_equipa);

            //printf("Equipa %s a fazer %s nas coordenadas (%d,%d)\n", nome_equipa, primeiro_comando, coord_x, coord_y);

            if(!(saltoL == 0 && saltoC == 0)) { // Se ambos os valores de salto forem 0, o input não pode ser aceite
                if (existeEquipaEmJogoNoTerreno(t, nome_equipa)) {

                    escavarTerreno(t, nome_equipa, saltoL, saltoC);

                    /******
                     Temos que imprimir se a equipa foi desclassificada logo a fazer a escavação.
                     Pensei numa coisa assim:
                    *****/


                    if (!existeEquipaEmJogoNoTerreno(t, nome_equipa)) { // Se 
                        printf("%s foi expulsa\n", nome_equipa);
                    }
                }
                else {
                    printf("Equipa invalida\n");
                }
            }
            else {
                printf("Salto invalido\n");
            }
        }
        else if(!strcmp("reforco",primeiro_comando)){
            /*COMANDO-REFORÇO: inicialmente, apenas se escreve "reforco" na primeira linha, escrevendo individualmente cada argumento depois*/
            printf("Introduza a equipa: ");
            fgets(nome_equipa, 100, stdin);
            nome_equipa[strlen(nome_equipa) - 1] = '\0';


            printf("Introduza o arqueologo: ");
            fgets(nome_arqueologo, 100, stdin);
            nome_arqueologo[strlen(nome_arqueologo) - 1] = '\0';

            if (existeEquipaEmJogoNoTerreno(t, nome_equipa)) {
                if (!existeArqueologoNaEquipaTerreno(t, nome_equipa, nome_arqueologo)) {
                    adicionarReforcoEquipaTerreno(t, nome_equipa, nome_arqueologo);
                }
                else {
                    print("Arqueologo invalido\n");
                }
            }
            else {
                printf("Equipa invalida\n");
            }

            //printf("Introduzido reforço com nome %s na equipa %s\n", nome_arqueologo, nome_equipa);
        }
        else if(!strcmp("equipa",primeiro_comando)){ // !!! o programa crasha se colocares um valor abaixo de 1, não sei se isso é preocupante ou não 
            /*COMANDO-EQUIPA: o argumento é um inteiro com o número da equipa*/
            sscanf(string, "%s %d", primeiro_comando, &num_equipa);
            //printf("\nAdicionada equipa %d\n", num_equipa);

            if (num_equipa <= tamanhoDicOrdenadoPorNumTerreno(t)) {
                if (!(existeEquipaNoOutroDicTerreno(t, num_equipa))) {
                    adicionaAoOutroDicionarioTerreno(num_equipa,t);
                }
                else {
                    printf("Equipa invalida\n");
                }
            }
            else {
                printf("Equipa inexistente\n");
            }
        }
        else if(!strcmp("sair",primeiro_comando)){
            if (existeAlgumaEquipaEmJogoNoTerreno(t)){
            

                if (riquezaTerreno(t)){  
                    printf("Ainda havia tesouros por descobrir...\n");
                }    
                else {
                    printf("Todos os tesouros foram descobertos!\n");
                }
                    printf("classificacao\n");       
                    
                    for(int i=0;i <quantasEquipasNoTerreno(t);i++) {
                        if (equipaEstaEmJogoTerreno()) {
                            printf("%s: %d pts; %d descl.; %d com lic.\n");
                        }
                    }
                    //classificaEquipasTerreno(t);
                      
    
            }
            else{
            printf("Todas as equipas foram expulsas.\n");
            }
        return;
        }    
        else{
            printf("Comando invalido\n");
        }
    }
}

