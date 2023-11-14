#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int num){
    int i;
    int aux = 0;
    if(num >= 2){
        for(i = 2; i <= (num/2); i++){
        if(num % i == 0){
            return false;
            aux++;
            break;
        }
        }
        if(aux == 0){
            return true;
        
        }
    }
    return false;
}

int main(){
    int numero, sucessor;
    scanf("%d", &numero);

    sucessor = numero + 2;

    if(ehPrimo(numero) && ehPrimo(sucessor)){
        printf("Numero forma par de gemeos");
    }else{
        printf("Numero nao forma par de gemeos");
    }
}

