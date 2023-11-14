#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void extrair(char *email, int *inicio, int *fim){
    for(int i = 0; i < (int)strlen(email); i++){
        if(email[i] == '@'){
            *inicio = i;
            break;
        }
    }
    for(int i = *inicio; i < (int)strlen(email); i++){
        if(email[i] == '.'){
            *fim = i;
            break;
        }
    }
}

int main(){
    char email[50];
    int inicio, fim;

    do{
        scanf("%s", email);
        getchar();

        if(strcmp(email, "FIM") != 0){
            extrair(email, &inicio, &fim);
                                          //0123456 7891011
            printf("%d %d", inicio, fim); //marina@  gmail .com

            for(int i = (inicio+1); i < fim; i++){
                printf("%c", email[i]);
            }
            printf("\n");
        }

    }while(strcmp(email, "FIM") != 0);

}