#include <stdio.h>

int main(){
    int tam1, tam2, i, j, tamIntersec = 0;

    scanf("%d %d", &tam1, &tam2);

    int vetor1[tam1], vetor2[tam2], vetorIntersec[tam1+tam2];

    for(i = 0; i < tam1; i++){  // Lê os valores do vetor1
        scanf("%d", &vetor1[i]);
    }
    for(i = 0; i < tam2; i++){ // Lê os valores do vetor2
        scanf("%d", &vetor2[i]);
    }

    for(i = 0; i < tam1; i++){
        for(j = 0; j < tam2; j++){
            if(vetor1[i] == vetor2[j]){
                vetorIntersec[tamIntersec] = vetor1[i];
                tamIntersec++;
            }
        }
    }

    if(tamIntersec > 0){
        for(i = 0; i < (tamIntersec-1); i++){
            printf("%d ", vetorIntersec[i]);
        }
        printf("%d", vetorIntersec[tamIntersec-1]);
    }

}