#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* soma(int* vetorA, int* vetorB, int qtdA){
    int* vetorC = malloc(sizeof(int) * qtdA);
    for(int i = 0; i < qtdA; i++){
        vetorC[i] = vetorA[i] + vetorB[i];
    }

    return vetorC;
}

int main() {
  char *listaA, *listaB, *split;
  int qtdA = 0, qtdB = 0;
  int *vetorA, *vetorB;

  listaA = malloc(sizeof(char) * 200);
  listaB = malloc(sizeof(char) * 200);
  vetorA = malloc(sizeof(int) * 200);
  vetorB = malloc(sizeof(int) * 200);

  scanf("%[^\n]", listaA);
  getchar();
  scanf("%[^\n]", listaB);
  listaA = realloc(listaA, sizeof(char) * strlen(listaA));
  listaB = realloc(listaB, sizeof(char) * strlen(listaB));

  split = strtok(listaA, " ");

  while(split != NULL){
    vetorA[qtdA] = atoi(split);
    qtdA++;
    split = strtok(NULL, " ");
  }
  
  vetorA = realloc(vetorA, sizeof(int) * qtdA);

  split = strtok(listaB, " ");

  while(split != NULL){
    vetorB[qtdB] = atoi(split);
    qtdB++;
    split = strtok(NULL, " ");
  }
  
  vetorB = realloc(vetorB, sizeof(int) * qtdB);

  if(qtdA == qtdB){
    int* vetorC = soma(vetorA, vetorB, qtdA);
    for(int i = 0; i < qtdA; i++){
        printf("%d ", vetorC[i]);
    }
  }else{
    printf("Vetores de tamanhos diferentes!");
  }

}