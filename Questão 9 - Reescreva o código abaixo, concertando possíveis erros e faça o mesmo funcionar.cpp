#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

struct Aluno alunos[3];

void listarAlunos() {
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\nDigite os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome); 
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        getchar();
    }
    listarAlunos();
    
    return 0;
}



