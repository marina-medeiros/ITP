#include <stdio.h>

int main(){
    int quant, classeH, valorM;

    scanf("%d %d %d", &quant, &classeH, &valorM);

    if(quant < 1){
        printf("Melhor chamar Saitama!");
    }
    else{
        if(valorM == 1){
            if(classeH == 1 && quant < 3){
                printf("Melhor chamar Saitama!");
            }
            else{
                printf("Heróis vencerão!");
            }
        }
        if(valorM == 2){
            if(classeH == 1 || (classeH == 2 && quant < 3)){
                printf("Melhor chamar Saitama!");
            }
            else{
                printf("Heróis vencerão!");
            }
        }
        if(valorM == 3){
            if(classeH == 1 || classeH == 2 || (classeH == 3 && quant < 3)){
                printf("Melhor chamar Saitama!");
            }
            else{
                printf("Heróis vencerão!");
            }
        }
        if(valorM == 4){
            if(classeH == 1 || classeH == 2 || classeH == 3 || (classeH == 4 && quant < 3)){
                printf("Melhor chamar Saitama!");
            }
            else{
                printf("Heróis vencerão!");
            }
        }
        if(valorM == 5){
            if(classeH == 1 || classeH == 2 || classeH == 3 || classeH == 4){
                printf("Melhor chamar Saitama!");
            }
            else{
                printf("Heróis vencerão!");
            }
        }
    }
    

}