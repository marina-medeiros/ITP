#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int colorir(int linhas, int colunas, char mapa[linhas][colunas], int visitados[linhas][colunas], int x, int y, char corNova, char corAtual){
    int encurralado;

    if(visitados[x][y-1] == 1 && visitados[x][y+1] == 1 && visitados[x-1][y] == 1 && visitados[x+1][y] == 1){
        return 1;
    }

    if(x < colunas && (y-1) < linhas && x > 0 && (y-1) > 0 && visitados[x][y-1] == 0 && mapa[x][y-1] == corAtual && mapa[x][y] == corAtual){
        mapa[x][y-1] = corNova;
        mapa[x][y] = corNova;
        visitados[x][y] = 1;
        encurralado = colorir(linhas, colunas, mapa, visitados, x, (y-1), corNova, corAtual);
        
        if(encurralado){
            return 1;
        } 
    }
    if((x-1) < colunas && y < linhas && (x-1) > 0 && y > 0 && visitados[x-1][y] == 0 && mapa[x-1][y] == corAtual && mapa[x][y] == corAtual){
        mapa[x+1][y] = corNova;
        mapa[x][y] = corNova;
        visitados[x][y] = 1;
        encurralado = colorir(linhas, colunas, mapa, visitados, (x-1), y, corNova, corAtual);
        
        if(encurralado){
            return 1;
        } 
    }
    if((x+1) < colunas && y < linhas && (x+1) > 0 && y > 0 && visitados[x+1][y] == 0 && mapa[x+1][y] == corAtual && mapa[x][y] == corAtual){
        mapa[x+1][y] = corNova;
        visitados[x][y] = 1;
        encurralado = colorir(linhas, colunas, mapa, visitados, (x+1), y, corNova, corAtual);
        
        if(encurralado){
            return 1;
        } 
    }
    if(x < colunas && (y+1) < linhas && x > 0 && (y+1) > 0 && visitados[x][y+1] == 0 && mapa[x][y+1] == corAtual && mapa[x][y] == corAtual){
        mapa[x][y+1] = corNova;
        mapa[x][y] = corNova;
        visitados[x][y] = 1;
        encurralado = colorir(linhas, colunas, mapa, visitados, x, (y+1), corNova, corAtual);
        
        if(encurralado){
            return 1;
        }
    }


    return 0;
}

int main(){
    int lin, col, x, y;
    char cor;

    scanf("%d %d", &lin, &col);
    getchar();

    char mapa[lin][col];
    int visitados[lin][col];

    memset(visitados, 0, sizeof(visitados));

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%c", &mapa[i][j]);
        }
        getchar();
    }

    scanf("%d %d", &x, &y);

    scanf(" %c", &cor);

    colorir(lin, col, mapa, visitados, x, y, cor, mapa[x][y]);

    printf("PRINT:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
    printf("PRINT:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d", visitados[i][j]);
        }
        printf("\n");
    }
}