#include <stdio.h>

typedef struct st_time{
 char nome[50];
 int golsMarcados;
 int golsSofridos;
}Time;

void ordenaTimes(Time vet[], int tam){
  Time aux;
  for(int i = 0; i < tam; i++){
    for(int j = i+1; j < tam; j++){
        if(vet[i].golsMarcados < vet[j].golsMarcados){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
  }
}

void imprimeTimes(Time vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d - %s\n", i+1, vet[i].nome);
        printf("Gols marcados: %d\n", vet[i].golsMarcados);
        printf("Gols sofridos: %d\n", vet[i].golsSofridos);
    }
}

void leValores(int tamanho, Time vetor[]){
    for(int i = 0; i < tamanho; i++){
        scanf(" %[^\n]", vetor[i].nome);
        scanf("%d %d", &vetor[i].golsMarcados, &vetor[i].golsSofridos);
    }
}

int main(){
    int qntTimes;

    scanf("%d", &qntTimes);

    Time vetorTimes[qntTimes];

    leValores(qntTimes, vetorTimes);

    ordenaTimes(vetorTimes, qntTimes);

    imprimeTimes(vetorTimes, qntTimes);
  
}