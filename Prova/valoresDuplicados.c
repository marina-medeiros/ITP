#include <stdio.h>

int main() {
    int tam, i, j, k, qntRepetidos = 0;

    scanf("%d", &tam);
    int vetor[tam], repetidos[(tam/2)];

    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }   

    for(i = 0; i < tam; i++){
        int aux = 0;
        for(j = 0; j < tam; j++){
            if(vetor[i] == vetor[j]){
                aux++;
            }
        }
        if(aux > 1){
            repetidos[qntRepetidos] = vetor[i];
            qntRepetidos++;
        }
    }

    for(i = 0; i < (qntRepetidos); i++){
        printf("%d ", repetidos[i]);
    }   

}