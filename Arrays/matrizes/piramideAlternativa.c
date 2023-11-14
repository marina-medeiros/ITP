#include <stdio.h>

int main() {
    int num, i, j;
    scanf("%d", &num);
    int piramide[num+2][num+2];

    for(i = 0; i < num+2; i++){
        for(j = 0; j < num+2; j++){
            piramide[i][j] = 0;
        }
    }

  //definir o meio:
    if(num % 2 == 0){ //se for par
        piramide[(num+2)/2][(num+2)/2-1] = num-1;
        piramide[(num+2)/2][(num+2)/2] = num-1;
        piramide[(num+2)/2-1][(num+2)/2-1] = num-1;
        piramide[(num+2)/2-1][(num+2)/2] = num-1;
    }
    if(num % 2 != 0){ //se for ímpar
        piramide[(num+2)/2][(num+2)/2] = num;
    }

    do{
    for(i = 1; i < (num+1); i++){
        for(j = 1; j < (num+1); j++){
            if(piramide[i][j] != 0){
                if(piramide[i-1][j] < piramide[i][j] - 1){
                    piramide[i-1][j] = piramide[i][j] - 1;
                }
                if(piramide[i+1][j] < piramide[i][j] - 1){
                    piramide[i+1][j] = piramide[i][j] - 1;
                }
                if(piramide[i][j-1] < piramide[i][j] - 1){
                    piramide[i][j-1]= piramide[i][j] - 1;
                }
                if(piramide[i][j+1] < piramide[i][j] - 1){
                    piramide[i][j+1] = piramide[i][j] - 1;
                }
            }
        }
    }
    } while (piramide[1][1] == 0);

    
    for(i = 1; i < (num+1); i++){
        for(j = 1; j < (num+1); j++){
        printf("%d ", piramide[i][j]);
        }
    printf("\n");
    }
    
}