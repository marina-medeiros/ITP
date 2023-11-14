#include <stdio.h>

int calc_mdc(int x, int y){
    if((x % y) > 0){
        return calc_mdc(y, x % y);
    }else{
        return y;
    }
}

int calc_mmc(int x, int y, int mdc){
    return (x * y) / mdc;
}

int main(){
    int x, y, mdc, mmc;

    scanf("%d %d", &x, &y);

    mdc = calc_mdc(x, y);

    mmc = calc_mmc(x, y, mdc);

    printf("MDC = %d, MMC = %d", mdc, mmc);
}