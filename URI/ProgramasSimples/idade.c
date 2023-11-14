#include <stdio.h>

int main(){
    int qntDias, dias, meses, anos;
    
    scanf("%d", &qntDias);

    anos = qntDias / 365;
    meses = (qntDias - (anos * 365)) / 30;
    dias = (qntDias - (anos * 365) - (meses * 30));

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);

}