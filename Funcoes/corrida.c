#include <stdio.h>

int corrida(int d, int v1, int v2){
    int diferenca_1, diferenca_2, i;
    int pessoa, amigo, segundos;

    //distancia entre as pessoas dps de 1 segundo
    diferenca_1 = (v2 + d) - v1;
    //distancia entre as pessoas dps de 2 segundos
    diferenca_2 = ((2 * v2) + d) - (2 * v1);

    pessoa = 0;
    amigo = d;
    segundos = 0;

    if(diferenca_2 < diferenca_1){
        do{
            pessoa += v1;
            amigo += v2;
            segundos++;
        }while(pessoa != amigo);
        return segundos;
    }else{
        return -1;
    }
}

int main(){
    int V1, V2, D;
    scanf("%d", &D);
    scanf("%d", &V1);
    scanf("%d", &V2);

    corrida(D, V1, V2);

    /*
    retorno = corrida(D, V1, V2);

    if(retorno != -1){
        printf("%ds", retorno);
    }else{
        printf("impossivel");
    }
    */

    
    
}