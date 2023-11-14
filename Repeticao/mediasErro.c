#include <stdio.h>
#include <math.h>

int main(){
    int num, i;
    double mAri, mGeo, mHar;
    double soma, multiplicacao, somaInversa;
    double erroHarmonica, erroGeometrica, erroMedio;

    soma = 0;
    multiplicacao = 1;
    somaInversa = 0;

    for(i = 0; i < 10; i++){
        scanf("%d", &num);
        soma = soma + num;
        multiplicacao = multiplicacao * num;
        somaInversa = somaInversa + (float)1/num;
    }

    mAri = soma / 10;
    mGeo = pow(multiplicacao, (float)1/10);
    mHar = 10/(somaInversa);

    erroGeometrica = (mGeo - mAri) / mAri;
    erroHarmonica = (mHar - mAri) / mAri;
    erroMedio = (erroGeometrica + erroHarmonica) * 50;

    printf("Média aritmética é %.2lf\n", mAri);
    printf("Média harmônica é %.2lf\n", mHar);
    printf("Média geométrica é %.2lf\n", mGeo);
    printf("Erro médio é %.2lf %%", erroMedio);

}