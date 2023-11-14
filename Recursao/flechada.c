#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    int valor;
    int peso;
}Item;

void contaitens(int pesoMax, Item *listaItens){

}


int main(){
    int pesoMax, qtdItens;
    Item *listaItens;

    scanf("%d %d", &qtdItens, &pesoMax);
    getchar();

    listaItens = malloc(sizeof(Item) * qtdItens);

    for(int i = 0; i < qtdItens; i++){
        scanf("%[^ ]", listaItens[i].nome);
        scanf(" %d %d", &listaItens[i].valor, &listaItens[i].peso);
    }

    for(int i = 0; i < qtdItens; i++){
        printf("%s %d %d", listaItens[i].nome, listaItens[i].valor, listaItens[i].peso);
    }
}