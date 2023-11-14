#include <stdio.h>

int main(){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if((a >= (c + b)) || (b >= (a + c)) || (c >= (b + c))){
        printf("impossivel");
    }else{
        printf("possivel");
    }
}