#include <stdio.h>

int main(){
    int combo, preco, quant, dif;

    scanf("%d %d", &combo, &quant);

    switch (combo)
    {
    case 1: preco = 12; break;
    case 2: preco = 23; break;
    case 3: preco = 31; break;
    case 4: preco = 28; break;
    case 5: preco = 15; break;
    }

    if(preco == quant){
        printf("Deu certim!");
    }
    if(preco < quant){
        dif = quant - preco;
        printf("Troco = %d reais", dif);
    }
    if(quant < preco){
        dif = preco - quant;
        printf("Saldo insuficiente! Falta %d reais", dif);
    }

}