#include <stdio.h>
#include <math.h>

int main(){
    int contador, series;
    double tempo, entrada;

    scanf("%lf", &entrada);
    contador = 0;

    do
    {
        scanf("%lf", &tempo);
        if(tempo <= entrada && tempo != -1){
            contador++;
        }
    } while (tempo != -1);
    
    series = contador / 8;

    if(contador % 8 != 0){
        series++;
    }


    printf("%d %d", contador, series);

}