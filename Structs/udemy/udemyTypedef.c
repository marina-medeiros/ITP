#include <stdio.h>

//typedef --redefinir tipos

int main(){
     typedef float nota;

     nota prova1 = 7.0;
     nota prova2 = 6.0;

     nota soma = prova1 + prova2;

     printf("A soma das notas é %.2f", soma);
}