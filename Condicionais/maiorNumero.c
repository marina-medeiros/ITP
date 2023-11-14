#include <stdio.h>

int main(){
    int a, b, c, d, num;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a >= b && a >= c && a >= d){
        printf("Maior: %d", a);
    }
    if(b > a && b >= c && b >= d){
        printf("Maior: %d", b);
    }
    if(c > b && c > a && c >= d){
        printf("Maior: %d", c);
    }
    if(d > b && d > c && d > a){
        printf("Maior: %d", d);
    }
}