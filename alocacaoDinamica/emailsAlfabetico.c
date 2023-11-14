#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int inicio;
    int fim;
    char email[50];
    char extraido[20];
}Email;

void extrair(Email *listaEmails, int qtdEmails){
    for(int i = 0; i < (int)strlen(listaEmails[qtdEmails].email); i++){
        if(listaEmails[qtdEmails].email[i] == '@'){
            listaEmails[qtdEmails].inicio = i;
            break;
        }
    }
    for(int i = listaEmails[qtdEmails].inicio; i < (int)strlen(listaEmails[qtdEmails].email); i++){
        if(listaEmails[qtdEmails].email[i] == '.'){
            listaEmails[qtdEmails].fim = i;
            break;
        }
    }

    int count = 0;

    for(int i = (listaEmails[qtdEmails].inicio + 1); i < (listaEmails[qtdEmails].fim); i++){
        listaEmails[qtdEmails].extraido[count] = listaEmails[qtdEmails].email[i];
        count++;
    }

    listaEmails[qtdEmails].extraido[count] = '\0';

}

int verificaSort(Email *listaEmails, int qtdEmails){
    for(int i = 1; i < qtdEmails; i++){
        if(strcmp(listaEmails[i].extraido, listaEmails[i-1].extraido) < 0){
            return 1;
        }
    }

    return 0;
}

void organiza(Email *listaEmails, int qtdEmails){
    Email aux;
    do{
        for(int i = 1; i < qtdEmails; i++){
            if(strcmp(listaEmails[i].extraido, listaEmails[i-1].extraido) < 0){
                strcpy(aux.extraido, listaEmails[i].extraido);
                strcpy(listaEmails[i].extraido, listaEmails[i-1].extraido);
                strcpy(listaEmails[i-1].extraido, aux.extraido);
            }
        }
    }while(verificaSort(listaEmails, qtdEmails) == 1);
}

void printDominios(Email *listaEmails, int qtdEmails){
    for(int i = 0; i < qtdEmails; i++){
        printf("%s\n", listaEmails[i].extraido);
    }
}

int main(){
    Email *listaEmails = (Email*)malloc(sizeof(Email));
    int qtdEmails = 0;
    char email[50];

    do{
        scanf("%s", email);
        getchar();

        if(strcmp(email, "FIM") == 0){
            break;
        }
        
        listaEmails = realloc(listaEmails, sizeof(Email) * (qtdEmails + 1));

        strcpy(listaEmails[qtdEmails].email, email); 

        extrair(listaEmails, qtdEmails);

        qtdEmails++;

    }while(strcmp(email, "FIM") != 0);

    organiza(listaEmails, qtdEmails);

    printDominios(listaEmails, (qtdEmails));

}