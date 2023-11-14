#include <stdio.h>

int main(){
    char escala;
    double temp, k, c ,f;

    scanf("%lf %c", &temp, &escala);

    if(escala == 'C'){
        k = temp + 273.15;
        f = (temp * 1.8) + 32;
        c = temp;
    }
    if(escala == 'K'){
        c = temp - 273.15;
        f = (c * 1.8) + 32;
        k = temp;
    }

    if(escala == 'F'){
        c = (temp -32) /1.8;
        k = c + 273.15;
        f = temp;  
    }

    printf("Celsius: %.2lf\n", c);
    printf("Farenheit: %.2lf\n", f);
    printf("Kelvin: %.2lf", k);
}