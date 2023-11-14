#include <stdio.h>
#include <math.h>

int main(){
    int quant, quantTotal;
    double valor, somaValores;

    somaValores = 0;
    quantTotal = 0;


    do
    {
        scanf("%d", &quant);
        scanf(" %lf", &valor);
        if(quant != -1){
            quantTotal += quant;
            somaValores += (valor * quant);
        }
    } while (quant != -1);
    
    printf("%d %.2lf", quantTotal, somaValores);

}