#include <stdio.h>
#include <stdbool.h>

bool testa_divisor(int numero, int divisor){
    if(numero % divisor == 0){
        return true;
    }else{
        return false;
    }
}

int eh_perfeito(int value){
    int i, soma;
    soma = 0;
    for(i = 1; i < value; i++){
        if(testa_divisor(value, i)){
            soma += i;
        }
    }
    if(value == soma){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int N, x, i;
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &x);
        if(eh_perfeito(x) == 1){
            printf("%d eh perfeito\n", x);
        }else{
            printf("%d nao eh perfeito\n", x);
        }
    }
}