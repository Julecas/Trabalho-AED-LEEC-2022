#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void lerEquipas(terreno t){
    
    char linha[100];
    int nEquipas;

    FILE *fp;
    fp=fopen("teams.txt","r");
    if(fp==NULL)
        printf("Não foi possivel abrir o ficheiro");

    if(fp != NULL){
        while(fscanf(fp," %d\n",&nArqueologo))
    }
    