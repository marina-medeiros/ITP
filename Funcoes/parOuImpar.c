#include <stdio.h>
#include <stdbool.h>

bool verifica(int x){
    if(x % 2 == 0){
        return true;
    }else{
        return false;
    }
}
 
int main(){
    int num;
    scanf("%d", &num);

    if(verifica(num)){
        printf("true");
    }else{
        printf("false");
    }
}