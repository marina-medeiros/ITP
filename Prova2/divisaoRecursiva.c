#include <stdio.h>

void divide(int n){
    int aux = 0;
    int primos[4];

    primos[0] = 2;
    primos[1] = 3;
    primos[2] = 5;
    primos[3] = 7;

    for(int i = 0; i < 4; i++){
        if(n % primos[i] == 0){
            aux = primos[i];
            break;
        }
    }
    if(n > 1){
        printf("%d ", n);
        divide(n/aux);
    }if(n == 1 || aux == 0){
        printf("%d acabou!", n);
    }
}

int main(){
    int n;

    scanf("%d", &n);

    divide(n);
}