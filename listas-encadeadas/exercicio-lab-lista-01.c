#include <stdio.h>

int main() {
    int n, menor, maior, soma = 0;
    float media;

    FILE *entrada = fopen("entrada_q2.txt", "r");
    if (entrada == NULL) 
    return 1;

    for (int i = 0; i < 10; i++){
        fscanf(entrada, "%d", &n);
        soma += n;
        if (i == 0) {
            menor = maior = n;
        } else {
            if (n < menor) menor = n;
            if (n > maior) maior = n;
        }
    }
    fclose(entrada);

    media = soma /10.0;

    FILE *saida = fopen("saida_q2.txt", "w");
    if (saida == NULL) 
    return 1;

    fprintf(saida, "menor elemento: %d\n", menor);
    fprintf(saida, "maior elemento: %d\n", maior);
    fprintf(saida, "media dos elementos: %f\n", media);
    fclose(saida);
    return 0;
}