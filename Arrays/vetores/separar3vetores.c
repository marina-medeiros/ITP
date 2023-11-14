#include <stdio.h>

int main(){
    int a[15], b[15], c[15], d[15];
    int i, tamB = 0, tamC = 0, tamD = 0;


    for(i = 0; i < 15; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < 15; i++){
        if((a[i] % 2) == 0){
            b[tamB] = a[i];
            tamB++;
        }
        if((a[i] % 3) == 0){
            c[tamC] = a[i];
            tamC++;
        }
        if(((a[i] % 3) != 0) && ((a[i] % 2) != 0)){
            d[tamD] = a[i];
            tamD++;
        }
    }

    printf("B = [");
    for(i = 0; i < (tamB-1); i++){
        printf("%d, ", b[i]);
    }
    printf("%d]\n", b[tamB-1]);

    printf("C = [");
    for(i = 0; i < (tamC-1); i++){
        printf("%d, ", c[i]);
    }
    printf("%d]\n", c[tamC-1]);

    printf("D = [");
    for(i = 0; i < (tamD-1); i++){
        printf("%d, ", d[i]);
    }
    printf("%d]\n", d[tamD-1]);
    
}