#include <stdio.h>

int main(){
    int i, tam, aux = 0;

    scanf("%d", &tam);

    int vetor[tam];

    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < (tam-1); i++){
        if((vetor[i+1] - vetor[i]) % 2 != 0){
            aux++;
            break;
        }
    }

    if(aux != 0){
        printf("Chato");
    }else{
        printf("Legal");
    }
}