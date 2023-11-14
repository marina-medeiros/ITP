#include <stdio.h>

int testaValores(int n, int m, int mapa[n][m], int i, int j){
    int aux = 0;
    if(mapa[i][j] > mapa[i-1][j-1] && mapa[i][j] > mapa[i-1][j] && mapa[i][j] > mapa[i-1][j+1] && mapa[i][j] > mapa[i][j-1] && mapa[i][j] > mapa[i][j+1] && mapa[i][j] > mapa[i+1][j-1] && mapa[i][j] > mapa[i+1][j] && mapa[i][j] > mapa[i+1][j+1]){
        aux = 1;
    }
    // 1 --> é maior que todos;
    return aux;
}

int main() {
    int i, j, N, M, xJedi, yJedi, k, l, numLocal = 1;

    scanf("%d %d", &N, &M);
    scanf("%d %d", &xJedi, &yJedi);

    int mapa[N+2][M+2];
    int maiores[N+2][M+2];

    for(i = 0; i < (N+2); i++){
        for(j = 0; j < (M+2); j++){
            maiores[i][j] = 0;
            mapa[i][j] = 0;
        }
    }
    
    for(i = 1; i < (N+1); i++){
        for(j = 1; j < (M+1); j++){
            scanf("%d", &mapa[i][j]);
        }
    }
    for(i = 1; i < (N+1); i++){
        for(j = 1; j < (M+1); j++){
            if(testaValores((N+2), (M+2), mapa, i, j) == 1){
                maiores[i][j] = 2;
                maiores[i-1][j-1] = maiores[i-1][j] = maiores[i-1][j+1] = maiores[i][j-1] = maiores[i][j+1] = maiores[i+1][j-1] = maiores[i+1][j] = maiores[i+1][j+1] = 1;
                printf("Local %d: %d %d", numLocal, i, j);
                printf("\n");
                numLocal++;
            }
        }
    }

    if(maiores[xJedi][yJedi] == 1){
        printf("Descanse na Força...");
    }
    if(maiores[xJedi][yJedi] == 2){
        printf("Ao resgate!");
    }

  return 0;
}

