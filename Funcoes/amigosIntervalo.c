#include <stdio.h>

int testa_divisor(int numero, int divisor){
    if(numero % divisor == 0){
        return 1;
    }else{
        return 0;
    }
}

int soma_divisores(int value){
    int i, soma;
    soma = 0;
    for(i = 1; i < value; i++){
        if(testa_divisor(value, i) == 1){
            soma += i;
        }
    }
    return soma;
}

// dois números naturais diferentes são amigos se cada um for igual
// à soma dos divisores do outro (sem incluir os próprios números dos divisores)
int testa_amigos(int a, int b){
    if(a == soma_divisores(b) && b == soma_divisores(a) && a != b){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    // todos os valores de l1 que possuem um amigo em l2
    int A, B, C, D, j, k, numAmigos;
    scanf("%d %d", &A, &B);
    scanf("%d %d", &C, &D);
    numAmigos = 0;


    for(j = A; j <= B; j++){
        for(k = C; k <= D; k++){
            if(testa_amigos(k, j) == 1){
                printf("O %d possui um amigo!\n", j);
                numAmigos++;
            }
        }
    }
    if(numAmigos == 0){
        printf("Os intervalos nao apresentam amigos!");
    }

    return 0;
}