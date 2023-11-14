#include <stdio.h>

int main(){
    int fotos, entrada;
    int tubaroes[15] = {0};
    int i, j, diferentes = 0;

    scanf("%d", &fotos);

    for(i=0; i<fotos; i++){
        scanf("%d", &entrada);

        if(tubaroes[entrada] == 0){
            tubaroes[entrada] = 1;
            diferentes++;
        }
    }

    for(j=1; j<15; j++){
        if(tubaroes[i] !=0){
            switch (j){
            case 1: printf("TubarÃ£o Branco\n"); break;
            case 2: printf("TubarÃ£o Martelo\n"); break;
            case 3: printf("TubarÃ£o Touro\n"); break;
            case 4: printf("TubarÃ£o Baleia\n"); break;
            case 5: printf("TubarÃ£o Lixa\n"); break;
            case 6: printf("TubarÃ£o Frade\n"); break;
            case 7: printf("TubarÃ£o Tigre\n"); break;
            case 8: printf("TubarÃ£o CabeÃ§a-Chata\n"); break;
            case 9: printf("TubarÃ£o Serra\n"); break;
            case 10: printf("TubarÃ£o Pontas Negras\n"); break;
            case 11: printf("TubarÃ£o Raposa\n"); break;
            case 12: printf("TubarÃ£o Mako\n"); break;
            case 13: printf("TubarÃ£o Bruxa\n"); break;
            case 14: printf("TubarÃ£o Azul\n"); break;
            }
        }
    }

}
