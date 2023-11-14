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
        for(j=0; j < len; j++){
                if(j == (len-1)){
                    printf("%d\n", array[j]);
                }else{
                    printf("%d ", array[j]);
                }
        }
    } while (verificaSort(array, len) == 1);
}

int main(){
    int tam, i;

    scanf("%d", &tam);

    int vetor[tam];

    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < tam; i++){
        if(i == (tam-1)){
            printf("%d\n", vetor[i]);
        }else{
            printf("%d ", vetor[i]);
        }
    }
    bubbleSort(vetor, tam);
}