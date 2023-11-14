#include <stdio.h>

int main() {
    int num, i, j;
    int soma = 0;

    scanf("%d", &num);

    int matriz[num][num];

    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            scanf("%d", &matriz[i][j]);
            if(i == j){
                soma+= matriz[i][j];
            }
            if((i + j) == (num-1)){
                soma+= matriz[i][j];
            }
        }
    }

    printf("%d", soma);
    
}