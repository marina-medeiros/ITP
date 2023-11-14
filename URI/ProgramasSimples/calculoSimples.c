#include <stdio.h>

int main(){
    int codigo1, codigo2, qnt1, qnt2;
    double valor1, valor2, custo;

    scanf("%d %d %lf", &codigo1, &qnt1, &valor1);
    scanf("%d %d %lf", &codigo2, &qnt2, &valor2);

    custo = (valor1 * qnt1) + (valor2 * qnt2);

    printf("VALOR A PAGAR: R$ %.2lf\n", custo);
}