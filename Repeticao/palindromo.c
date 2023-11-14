#include <stdio.h>
#include <math.h>

int main(){
    int num, numAux, numAux2, algarismos, resto, reverso;

    scanf("%d", &num);
    algarismos = 0;
    reverso = 0;
    numAux = num;
    numAux2 = num;

    while(numAux > 0){
        algarismos++;
        numAux = numAux/10;
    }

    while(numAux2 != 0){
        resto = numAux2 % 10;
        reverso = reverso * 10 + resto;
        numAux2 = numAux2 / 10;
    }

    if(reverso == num){
        printf("%d é Palíndromo", num);
    }else{
        printf("%d não é Palíndromo", num);
    }
    if(num % 2 == 0){
        printf(" e par.");
    }else{
        printf(" e impar.");
    }
}