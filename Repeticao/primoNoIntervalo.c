#include <stdio.h>

int main(){
    int inicial, final, aux, primo;
    int i, j;


    scanf("%d %d", &inicial, &final);

    if(inicial > final){
        aux = final;
        final = inicial;
        inicial = aux;
    }

    for(i=inicial; i<=final; i++){
        primo = 0;
        for(j=2; j<i; j++){
            if(i%j == 0){
                primo++;
                break;
            }
        }
        if(primo == 0 && i != 1) printf("%d ", i);
    }
}