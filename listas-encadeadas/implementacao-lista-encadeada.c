#include <stdio.h>

typedef struct aluno{
    int matricula;
    float nota;
    char nome[50];    
}Alunos;

void cadastrar (int quantidade_aluno){
    FILE *arquivo = fopen ("dados.dat", "wb");
    Alunos aluno_lido;
    int index;
    printf ("informe o nome do aluno: \n");
    for (index=0; index < quantidade_aluno; index++){
        scanf("%d", &aluno_lido.matricula);
        scanf(" %[^\n]", aluno_lido.nome);
        scanf("%f", &aluno_lido.nota);
        fwrite(&aluno_lido, sizeof(Alunos), 1, arquivo);
    }
    fclose(arquivo);
}

void imprimir (void){
FILE *arquivo = fopen("dados.dat", "rb");
Alunos aluno_lido;

while(fread (&aluno_lido, sizeof (Alunos), 1, arquivo)){
    printf("Matricula:%d\tNome:%s\tNota:%.2f\n", aluno_lido.matricula, aluno_lido.nome, aluno_lido.nota);
}
fclose(arquivo);
}

void contar (void){
    FILE *arquivo = fopen ("dados.dat", "rb");
    Alunos aluno_lido;
    int contador=0;
    while(fread(&aluno_lido,sizeof (Alunos), 1, arquivo)){
        contador++;
    }
    printf("total:%d", contador);
    fclose(arquivo);
}

int main (void){
    cadastrar(3);
    return 0;
}
