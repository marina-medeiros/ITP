#include <stdio.h>

int main(){
    int nTrilhas, saude;

    scanf("%d", &nTrilhas);

    if(nTrilhas < 5){
        printf("Iniciante");
    }
    if(nTrilhas >= 5 && nTrilhas < 20){
        scanf("%d", &saude);
        switch (saude)
        {
        case 0: printf("Iniciante"); break;
        case 1: printf("Intermediário"); break;
        }
    }
    if(nTrilhas >= 20){
        scanf("%d", &saude);
        switch (saude)
        {
        case 0: printf("Intermediário"); break;
        case 1: printf("Avançado"); break;
        }
    }
}