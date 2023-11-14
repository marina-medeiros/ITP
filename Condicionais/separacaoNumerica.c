#include <stdio.h>
#include <string.h>

int main(){
    int n;

    n = getchar();

    if(n <= 9){
        putchar(n);
    }
    if(n >= 10 && n <= 99 ){
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);

    }
    if(n >= 100 && n <= 999){
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
    }
    if(n >= 1000 && n <=9999){
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
    }
    if(n >= 10000 && n <= 99999){
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
    }
    if(n == 100000){
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
        printf("\n");
        n = getchar();
        putchar(n);
    }
}