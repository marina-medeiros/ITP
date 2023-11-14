#include <stdio.h>
#include <string.h>


int main(){
    char texto[100];

    /*
    texto[0] = 'T';
    texto[1] = 'e';
    texto[2] = 's';
    texto[3] = 't';
    texto[4] = 'e';
    texto[5] = '\0'; //tem que ter o \0
    */

    //scanf("%s", texto); // não precisa colocar &
                       // ele só lê até que apareça um espaço

    //fgets(texto, 99, stdin); // BOAS PRÁTICAS
                               // Pega só até o limite
                               // o \n entra na string

    //scanf("%[A-Z]", texto); // armazene até caracteres de A a Z maiúsculo
    //scanf("%[^A-Z]", texto); // armazene até caracteres FORA de A a Z maiúsculo
    scanf("%[^;]", texto); // armazene até caracteres FORA de ...
                           // parecido com o fgets, mas tem chance de ultrapassar o limite da memória
    
    
    printf("%s\n", texto);

    return 0;
}