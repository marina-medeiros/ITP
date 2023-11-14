#include <stdio.h>

int main(){
    int tam1, tam2, i, j, tamUniao = 0;

    scanf("%d %d", &tam1, &tam2);

    int vetor1[tam1], vetor2[tam2], vetorUniao[tam1+tam2];

    for(i = 0; i < tam1; i++){  // Lê os valores do vetor1 e coloca no vetorUniao
        scanf("%d", &vetor1[i]);
        vetorUniao[i] = vetor1[i];
        tamUniao++; //1 2 3
    }
    for(i = 0; i < tam2; i++){ // Lê os valores do vetor2
        scanf("%d", &vetor2[i]);
    }

    for(i = 0; i < tam2; i++){
        int aux = 1;
        for(j = 0; j < tam1; j++){
            if(vetor2[i] == vetor1[j]){
                aux = 0;
                break;
            }
        }
        if(aux){
            vetorUniao[tamUniao] = vetor2[i];
            tamUniao++;
        }
    }

    for(i = 0; i < (tamUniao-1); i++){
        printf("%d ", vetorUniao[i]);
    }
    printf("%d", vetorUniao[tamUniao-1]);

}