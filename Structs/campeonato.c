#include <stdio.h>
#include <string.h>

typedef struct st_time{
 char nome[200];
 int vitorias, empates, derrotas;
 int golsFeitos, golsSofridos;
 int pontos, jogos, saldoDeGols;
}Time;

void imprimeTimes(int tamanho, Time vetor[]){
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    for(int i = 0; i < tamanho; i++){
        printf("%s| ", vetor[i].nome);
        printf("%d| %d| %d| %d| %d| %d| %d| %d\n", vetor[i].pontos, vetor[i].jogos, vetor[i].vitorias, vetor[i].empates, vetor[i].derrotas, vetor[i].golsFeitos, vetor[i].golsSofridos, vetor[i].saldoDeGols);
    }
    
    printf("\n");
    printf("Times na zona da libertadores:\n");
    for(int i = 0; i < 6; i++){
        printf("%s\n", vetor[i].nome);
    }
    printf("\n");
    printf("Times rebaixados:\n");
    for(int i = tamanho-1; i > tamanho-5; i--){
        printf("%s\n", vetor[i].nome);
    }
}

void cadastraTimes(int tamanho, Time vetor[]){
    for(int i = 0; i < tamanho; i++){
        getchar(); // Limpa o buffer do teclado
        scanf("%[^;]", vetor[i].nome);
        getchar();
        scanf("%d %d %d %d %d", &vetor[i].vitorias, &vetor[i].empates, &vetor[i].derrotas, &vetor[i].golsFeitos, &vetor[i].golsSofridos);
        vetor[i].pontos = vetor[i].vitorias * 3 + vetor[i].empates;
        vetor[i].jogos = vetor[i].vitorias + vetor[i].empates + vetor[i].derrotas;
        vetor[i].saldoDeGols = vetor[i].golsFeitos - vetor[i].golsSofridos;
    }
}

void ordenaTimes(int tamanho, Time vetor[]){
    Time aux;
    for(int i = 0; i < tamanho; i++){
        for(int j = i+1; j < tamanho; j++){
            if(vetor[i].pontos < vetor[j].pontos){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }else if(vetor[i].pontos == vetor[j].pontos && vetor[i].vitorias < vetor[j].vitorias){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }else if(vetor[i].pontos == vetor[j].pontos && vetor[i].vitorias == vetor[j].vitorias && (vetor[i].saldoDeGols) < (vetor[j].saldoDeGols)){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main(){
    int qntTimes;

    scanf("%d", &qntTimes);

    Time vetorTimes[qntTimes];

    cadastraTimes(qntTimes, vetorTimes);

    ordenaTimes(qntTimes, vetorTimes);

    imprimeTimes(qntTimes, vetorTimes);
  
}