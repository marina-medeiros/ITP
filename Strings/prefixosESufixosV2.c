#include <stdio.h>
#include <string.h>

void apagaPrefixoOuSufixo(char* string, char* substring) {
    char *caso = string;
    int tamanhoSubstring = strlen(substring);
    
    while ((caso = strstr(caso, substring)) != NULL) {
        memmove(caso, caso + tamanhoSubstring, strlen(caso + tamanhoSubstring) + 1);
    }
}

int main() {
    char prefixos[10][10], sufixos[10][10], palavras[100][100];
    int qntdPrefixos, qntdSufixos, i, j, contador = 0;

    scanf("%d", &qntdPrefixos);
    for (i = 0; i < qntdPrefixos; i++)
        scanf("%s", prefixos[i]);

    scanf("%d", &qntdSufixos);
    for (i = 0; i < qntdSufixos; i++)
        scanf("%s", sufixos[i]);

    while (1) {
        scanf("%s", palavras[contador]);
        if (strcmp(palavras[contador], "-1") == 0){
            break;
        }   
        contador++;
    }

    for(i = 0; i < qntdPrefixos; i++)
        for (j = 0; j < contador; j++)
            apagaPrefixoOuSufixo(palavras[j], prefixos[i]);
    
    for(i = 0; i < qntdSufixos; i++){
        for (j = 0; j < contador; j++){
            apagaPrefixoOuSufixo(palavras[j], sufixos[i]);
        }      
    }

    for(i = 0; i < contador; i++){
        printf("%s\n", palavras[i]);
    }
    return 0;
}