#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct email{
    char email[50];
}Email;

int main(){
    Email *emails = (Email*)malloc(sizeof(Email));
    int c = 0;
    char palavra[50];

    scanf("%[^\n]", palavra);
    printf("%s\n", palavra);

    while(strcmp(palavra, "FIM") != 0){
        emails = realloc(emails, sizeof(Email) * (c+1));
        strcpy(emails[c].email, palavra);
        c++;
        scanf("%[^\n]", palavra);
    }

    for(int i = 0; i < c; i++){
        printf("%s", emails[i].email);
    }

}