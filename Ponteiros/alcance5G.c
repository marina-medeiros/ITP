#include <stdio.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index){
    int i;
    int inicio = user - distance;
    int fim = user + distance;

    for(i = 0; i < n; i++){
        if(cells[i] >= inicio){
            *left_index = i;
            break;
        }
    }
    for(i = *left_index; i < n; i++){
        if(cells[i] >= fim){
            *right_index = i-1;
            break;
        }
    }

    int range = *right_index - *left_index + 1;

    return range;
}


int main(){
    int numCelulas, distancia, usuario, i;

    int esquerda, direita;

    scanf("%d %d %d", &numCelulas, &distancia, &usuario);

    int vetorCelulas[numCelulas];

    for(i = 0; i < numCelulas; i++){
        scanf(" %d", &vetorCelulas[i]);
    }

    int rangeVector = get_range(numCelulas, vetorCelulas, distancia, usuario, &esquerda, &direita);

    //0 1 2 3 |4 5 6| 7
    //        |0 1 2|
            
    if(rangeVector > 0){
        for(i = 0; i < rangeVector; i++){
            printf("%d ", vetorCelulas[i + esquerda]);
        }
    }else{
        printf("USUARIO DESCONECTADO");
    }
    


}