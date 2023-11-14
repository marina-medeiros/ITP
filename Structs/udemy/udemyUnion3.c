#include <stdio.h>
#include <string.h>

union numeros{
    int num1, num2, num3;
}n;

//union sobescreve
//pode ser útil para economizar memória
int main(){
    int soma = 0;

    n.num1 = 1;
    soma += n.num1;
    printf("O valor de num1 eh %d\n", n.num1);
    n.num2 = 2;
    soma += n.num2;
    printf("O valor de num2 eh %d\n", n.num2);
    n.num3 = 3;
    soma += n.num3;
    printf("O valor de num3 eh %d\n", n.num3);

    
    printf("O valor de num1 eh %d\n", n.num1);
    printf("O valor de num2 eh %d\n", n.num2);
    printf("O valor de num3 eh %d\n", n.num3);

    printf("O valor da soma eh %d\n", soma);
}