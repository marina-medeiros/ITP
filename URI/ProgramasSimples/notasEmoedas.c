#include <stdio.h>
#include <math.h>

int main(){
    double valor;
    double valorInteiro;
    double valorDecimal;
    int n100, n50, n20, n10, n5, n2, n1;
    int m50, m25, m10, m5, m1;

    scanf("%lf", &valor);

    valorDecimal = modf(valor, &valorInteiro);

    n100 = valorInteiro / 100;
    n50 = (valorInteiro - (n100 * 100)) / 50;
    n20 = (valorInteiro - (n50 * 50) - (n100 * 100)) / 20;
    n10 = (valorInteiro - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 10;
    n5 = (valorInteiro - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 5;
    n2 = (valorInteiro - (n5 * 5) - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100)) / 2;
    n1 = (valorInteiro - (n2 * 2) - (n5 * 5) - (n10 * 10) - (n20 * 20) - (n50 * 50) - (n100 * 100));

    valorDecimal = valorDecimal * 100;

    m50 = valorDecimal / 50;
    m25 = (valorDecimal - (m50 * 50)) / 25;
    m10 = (valorDecimal - (m50 * 50) - (m25 * 25)) / 10;
    m5 = (valorDecimal - (m50 * 50) - (m25 * 25) - (m10 * 10)) / 5;
    m1 = (valorDecimal - (m50 * 50) - (m25 * 25) - (m10 * 10) - (m5 * 5));

    
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", n100);
    printf("%d nota(s) de R$ 50.00\n", n50);
    printf("%d nota(s) de R$ 20.00\n", n20);
    printf("%d nota(s) de R$ 10.00\n", n10);
    printf("%d nota(s) de R$ 5.00\n", n5);
    printf("%d nota(s) de R$ 2.00\n", n2);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", n1);
    printf("%d moeda(s) de R$ 0.50\n", m50);
    printf("%d moeda(s) de R$ 0.25\n", m25);
    printf("%d moeda(s) de R$ 0.10\n", m10);
    printf("%d moeda(s) de R$ 0.05\n", m5);
    printf("%d moeda(s) de R$ 0.01\n", m1);
}