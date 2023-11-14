#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char grande[41], pequena[41], *substring;
    int locais[40], repet = 0, tamGrande;
    
    scanf("%s", pequena);
    getchar();
    scanf("%[^\n]", grande); 

    tamGrande = (int)strlen(grande);

    for(int i = 0; i < (int)strlen(grande); i++){ 
        grande[i] = tolower(grande[i]);
    }

    for(int i = 0; i < (int)strlen(pequena); i++){ 
        pequena[i] = tolower(pequena[i]);
    }

    do{
        substring = strstr(grande, pequena);

        if(substring == NULL){
            break;
        }

        locais[repet] = tamGrande - (int)strlen(substring);


        repet++;

        for(int i = 0; i < (int)strlen(substring)-(int)strlen(pequena); i++){
            grande[i] = substring[i+(int)strlen(pequena)];
        }
        grande[(int)strlen(substring)-(int)strlen(pequena)] = '\0';

    }while(substring != NULL);

    printf("Repetições: %d\n", repet);

    if(repet > 0){
        printf("Posições: ");

        for(int i = 0; i < repet; i++){
            printf("%d ", locais[i]);
        }
    }
}