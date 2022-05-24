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
	destroiTerreno(t);
	return 0;
}


terreno parametrosIniciais(){

int c,l,i,j;
char linha[100];

fgets(linha, 100, stdin); // Obter input das linhas e colunas do terreno.
sscanf(linha,"%d %d",&l,&c);

int tesouro[l][c]; // Matriz inicial que irá guardar os valores dos tesouros para os guardar.

for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
        scanf(" %d", &tesouro[i][j]);
    }
}
  
return criaTerreno(l,c,tesouro); 
}

void lerEquipas(terreno t){
    FILE *fp;
    int nEquipasTotal, n_membros, n_equipa = 1, i, num;
    char linha[100];
    char nome_equipa[100];

    fp = fopen("teams.txt", "r");

    // Adicionar equipas no ficheiro ao dicionário por inteiros
    while (fscanf(fp, "%d\n", &n_membros) != EOF) { 
      fscanf(fp, "%[^\n]\n", nome_equipa);   
      
      adicionarEquipaDicOrdenadoPorNumTerreno(nome_equipa,n_equipa,t);

      for (i = 0; i < n_membros; i++) {
        fscanf(fp, "%[^\n]\n", linha);

        adicionaArqueologoEquipaTerreno(linha,n_equipa,t);
      }
      n_equipa++;
    }
    fclose(fp);

    // Obter o input de quantas equipas entram no concurso.
    scanf(" %d", &nEquipasTotal);

    for (i = 0; i < nEquipasTotal; i++) {
      scanf(" %d", &num);

      adicionaAoOutroDicionarioTerreno(num,t);
    }
    scanf("\n"); // Ler o \n pois estava a ser lido no interpretador.
}

void interpretador(terreno t){

    int num_equipa, saltoL, saltoC;
    char primeiro_comando[10], string[100], nome_equipa[100] /*nome_arqueologo[100]*/;
    
    while(1){   // Continua no loop até o utilizador usar o comando "sair", que contêm um return.
        fgets(string, 100, stdin);
        string[strlen(string) - 1] = '\0';

        sscanf(string, "%s", primeiro_comando);

        if (!strcmp("riqueza",primeiro_comando)) {
            printf("Riqueza enterrada: %d\n",riquezaTerreno(t));
        }
        else if (!strcmp("terreno",primeiro_comando) ){
            for (int i=0; i<linhasTerreno(t); i++) {
                for(int j=0; j<colunasTerreno(t); j++){
                    if(estadoTerreno(t,i,j)){
                        printf("*");
                    } 
                    else  
                        printf("-");     
                }
                printf("\n");   
            }
        }
        else if(!strcmp("estrela",primeiro_comando)){
            sscanf(string, "%s %[^\n]", primeiro_comando, nome_equipa);
            if (existeEquipaEmJogoNoTerreno(t, nome_equipa)) {
                printf("Estrela de %s: %s\n", nome_equipa,  procuraEstrelaTerreno(t,nome_equipa));
            }
            else {
                printf("Equipa invalida\n");
            }
        }
        else if(!strcmp("escavacao",primeiro_comando)){
            sscanf(string, "%s %d %d %[^\n]", primeiro_comando, &saltoL, &saltoC, nome_equipa);

            // Se ambos os valores de salto forem 0, o input não pode ser aceite.
            if(!(saltoL == 0 && saltoC == 0)) { 
                if (existeEquipaEmJogoNoTerreno(t, nome_equipa)) {
                    escavarTerreno(t, nome_equipa, saltoL, saltoC);
                    // Usar o escavarTerreno para verificar se a equipa foi expulsa ou não!!!!!
                    if (!existeEquipaEmJogoNoTerreno(t, nome_equipa)) { // Verificar que a equipa foi expulsa após a escavação.
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
        /*else if(!strcmp("reforco",primeiro_comando)){
            COMANDO-REFORÇO: inicialmente, apenas se escreve "reforco" na primeira linha, escrevendo individualmente cada argumento depois
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
                    printf("Arqueologo invalido\n");
                }
            }
            else {
                printf("Equipa invalida\n");
            }

            //printf("Introduzido reforço com nome %s na equipa %s\n", nome_arqueologo, nome_equipa);
        }*/
        else if(!strcmp("equipa",primeiro_comando)){ 
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
                    /*printf("classificacao\n");       
                    
                    int num = quantasEquipasEmJogoNoTerreno(t);

                    for(int i=0;i<num;i++) {
                        //printf("i = %d\n", i);
                        equipa e = obterERemoverDoDicMelhorEquipaNoTerreno(t);
                        printf("%s: %d pts; %d descl.; %d com lic.\n", nomeEquipa(e), totalPontosEquipa(e), quantosArqueologosExpulsosNaEquipa(e), tamanhoEquipa(e) - quantosArqueologosExpulsosNaEquipa(e));
                    }*/
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

