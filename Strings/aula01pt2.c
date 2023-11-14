#include <stdio.h>

int main(){
    char texto[100];
    char nome[50];
    int idade;
    double altura;

    fgets(texto, 100, stdin);

    sscanf(texto, "%s; %d %lf", nome, &idade, &altura);
    //sscanf(texto, "%*s - %d - %*lf", nome, &idade, &altura); //ignora as informações

    printf("Nome: %s\nIdade %d\nAltura %.2lf\n", nome, idade, altura);

    
}