/*
MANIPULAÇAO DE ARQUIVOS

dados.txt
fopen : abre o arquivo
fclose : fecha o arquivo
fprintf, fputc, fputs: ler no arquivo
fsacanf, fgetc, fgets, sscanf: ler dados do arquivo

dados.dat
fopen : abre o arquivo
fclose: fecha o arquivo
fwrite escrever no arquivo: fwrite(&var, tmanho, 1, arquivo )
fread: ler do arquivo: fread(&var , tamanho, 1, arquivo)
*/

#include <stdio.h>

int main (void){
    int inteiro, conteudo;
    
    FILE *arquivo = fopen("dados.dat", "w");
    printf("Digite um numero inteiro: \t");
    scanf("%d" , &inteiro);
    
    //Escrita do arquivo 
    fwrite(&inteiro, sizeof(int), 1, arquivo);
    fclose(arquivo);
    
    //Ler
    arquivo = fopen("dados.dat", "rb");
    fread(&conteudo, sizeof(int), 1, arquivo);
    printf("conteudo lido: %d, conteudo");
    fclose(arquivo);
    return 0;
}