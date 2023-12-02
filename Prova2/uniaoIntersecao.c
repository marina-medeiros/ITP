#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* uniao(int *A, int *B, int tamA, int tamB, int *tamUniao){
    int* C =  malloc(sizeof(int) * (tamA + tamB));
    int aux = 0, tamC = 0;

    for(int i = 0; i < tamA; i++){
        for(int j = 0; j < tamC; j++){
            if(A[i] == C[j]){
                aux++;
            }
        }
        if(aux == 0){
            C[i] = A[i];
            tamC++;
        }
    }

    aux = 0;

    for(int i = 0; i < tamB; i++){
        for(int j = 0; j < tamC; j++){
            if(B[i] == C[j]){
                printf("func %d", B[i]);
                aux++;
            }
        }
        if(aux == 0){
            C[tamC] = B[i];
            tamC++;
        }
    }

    *tamUniao = tamC;

    C = realloc(C, sizeof(int) * tamC);

    return C;
}

int *intersecao(int *A, int *B, int tamA, int tamB, int *tamIntersec){
    int* C =  malloc(sizeof(int) * (tamA + tamB));
    int aux = 0, tamC = 0;

    for(int i = 0; i < tamA; i++){
        for(int j = 0; j < tamC; j++){
            if(A[i] == C[j]){
                aux++;
            }
        }
        for(int j = 0; j < tamB; j++){
            if(A[i] == B[j] && aux == 0){
                C[tamC] = A[i];
                tamC++;
            }
        }
    }

    *tamIntersec = tamC;

    C = realloc(C, sizeof(int) * tamC);

    return C;
}

int main(){
    int tamA, tamB, tamUniao, tamIntersecao;
    int *vetorA, *vetorB;

    scanf("%d ", &tamA);

    vetorA = malloc(sizeof(int) * tamA);

    for(int i = 0; i < tamA; i++){
        scanf("%d", &vetorA[i]);
    }

    scanf("%d ", &tamB);

    vetorB = malloc(sizeof(int) * tamB);

    for(int i = 0; i < tamB; i++){
        scanf("%d", &vetorB[i]);
    }

    for(int i = 0; i < tamA; i++){
        printf("%d\n", vetorA[i]);
    }

    for(int i = 0; i < tamB; i++){
        printf("%d\n", vetorB[i]);
    }



    int *vetorUniao = uniao(vetorA, vetorB, tamA, tamB, &tamUniao);
    int *vetorIntersec = intersecao(vetorA, vetorB, tamA, tamB, &tamIntersecao);
    
    printf("A união B == {");
    if(tamUniao == 0){
        printf("vazio");
    }else{
        for(int i = 0; i < tamUniao-1; i++){
            printf("%d ", vetorUniao[i]);
        }
    }
    printf("%d}\n", vetorUniao[tamUniao-1]);

    
    printf("A interseção B == {");
    if(tamIntersecao == 0){
        printf("vazio");
    }else{
        for(int i = 0; i < tamIntersecao-1; i++){
            printf("%d ", vetorIntersec[i]);
        }
    }
    printf("%d}\n", vetorIntersec[tamIntersecao-1]);

}