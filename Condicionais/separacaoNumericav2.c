#include <stdio.h>
#include <string.h>

int main(){
    int numero, u, d, c, m , dm, cm;

    scanf("%d", &numero);

    if(numero <= 9){ 
        printf("%d", numero);
    }
    if(numero >= 10 && numero <= 99 ){ 
        u = numero % 10;
        d = (numero - u) /10;

        printf("%d\n", d);
        printf("%d\n", u);
    }
    if(numero >= 100 && numero <= 999){
        u = numero % 10;
        d = ((numero - u) % 100) / 10;
        c = (numero - u - ( d * 10)) / 100;
        printf("%d\n", c);
        printf("%d\n", d);
        printf("%d\n", u);
    }
    if(numero >= 1000 && numero <=9999){
        u = numero % 10;
        d = ((numero - u) % 100) / 10;
        c = ((numero - u - ( d * 10)) % 1000) / 100;
        m = ((numero - u - ( d * 10) - (c * 100)) % 10000) / 1000;
        printf("%d\n", m);
        printf("%d\n", c);
        printf("%d\n", d);
        printf("%d\n", u);
    }
    if(numero >= 10000 && numero <= 99999){
        u = numero % 10;
        d = ((numero - u) % 100) / 10;
        c = ((numero - u - ( d * 10)) % 1000) / 100;
        m = ((numero - u - ( d * 10) - (c * 100)) % 10000) / 1000;
        dm = ((numero - u - ( d * 10) - (c * 100) - (m * 1000)) % 100000) / 10000;
        printf("%d\n", dm); 
        printf("%d\n", m);
        printf("%d\n", c);
        printf("%d\n", d);
        printf("%d\n", u);
    }
    if(numero == 100000){
        u = numero % 10;
        d = ((numero - u) % 100) / 10;
        c = ((numero - u - ( d * 10)) % 1000) / 100;
        m = ((numero - u - ( d * 10) - (c * 100)) % 10000) / 1000;
        dm = ((numero - u - ( d * 10) - (c * 100) - (m * 1000)) % 100000) / 10000;
        cm = ((numero - u - ( d * 10) - (c * 100) - (m * 1000) - (dm * 10000)) % 1000000) / 100000;
        printf("%d\n", cm);
        printf("%d\n", dm);
        printf("%d\n", m);
        printf("%d\n", c);
        printf("%d\n", d);
        printf("%d\n", u);
    }
}