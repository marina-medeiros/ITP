#include <stdio.h>

int main(){
    int numeroFunc, horas;
    double valorHora, salario;

    scanf("%d", &numeroFunc);
    scanf("%d", &horas);
    scanf("%lf", &valorHora);

    salario = valorHora * horas;

    printf("NUMBER = %d\n", numeroFunc);
    printf("SALARY = U$ %.2lf\n", salario);



}