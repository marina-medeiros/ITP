#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    int disponivel;
}Pessoa;

int main(){
    int qtdEntradas, presentes = 0;
    char acao[10], nome[20];

    scanf("%d", &qtdEntradas);

    Pessoa lista[qtdEntradas];

    for(int i = 0; i < qtdEntradas; i++){
        scanf("%s", acao);

        if(strcmp(acao, "INSERIR") == 0){
            scanf(" %[^\n]", nome);
            strcpy(lista[presentes].nome, nome);
            lista[presentes].disponivel = 1;
            presentes++;
        }
        if(strcmp(acao, "REMOVER") == 0){
            scanf(" %[^\n]", nome);
            for(int i = 0; i < presentes; i++){
                if(strcmp(lista[i].nome, nome) == 0){
                    lista[i].disponivel = 0;
                }
            }
        }
        if(strcmp(acao, "IMPRIMIR") == 0){
            printf("Atualmente trabalhando:\n");
            for(int i = 0; i < presentes; i++){
                if(lista[i].disponivel == 1){
                    printf("%s\n", lista[i].nome);
                }
            }
        }
    }

}
