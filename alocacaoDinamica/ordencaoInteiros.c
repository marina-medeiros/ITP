#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verificaSort(int *vetor, int len){
    int i, x = 0;
    for(i = 0; i < (len-1); i++){
        if(vetor[i] > vetor[i+1]){
            x = 1;
            break;
        }
    }
    return x;
}

void ordena(int *vetor, int len){
  int aux;
  do{
    for(int i = 1; i < len; i++){
      if(vetor[i] < vetor[i-1]){
        aux = vetor[i];
        vetor[i] = vetor[i-1];
        vetor[i-1] = aux;
      }
    }
  }while(verificaSort(vetor, len));
}

int main() {
  char *lista, *split;
  int numInteiros = 0;
  int *vetorInteiros;

  lista = malloc(sizeof(char) * 200);
  vetorInteiros = malloc(sizeof(int) * 200);

  scanf("%[^\n]", lista);
  lista = realloc(lista, sizeof(char) * strlen(lista));

  split = strtok(lista, " ");

  while(split != NULL){
    vetorInteiros[numInteiros] = atoi(split);
    numInteiros++;
    split = strtok(NULL, " ");
  }
  
  vetorInteiros = realloc(vetorInteiros, sizeof(int) * numInteiros);

  ordena(vetorInteiros, numInteiros);

  for(int i = 0; i < numInteiros; i++){
    printf("%d ", vetorInteiros[i]);
  }
}