#include <stdio.h>
#include <stdlib.h>

// 1. Criando uma Struct para organizar os dados na memória
struct Aluno {
    char nome[50];
    float nota1, nota2, nota3;
    float media;
};

int main() {
    FILE *arquivoEntrada;
    FILE *arquivoSaida;
    
    //armazenar até 50 alunos
    struct Aluno turma[50]; 
    int quantidadeAlunos = 0;

    arquivoEntrada = fopen("entrada-q1.txt", "r");
    
    if (arquivoEntrada == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo de entrada!\n");
        return 1;
    }

    while (fscanf(arquivoEntrada, "%49s %f %f %f", turma[quantidadeAlunos].nome, 
                  &turma[quantidadeAlunos].nota1, 
                  &turma[quantidadeAlunos].nota2, 
                  &turma[quantidadeAlunos].nota3) == 4) {
    
        turma[quantidadeAlunos].media = (turma[quantidadeAlunos].nota1 + turma[quantidadeAlunos].nota2 + turma[quantidadeAlunos].nota3) / 3.0;
        
        quantidadeAlunos++;
    }
    
    fclose(arquivoEntrada);

    arquivoSaida = fopen("saida_q1.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo de saida!\n");
        return 1;
    }

    //Escrevendo os aprovados (Media >= 7.0)
    fprintf(arquivoSaida, "Alunos Aprovados\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        if (turma[i].media >= 7.0) {
            fprintf(arquivoSaida, "Nome: %s | Media: %.2f\n", turma[i].nome, turma[i].media);
        }
    }

    fprintf(arquivoSaida, "\n");

    //Escrevendo a seção de Reprovados (Média < 7.0)
    fprintf(arquivoSaida, "Alunos Reprovados\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        if (turma[i].media < 7.0) {
            fprintf(arquivoSaida, "Nome: %s | Media: %.2f\n", turma[i].nome, turma[i].media);
        }
    }

    // Fechando o arquivo de saída
    fclose(arquivoSaida);

    printf("Sucesso! Os dados foram processados e salvos em 'saida_q1.txt'.\n");

    return 0;
}