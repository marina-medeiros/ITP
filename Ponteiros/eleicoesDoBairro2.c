#include <stdio.h>

typedef struct st_chapa{
    int numero;
    char nome[10];
    int qntVotos;
}Party;

float compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party *most_voted, Party *second_most_voted){
    int i, j;
    float votosValidos = 0;
    Party aux;

    //Computa o número de votos de cada chapa e o número de votos válidos
    for(i = 0; i < num_parties; i++){
        int votosChapa = 0;
        for(j = 0; j < num_votes; j++){
            if(parties[i].numero == votes[j]){
                votosValidos++;
                votosChapa++;
            }
        }
        parties[i].qntVotos = votosChapa;
    }

    //Ordena as chapas de acordo com a quantidade de votos de cada
    for(i = 0; i < num_parties; i++){
        for(j = i+1; j < num_parties; j++){
            if(parties[i].qntVotos < parties[j].qntVotos){
                aux = parties[i];
                parties[i] = parties[j];
                parties[j] = aux;
            }
        }
    }

    *most_voted = parties[0];
    *second_most_voted = parties[1];

    return votosValidos;
}

int main(){
    int qntChapas, qntVotos, i;
    float porcentagemMaisVotada, porcentagemSegMaisVotada, votosValidos;
    Party maisVotado, segundoMaisVotado;

    scanf("%d", &qntChapas);

    Party vetorDeChapas[qntChapas];

    for(i = 0; i < qntChapas; i++){
        scanf("%d", &vetorDeChapas[i].numero);
        scanf("%[^\n]", vetorDeChapas[i].nome);
    }

    scanf("%d", &qntVotos);

    int vetorVotos[qntVotos];

    for(i = 0; i < qntVotos; i++){
        scanf("%d", &vetorVotos[i]);
    }

    votosValidos = compute_votes(qntVotos, vetorVotos, qntChapas, vetorDeChapas, &maisVotado, &segundoMaisVotado);

    porcentagemMaisVotada = maisVotado.qntVotos / votosValidos * 100;
    porcentagemSegMaisVotada = segundoMaisVotado.qntVotos / votosValidos* 100;

    printf("VENCEDOR:%s (%d votos = %.2f%%)\n", maisVotado.nome, maisVotado.qntVotos, porcentagemMaisVotada);
    printf("VICE:%s (%d votos = %.2f%%)", segundoMaisVotado.nome, segundoMaisVotado.qntVotos, porcentagemSegMaisVotada);

}