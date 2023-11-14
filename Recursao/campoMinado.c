#include <stdio.h>
#include <string.h>

int contaBombas(int lin, int col, char mapaOriginal[lin][col], int x, int y){
    int qtdBombas = 0;

    x--;
    y--;

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if((x+i) < 0||(x+i) > (lin-1)||(y+j) < 0||(y+j) > (col-1)){
                break;
            }
            if(mapaOriginal[x+i][y+j] == 'X' && (i != 0 && j != 0)){
                qtdBombas++;
                printf("%d\n", qtdBombas);
            }
            printf("%d %d\n", (x+i), (y+j));
        }
    }

    printf("%d", qtdBombas);

    return qtdBombas;
} 

void alteraTela(int lin, int col, char mapaOriginal[lin][col], char mapaTela[lin][col], int x, int y){
    x--;
    y--;

    if(x < 0 || x > (lin-1) || y < 0 || y > (col-1)){
        return;
    }

    int qtd = contaBombas(lin, col, mapaOriginal, x, y);

    printf("Bombas em %d %d === %d\n", x, y, qtd);

    if(qtd == 0){
        alteraTela(lin, col, mapaOriginal, mapaTela, x - 1, y - 1);
        alteraTela(lin, col, mapaOriginal, mapaTela, x - 1, y);
        alteraTela(lin, col, mapaOriginal, mapaTela, x - 1, y + 1);
        alteraTela(lin, col, mapaOriginal, mapaTela, x, y - 1);
        alteraTela(lin, col, mapaOriginal, mapaTela, x, y + 1);
        alteraTela(lin, col, mapaOriginal, mapaTela, x + 1, y - 1);
        alteraTela(lin, col, mapaOriginal, mapaTela, x + 1, y);
        alteraTela(lin, col, mapaOriginal, mapaTela, x + 1, y + 1);
    }
    if(qtd > 0){
        mapaTela[x][y] = qtd;
        return;
    }
}

void printMatriz(int lin, int col, char mapaTela[lin][col]){
    printf("\n");
    for(int j = 0; j < col; j++){
        printf("=");
    }
    printf("\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%c", mapaTela[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int lin, col, qtdBombas, x, y, qtdAcoes;
    char acao[7];

    scanf("%d %d", &lin, &col);

    char mapaOriginal[lin][col];
    char mapaTela[lin][col];

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mapaTela[i][j] = '*';
            mapaOriginal[i][j] = '*';
        }
    }

    scanf("%d", &qtdBombas);

    for(int i = 0; i < qtdBombas; i++){
        scanf("%d %d", &x, &y);
        mapaOriginal[x-1][y-1] = 'X';
    }

    printf("\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%c", mapaOriginal[i][j]);
        }
        printf("\n");
    }

    scanf("%d", &qtdAcoes);
    getchar();

    for(int i = 0; i < qtdAcoes; i++){
        scanf("%[^ ]", acao);
        scanf("%d %d", &x, &y);
        getchar();
        printf("A acao eh:%s\n", acao);
        if(strcmp(acao, "Clica") == 0){
            contaBombas(lin, col, mapaOriginal, x, y);
        }
        if(strcmp(acao, "Marca") == 0){
            mapaTela[x-1][y-1] = 'B';
        }
        printMatriz(lin, col, mapaTela);

    }

}