#include <stdio.h>
#include <string.h>

int main(){
    char frase[61];
    int i = 0;

    fgets(frase, 61, stdin);

    while(frase[i] != '\0'){
        if(i == 0){
            frase[i] = toupper(frase[i]);
        }
        else if(frase[i-1] == ' '){
            frase[i] = toupper(frase[i]);
        }
        else{
            frase[i] = tolower(frase[i]);
        }
        
        i++;
    }

    printf("%s\n", frase);
}