#include <stdio.h>

int MDC(int x, int y){
    int aux, i, mdc;
    if(x>y){
        aux = x;
        x = y;
        y = aux;
    }
    if(x == 0){
        mdc = y;
    }else{
        for(i=1; i <= x; i++){
            if(x % i == 0 && y % i == 0){
                mdc = i;
            }
        }
    }
    
    return mdc;
}

int main(){
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("MDC(%d, %d)=%d", num1, num2, MDC(num1, num2));

    return 0;
}