#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COLUNAS 5
#define LINHAS 10

int main () {
    int i, j, x, y, n, numeroaux;
    int matriz[LINHAS][COLUNAS];
    char stringaux[10], linha[100];

    for (x = 0; x < LINHAS; x++) {
      fgets(linha, 100, stdin);
      for (i = 0, j = 0, y = 0, n = 0; n < COLUNAS; i++, j++) {
          if (linha[i] == ' ' || linha[i] == '\0') {
              stringaux[j] = '\0';
              numeroaux = atoi(stringaux);
              /*printf("Processou %s, converteu para %d\n", stringaux, numeroaux);*/
              matriz[x][y] = numeroaux;
              i++;
              y++;
              n++;
              j = 0;
              if (linha[i] == '\0') {
                  break;
              }
          }
          /*printf(".");*/
          stringaux[j] = linha[i];
      }
    }
    
    printf("\n");
    for (x = 0; x < LINHAS; x++) {
      for (y = 0; y < COLUNAS; y++) {
        printf("%d ", matriz[x][y]);
      }
      printf("\n");
    }
}