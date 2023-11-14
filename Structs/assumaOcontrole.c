#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
}Pessoa;

Pessoa* inserir(int qtdEntradas, Pessoa lista[qtdEntradas], int *posNome, char* nome){
    strcpy(nome, lista[*posNome].nome);
    (*posNome)++;

    return lista;
}

Pessoa* remover(int qtdEntradas, Pessoa lista[qtdEntradas], int *posNome, char* nome){
    int posDel, aux = 0;
    for(int i = 0; i < *posNome; i++){
        if(strcmp(lista[i].nome, nome) == 0){
            posDel = i;
            aux = 1;
        }
    }
    if(aux){
        for(int i = posDel; i < (*posNome-1); i++){
            lista[i] = lista[i+1];
        }
    }

    (*posNome)--;

    return lista;
}

void imprimir(int qtdEntradas, Pessoa lista[qtdEntradas], int *posNome){
    for(int i = 0; i < *posNome; i++){
        printf("%s", lista[i].nome);
    }
}

int main(){
    int qtdEntradas, posNome = 0;
    char entrada[50];
    char acao[11];
    char nome[20];

    scanf("%d", &qtdEntradas);
    printf("%d\n", qtdEntradas);

    Pessoa lista[qtdEntradas];

    scanf("%[^\n]", entrada);
    
    for(int i = 0; i < qtdEntradas; i++){
        scanf("%s ", acao);
        scanf("%[^\n]", nome);
        printf("oi");
        if(strcmp(acao, "INSERIR") == 0){
            inserir(qtdEntradas, lista, &posNome, nome);
        }
        if(strcmp(acao, "REMOVER") == 0){
            remover(qtdEntradas, lista, &posNome, nome);
        }
        if(strcmp(acao, "IMPRIMIR") == 0){
            printf("Atualmente trabalhando:");
            imprimir(qtdEntradas, lista, &posNome);
        }
    }
}