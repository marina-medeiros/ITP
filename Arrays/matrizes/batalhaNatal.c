#include <stdio.h>

int main(){
    int coordCanoa[2], coordBarco[4], coordFragata[6], coorDestroier[8];
    char mapa[10][10];
    int i, j;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            mapa[i][j] = '~';
        }
    }

    for(i = 0; i < 11; i++){
        scanf("%d");
    }

    //talvez usar um switch case?
}