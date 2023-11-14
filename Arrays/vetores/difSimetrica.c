#include <stdio.h>

int verificaSort(int* array, int len){
    int i, x = 0;
    for(i = 0; i < (len-1); i++){
        if(array[i] > array[i+1]){
            x = 1;
            break;
        }
    }
    return x;
}

void bubbleSort(int* array, int len){
    int i, j, aux, fim;
    fim = len;
    do
    {
       for(i = 0; i < (fim-1); i++){
            if(array[i] > array[i+1]){
                aux = array[i+1];
                array[i+1] = array[i];
                array[i] = aux;
            }
        }
        fim--;
    } while (verificaSort(array, len) == 1);
    
    
}

int main() {
    int tam1, tam2, i, j, aux;
    int tamanho = 0;
    
    scanf("%d %d", &tam1, &tam2);

    int vetor1[tam1], vetor2[tam2], vetorDifSimetrica[tam1+tam2];

    for(i = 0; i < tam1; i++){
        scanf("%d", &vetor1[i]);
    }
    for(i = 0; i < tam2; i++){
        scanf("%d", &vetor2[i]);
    }

    for(i = 0; i < tam1; i++){
        aux = 1;
        for(j = 0; j < tam2; j++){
            if(vetor1[i] == vetor2[j]){
                aux = 0;
                break;
            }
        }
        if(aux == 1){
            vetorDifSimetrica[tamanho] = vetor1[i];
            tamanho++;
        }
    }

    for(i = 0; i < tam2; i++){
        aux = 1;
        for(j = 0; j < tam1; j++){
            if(vetor2[i] == vetor1[j]){
                aux = 0;
                break;
            }
        }
        if(aux == 1){
            vetorDifSimetrica[tamanho] = vetor2[i];
            tamanho++;
        }
    }

    bubbleSort(vetorDifSimetrica, tamanho);

    for(i = 0; i < tamanho; i++){
        printf("%d ", vetorDifSimetrica[i]);
    }

 return 0;
}