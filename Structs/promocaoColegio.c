#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    float nota;
}Aluno;

int main(){
    int qtdAlunosA = 0, qtdAlunosB = 0;
    float  somaNotasA = 0, somaNotasB = 0, mediaA, mediaB;
    Aluno *turmaA;
    Aluno *turmaB;
    Aluno maiorNota;

    maiorNota.nota = 0;

    turmaA = malloc(sizeof(Aluno) * (qtdAlunosA + 1));
    turmaB = malloc(sizeof(Aluno) * (qtdAlunosB + 1));

    char nome[20] = "x";

    do{
        scanf("%s", nome);

        if(strcmp(nome, "*") != 0){
            strcpy(turmaA[qtdAlunosA].nome, nome);
            getchar();
            scanf("%f", &turmaA[qtdAlunosA].nota);
            if(turmaA[qtdAlunosA].nota > maiorNota.nota){
                maiorNota.nota = turmaA[qtdAlunosA].nota;
                strcpy(maiorNota.nome, turmaA[qtdAlunosA].nome);
            }
            somaNotasA += turmaA[qtdAlunosA].nota;
            qtdAlunosA++;
            turmaA = realloc(turmaA, sizeof(Aluno) * (qtdAlunosA + 1));
        }
    }while(strcmp(nome, "*") != 0);

    do{
        scanf("%s", nome);

        if(strcmp(nome, "*") != 0){
            strcpy(turmaB[qtdAlunosB].nome, nome);
            getchar();
            scanf("%f", &turmaB[qtdAlunosB].nota);
            if(turmaB[qtdAlunosB].nota > maiorNota.nota){
                maiorNota.nota = turmaB[qtdAlunosB].nota;
                strcpy(maiorNota.nome, turmaB[qtdAlunosB].nome);
            }
            somaNotasB += turmaB[qtdAlunosB].nota;
            qtdAlunosB++;
            turmaB = realloc(turmaB, sizeof(Aluno) * (qtdAlunosB + 1));
        }
    }while(strcmp(nome, "*") != 0);

    mediaA = somaNotasA / qtdAlunosA;
    mediaB = somaNotasB / qtdAlunosB;


    if(mediaA > 8 && mediaB > 8){
        printf("Viagem para todos!\n");
    }
    else if(mediaA > 8 && mediaB < 8){
        printf("Viagem para turma A\n");
    }
    else if(mediaA < 8 && mediaB > 8){
        printf("Viagem para turma B\n");
    }
    else if(mediaA < 8 && mediaB < 8){
        printf("Nenhuma das turmas viaja...\n");
    }

    if(maiorNota.nota > 8){
        printf("%s ganhou viagem e ingresso no parque!\n", maiorNota.nome);
        printf("Nota: %.2f\n", maiorNota.nota);
    }else{
        printf("Ninguem ganhou viagem e ingresso no parque...");
    }
}