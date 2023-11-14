#include <stdio.h>
#include <math.h>

int main(){
    int quant, i, quantInvalidos;
    double indice, soma, media;

    scanf("%d", &quant);
    soma = 0;
    quantInvalidos = 0;

    if(quant != 0){
        for(i = 0; i < quant; i++){
            scanf("%lf", &indice);
            if(indice != -1){
                soma += indice;
            }else{
                quantInvalidos++;
            }
        }
    }

    if(quantInvalidos == quant  || quant == 0){
        printf("A competicao nao possui dados historicos!");
    }else{
        media = soma / (quant - quantInvalidos);
        printf("%.2lf", media);
    }

}