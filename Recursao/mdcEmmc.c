#include <stdio.h>

void calc_mdc_mmc(int x, int y, int *mdc, int *mmc){
    int a, b, res;
    int x1 = x, y1 = y;
    do{
        a = x;
        b = y;
        res = a % b;
        x = b;
        y = res;
    }while(res != 0);

    *mdc = b;

    *mmc = (x1 * y1) / *mdc;
}

int main(){
    int x, y, mdc, mmc;

    scanf("%d", &x);
    scanf("%d", &y);

    calc_mdc_mmc(x, y, &mdc, &mmc);

    printf("MDC = %d, MMC = %d", mdc, mmc);
}