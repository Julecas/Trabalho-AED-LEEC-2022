int main () {
    int i, j, x, y, numeroaux;
    int matriz[10];
    char stringaux[10], linha[100] = "12 1 100 20 40 2";

    printf("%s\n", linha);

    for (i = 0, j = 0, x = 0; i < 100; i++, j++) {
        if (linha[i] == ' ' || linha[i] == '\0') {
            stringaux[j] = '\0';
            numeroaux = atoi(stringaux);
            /*matriz[x] = numeroaux;*/
            i++;
            /*x++;*/
            j = 0;
            if (linha[i] == '\0') {
                break;
            }
        }
        stringaux[j] = linha[i];
    }

    for (y = 0; y < 11; y++) {
        printf("%d\n", matriz[y]);
        if (matriz[y] == '\0') {
            break;
        }
    }
}