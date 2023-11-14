#include <stdio.h>
#include <string.h>

int main(){
    char A[41], B[41], *substring, aux[40];
    int count = 0, locais[40], repet = 0;
    
    scanf("%[^\n]", A); //the north remembers norths north
    scanf("%s", B); //north

    printf("A:%s\nB:%s\n", A, B);

    do{
        substring = strstr(A, B);
        printf("substring:%s\n", substring);

        if(substring == NULL){
            break;
        }

        if(repet > 0){
            locais[repet] = (int)strlen(A) - (int)strlen(substring);
        }else{
            locais[repet] = (int)strlen(A) - (int)strlen(substring);
        }

        printf("local: %d \n", locais[repet]);

        for(int i = 0; i < (int)strlen(A)-((int)strlen(B) * (repet + 1)); i++){
            aux[count] = substring[i];
            count++;
        }

        repet++;

        aux[count] = '\0';
        printf("aux:%s\n", aux);
        count = 0;

        strcpy(A, aux);

    }while(substring != NULL);

    printf("%d", repet);

    
}