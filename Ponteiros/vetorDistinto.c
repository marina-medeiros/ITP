#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float* ordenar(int* tam, float* vetor){
    float* saida = malloc(sizeof(float) * (*tam));
    int qnt = 0;

    for(int i = 0; i < *tam; i++){
        int aux = 0;
        for(int j = 0; j < *tam; j++){
            if((i != j) && (vetor[i] == vetor[j])){
                aux++;
                break;
            }
        }
        if(!aux){
            saida[qnt] = vetor[i];
            qnt++;
        }
    }

    *tam = qnt;
    return saida;
}

int main(){
    int n;

    scanf("%d", &n);

    float* valores = malloc(sizeof(float) * n);

    for(int i = 0; i < n; i++){
        scanf(" %f", &valores[i]);
    }
    
    valores = ordenar(&n, valores);

    if(n == 0){
        printf("[]");
    }else{
        printf("[");
        for(int i = 0; i < (n-1); i++){
            printf("%.4f, ", valores[i]);
        }
        printf("%.4f]", valores[n-1]);
    }

}