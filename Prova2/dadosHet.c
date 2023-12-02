#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[20];
    float preco;
    } Produto;

void read_line(char linha[30], int tam) {
    fgets(linha, tam, stdin);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1]='\0'; //remove o \n do final
}

void imprimeProdutos(Produto prod[], int qtdprod) {
    printf("========================================\n");
    printf("| Código | Descrição       | Preço     |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < qtdprod; i++) {
        printf("| %6d ", prod[i].codigo);
        printf("| %15s ", prod[i].descricao);
        printf("| R$ %6.2f |\n", prod[i].preco);
    }
    printf("----------------------------------------\n");
}

int main(){
    Produto *listaDeProdutos = NULL;
    Produto lido;
    int qtdProdutos = 1, aux;
    char linha[30];

    listaDeProdutos = (Produto*)malloc(sizeof(Produto) * qtdProdutos);

    do{
        aux = 0;
        read_line(linha, 30);

        if(linha[0] == '\0'){
            break;
        }

        lido.codigo = atoi(strtok(linha, ","));
        strcpy(lido.descricao, strtok(NULL, ","));
        lido.preco = atof(strtok(NULL, ","));

        for(int i = 0; i < qtdProdutos; i++){
            if(listaDeProdutos[i].codigo == lido.codigo){
                aux++;
                break;
            }
        }

        if(aux == 0){
            listaDeProdutos[qtdProdutos-1] = lido;
            qtdProdutos++;
        }

        listaDeProdutos = realloc(listaDeProdutos, sizeof(Produto) * qtdProdutos);
    }while(linha[0] != '\0');

    imprimeProdutos(listaDeProdutos, (qtdProdutos-1));
}