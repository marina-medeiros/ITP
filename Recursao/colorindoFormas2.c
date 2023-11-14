#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMapa(int lin, int col, char mapa[lin][col]){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

void colorir(int lin, int col, char mapa[lin][col], int x, int y, char corNova, char corAtual){
    if(x > lin || x < 0 || y > col || y < 0 || mapa[x][y] != corAtual){
        return;
    }

    mapa[x][y] = corNova;

    colorir(lin, col, mapa, (x-1), y, corNova, corAtual);
    colorir(lin, col, mapa, (x+1), y, corNova, corAtual);
    colorir(lin, col, mapa, x, (y+1), corNova, corAtual);
    colorir(lin, col, mapa, x, (y-1), corNova, corAtual);
}

int main(){
    int lin, col, x, y;
    char cor;

    scanf("%d %d", &lin, &col);
    getchar();

    char mapa[lin][col];

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%c", &mapa[i][j]);
        }
        getchar();
    }
    
    scanf("%d %d", &x, &y);

    scanf(" %c", &cor);

    colorir(lin, col, mapa, x, y, cor, mapa[x][y]);

    printMapa(lin, col, mapa);
}