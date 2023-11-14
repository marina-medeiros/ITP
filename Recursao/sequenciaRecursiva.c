#include <stdio.h>

void geraSequencia(int n){
    if(n > 1){
        do{
            printf("%d ", n);
            if(n % 2 == 0){
                n = n / 2;
            }
            else if(n % 2 != 0){
                n = n * 3 + 1;
            }
        }while(n > 1);
    }
    printf("1");
}

int main(){
    int x;

    scanf("%d", &x);

    geraSequencia(x);
}