#include <stdio.h>
#include <string.h>

union pessoa{
    char nome[100];
    int idade;
};

//union sobescreve

int main(){
    union pessoa pes;

    strcpy(pes.nome, "Angelina Jolie");
    printf("Dados de %s\n", pes.nome);

    pes.idade = 39;
    printf("Ela tem %d anos\n", pes.idade);

    printf("A variável 'pes' está ocupando %d bytes em memória.", sizeof(pes));

}