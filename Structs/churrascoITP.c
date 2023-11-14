#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int preco;
    int qtd;
}Item;

Item* cadastraItem(Item *listaItens, int* posItem){
    Item added;
    scanf("%[^\n]", added.nome);
    scanf("%d", &added.preco);
    scanf("%d", &added.qtd);

    listaItens[*posItem] = added;
    (*posItem)++;
    listaItens = realloc(listaItens, sizeof(Item) * (*posItem + 1));

    return listaItens;
}

float somaValores(Item *listaItens, int* posItem){
    int soma = 0;

    for(int i = 0; i < *posItem; i++){
        soma += listaItens[i].preco * listaItens[i].qtd;
    }

    return soma;
}

int main(){
    int acao = 0;
    int qtdPessoas = 0;
    int posItem = 0;
    Item *vetorDeItens = malloc(sizeof(Item) * (posItem + 1));

    while(acao != 2){
        vetorDeItens = cadastraItem(vetorDeItens, &posItem);
        scanf("%d", &acao);
        getchar();
    }

    scanf("%d", &qtdPessoas);

    float valor = somaValores(vetorDeItens, &posItem);

    printf("Valor: R$ %.2f\n", valor);
    printf("Divisão R$ %.2f para cada participante.", (valor / qtdPessoas));
}