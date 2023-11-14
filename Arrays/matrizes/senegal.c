#include <stdio.h>

int numInicial;

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor){
    int coluna = largura / 3;
    int valorAposta, i, j;

    //cria a matriz
    for(i = 0; i < altura; i++){ 
        for(j = 0; j < largura; j++){
            if(j < coluna){
                bandeira[i][j] = numInicial + 1; //G
            }
            if(j >= coluna && j < (coluna*2)){ 
                bandeira[i][j] = numInicial + 2; //Y
            }
            if(j >= (coluna*2)){
                bandeira[i][j] = numInicial + 3; //R
            }
        }
    }

    switch (cor){
    case 'G': valorAposta = coluna * altura * (numInicial + 1) ; break;
    case 'Y': valorAposta = coluna * altura * (numInicial + 2) ; break;
    case 'R': valorAposta = coluna * altura * (numInicial + 3) ; break;
    }

    return valorAposta;
}


int main(){
    int largura, altura;
    char cor;

    scanf("%d %d %c", &largura, &numInicial, &cor);

    altura = (largura * 2) / 3;

    int bandeira[altura][largura];

    printf("%d", calcular_aposta(largura, altura, bandeira, cor));
}