#include <stdio.h>

int main(){
    char tabuleiro[3][3], simbolo;
    int qnt, i, j, lin, col, auxLin = 0, auxCol = 0, auxDia = 0, conta = 0;

    //lê o tabuleiro
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }

    //lê a quantidade de entradas
    scanf("%d", &qnt);

    for(i = 0; i < qnt; i++){
        scanf("%d %d %c", &lin, &col, &simbolo);
            lin--;
            col--;
            if(tabuleiro[lin][col] == '.'){
                for(j = 0; j < 3; j++){
                    if(tabuleiro[lin][j] == simbolo){
                        conta++;
                    }
                    if(tabuleiro[j][col] == simbolo){
                        conta++;
                    }
                }
                if(conta == 2){
                    printf("Boa jogada, vai vencer!\n");
                }
                if(lin == col){
                    for(j = 0; j < 3; j++){
                        if(tabuleiro[j][j] == simbolo){
                            auxDia++;
                        }
                    }     
                }
                if((lin == 0 && col == 2) || (lin == 2 && col == 0) || (lin == 2 && col == 2)){
                    for(j = 0; j < 3; j++){
                        if(tabuleiro[j][2-j] == simbolo){
                            auxDia++;
                        }
                    }     
                }
                if(auxLin == 2 || auxCol == 2 || auxDia == 2){
                    printf("Boa jogada, vai vencer!\n");
                }
                if(auxLin == 1 || auxCol == 1 || auxDia == 1){
                    printf("Continua o jogo\n");
                }
            }else{
                printf("Jogada inválida\n");
            }
    }
}