#include <stdio.h>

int main(){
    int numero = 42;
    float nota = 7.9;
    double nota2 = 6;
    char letra = 'd';

    printf("A variável 'numero' tem valor %d e ocupa %d bytes\n", numero, sizeof(numero));
    printf("A variável 'nota' tem valor %.2f e ocupa %d bytes\n", nota, sizeof(nota));
    printf("A variável 'nota2' tem valor %.2f e ocupa %d bytes\n", nota2, sizeof(nota2));
    printf("A variável 'letra' tem valor %c e ocupa %d bytes\n", letra, sizeof(letra));

}