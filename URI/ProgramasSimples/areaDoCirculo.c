#include <stdio.h>

int main(){
    const double pi = 3.14159;

    double raio = 0;
    double area;

    scanf("%lf", &raio);

    area = raio * raio * pi;

    printf("A=%.4f\n", area);

}
