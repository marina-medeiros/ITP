#include <stdio.h>

void compute_votes( int n, int votes[n], int *most_voted, int *second_most_voted){
    int i, j, count, most = 0, elem, elem2;

    for(i = 0; i < n; i++){
        count = 1;
        for(j = i+1; j < n; j++){
            if(votes[j] == votes[i]){
                count++;
            }
        }
        if(most < count){
            most = count;
            elem = votes[i];
        }
    }
    
    *most_voted = elem;

    most = 0;
    for(i = 0; i < n; i++){
        count = 1;
        for(j = i+1; j < n; j++){
            if(votes[j] == votes[i] && votes[i] != elem){
                count++;
            }
        }
        if(most < count){
            most = count;
            elem2 = votes[i];
        }
    }

    *second_most_voted = elem2;
}

int main(){
    int qnt, i, maisVotado, segundoMaisVotado;

    scanf("%d", &qnt);

    int vetorVotos[qnt];

    for(i = 0; i < qnt; i++){
        scanf("%d", &vetorVotos[i]);
    }

    compute_votes(qnt, vetorVotos, &maisVotado, &segundoMaisVotado);

    printf("%d %d", maisVotado, segundoMaisVotado);
}