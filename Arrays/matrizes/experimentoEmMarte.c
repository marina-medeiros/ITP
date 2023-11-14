#include <stdio.h>

int CalcValorArea(int n, int m, int matriz[n][m], int a, int b){
    int i, j, valorArea = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            valorArea += matriz[a+i][b+j];
        }
    }
    return valorArea;
}

int main() {
    int i, j, N, M, S, x, y, menorValor;
    int temIgual = 0;

    scanf("%d %d %d", &N, &M, &S);

    int mapa[N][M];


    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            scanf(" %d", &mapa[i][j]);
        }
    }

    for(i = 0; i < (N-2); i++){
        for(j = 0; j < (M-2); j++){
            if(CalcValorArea(N, M, mapa, i, j) == S){
                printf("A melhor area para exploracao eh %d %d com valor 0", (i+1), (j+1));
                temIgual++;
                break;
            }
        }
    }

    if(temIgual == 0){
        if((CalcValorArea(N, M, mapa, 0, 0) - S) < 0){
            menorValor = ((CalcValorArea(N, M, mapa, 0, 0) - S) * (-1));
        }
        else{
            menorValor = (CalcValorArea(N, M, mapa, 0, 0) - S);
        }
        for(i = 0; i < (N-2); i++){
            for(j = 0; j < (M-2); j++){
                if((CalcValorArea(N, M, mapa, i, j) - S) < 0){
                    if(((CalcValorArea(N, M, mapa, i, j) - S) * (-1)) < menorValor){
                        menorValor = ((CalcValorArea(N, M, mapa, i, j) - S) * (-1));
                        x = i;
                        y = j;
                    }
                }
                else{
                    if((CalcValorArea(N, M, mapa, i, j) - S) <= menorValor){
                        menorValor = (CalcValorArea(N, M, mapa, i, j) - S);
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("A melhor area para exploracao eh %d %d com valor %d", (x+1), (y+1), menorValor);
    }

    
}