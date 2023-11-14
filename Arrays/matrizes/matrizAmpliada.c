#include <stdio.h>

int main() {
    int num, i, j;
    scanf("%d", &num);
    //int piramide[num+2][num+2];
    int matriz[num][num];

    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            matriz[i][j] = i;
        }
    }
    matriz[0][0] = 99;
    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            if(matriz[i][j] > matriz[i-1][j-1]){
                printf("oi %d %d  ", i, j);
            }
        }
    }

    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
        printf("%d ", matriz[i][j]);
        }
    printf("\n");
    }

    /*
    for(i = 0; i < num+2; i++){
        for(j = 0; j < num+2; j++){
            piramide[i][j] = 0;
        }
    }

    for(i = 1; i < num+1; i++){
        for(j = 1; j < num+1; j++){
            piramide[i][j] = 1;
        }
    }
    
    for(i = 1; i < (num+1); i++){
        for(j = 1; j < (num+1); j++){
        printf("%d ", piramide[i][j]);
        }
    printf("\n");
    }
    for(i = 0; i < (num+2); i++){
        for(j = 0; j < (num+2); j++){
        printf("%d ", piramide[i][j]);
        }
    printf("\n");
    }

    00 01 02 03 04    
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34
    40 41 42 43 44

    00 01 02 03 04    
    01 02 03 04 05
    02 03 04 05 06
    03 04 05 06 07
    04 05 06 07 08
    */
    
}