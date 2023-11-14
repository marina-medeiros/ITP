#include <stdio.h>

int main(){
    int letra;

    scanf("%d", &letra);

    switch (letra)
    {
    case 1: printf("A"); break;
    case 2: printf("B"); break;
    case 3: printf("C"); break;
    case 4: printf("D"); break;
    case 5: printf("E"); break;
    case 6: printf("F"); break;
    
    default: printf("Passou do limite.");
        break;
    }
}