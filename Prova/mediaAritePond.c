#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3){
    float media;
    if(tipo == 'A'){
        media = (n1 + n2 + n3)/3;
    }
    if(tipo == 'P'){
        media = (n1 * 4 + n2 * 5 + n3 * 6)/15;
    }
    return media;
}

int main() {
    char tipoDeMedia;
    float nota1, nota2, nota3;

    scanf("%c", &tipoDeMedia);
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    printf("Média %.2f", calculaMedia(tipoDeMedia, nota1, nota2, nota3));
}
