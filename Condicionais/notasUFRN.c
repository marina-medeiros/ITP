#include <stdio.h>

int main(){
    float n1, n2, n3, rec, media, menorN;

    printf("Digite suas notas");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = (n1 + n2 + n3)/3;

    if(n1 <= n2 && n1 <= n3){
        menorN = n1;
    }
    if(n2 <= n3 && n2 <= n1){
        menorN = n2;
    }
    else{
        menorN = n3;
    }

    if(media >= 7){
        printf("Aprovado!");
    }
    if(media < 7 && media >= 5 && n1 >= 3 && n2 >= 3 && n3 >= 3){
        printf("Aprovado por nota.");
    }
    if(media < 5 && n1 > 3 && n2 > 3 && n3 > 3){
        printf("Digite sua nota da recuperação:");
        scanf("%f", &rec);
        media = (n1 + n2 + n3 - menorN) / 3;

        if(media >= 7){
            printf("Aprovado!");
        }
        if(media < 7 && media >= 5 && rec >= 3){
            printf("Passou na recuperação.");
        }

    }
    if(media < 3){
        printf("Reprovado.");
    }
}