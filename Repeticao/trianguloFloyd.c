#include <stdio.h>
#include <math.h>

int main(){
    int entrada, i, j, contador;

    scanf("%d", &entrada);
    contador = 1;

    if(entrada > 0){
        for(i = 0; i <= entrada; i++){
            for(j = 0; j < i; j++){
                if(contador < 10){
                    printf(" %d ", contador);
                }else{
                    printf("%d ", contador);
                }
                contador++;
                if(j == (i-1)){
                    printf("\n");
                }
            }
        }
    }else{
        printf("Você entrou com %d, tente de novo na próxima", entrada);
    }
    
}