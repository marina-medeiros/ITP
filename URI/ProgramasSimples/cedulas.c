#include <stdio.h>

int main(){
    int valor, n100, n50, n20, n10, n5, n2, n1;

    scanf("%d", &valor);

    n100 = valor / 100;
    n50 = (valor - (n100 * 100)) / 50;
    n20 = (valor - (n50 * 50) - (n100 * 100)) / 20;
    n10 = (valor - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 10;
    n5 = (valor - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 5;
    n2 = (valor - (n5 * 5) - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 2;
    n1 = (valor - (n2 * 2) - (n5 * 5) - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100));
    
    printf("%d\n", valor);
    printf("%d nota(s) de R$ 100,00\n", n100);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);
}