#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    int valor;
    int peso;
}Item;

typedef struct{
    Item* objetos;
    int tam;
}Inventario;

void compara_melhor(Inventario *sacola, Inventario *melhor){
    int velho, novo;

    velho = novo = 0;

    for(int i = 0; i < sacola->tam; i++){
        novo += sacola->objetos[i].valor;
    }
    for(int i = 0; i < melhor->tam; i++){
        velho += melhor->objetos[i].valor;
    }

    if(novo > velho){
        melhor->tam = sacola->tam;

        for(int i = 0; i < sacola->tam; i++){
            melhor->objetos[i] = sacola->objetos[i];
        }
    }
}

void monta_inventario(Inventario caverna, Inventario *sacola, Inventario *melhor, int peso){
    //Sacola cheia
    if(peso == 0){
        compara_melhor(sacola, melhor);
    }
    //Senão, tenta colocar outro item
    else{
        for(int i = 0; i < caverna.tam; i++){
            //Tenta colocar o item
            if(caverna.objetos[i].peso <= peso && caverna.objetos[i].peso > -1){
                sacola->objetos[sacola->tam] = caverna.objetos[i];
                sacola->tam++;
                peso -= caverna.objetos[i].peso;
                caverna.objetos[i].peso = -1;

                //Chamar a recursão
                //testa todas as combinações com o item i
                monta_inventario(caverna, sacola, melhor, peso);
                        
                //Tirar o item da sacola para testar combinações com outros itens
                sacola->tam--;
                caverna.objetos[i] = sacola->objetos[sacola->tam];
                peso += caverna.objetos[i].peso;
            }
        }


    }
    //Não consigo mais colocar itens na sacola
    compara_melhor(sacola, melhor);

}


int main(){
    int qtd, peso;
    Inventario caverna, melhor, sacola;

    scanf("%d %d", &qtd, &peso);

    caverna.objetos = malloc(sizeof(Item) * qtd);
    melhor.objetos = malloc(sizeof(Item) * qtd);
    sacola.objetos = malloc(sizeof(Item) * qtd);

    caverna.tam = qtd;
    melhor.tam = sacola.tam = 0;

    for(int i = 0; i < qtd; i++){
        scanf(" %s %d %d", caverna.objetos[i].nome, &caverna.objetos[i].valor, &caverna.objetos[i].peso);
    }

    monta_inventario(caverna, &sacola, &melhor, peso);

    if(melhor.tam > 0){
        int valor = 0;
        printf("Inventario final:\n");

        for(int i = 0; i < melhor.tam; i++){
            printf("Item: %s\n", melhor.objetos[i].nome);
            valor += melhor.objetos[i].valor;
        }

        printf("Valor total: %d\n", valor);

    }else{
        printf("Nada para carregar...");
    }

}