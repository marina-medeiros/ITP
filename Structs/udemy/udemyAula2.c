#include <stdio.h>
#include <string.h>

struct st_aluno{
    char matricula[10];
    char nome[100];
    char curso[50];
    int ano_nascimento;
}alunos[5];

struct st_contato{
    char nome[100];
    int ano_nascimento;
    char telefone[20];
    char email[100];
};

struct st_agenda{
    struct st_contato contatos[100]; //um array de contatos
}agenda;

int main(){

    for(int i = 0; i < 5; i++){
        printf("Informe o nome do aluno: ");
        fgets(agenda.contatos[i].nome, 100, stdin);

        printf("Informe o ano de nascimento do aluno: ");
        scanf("%d", &agenda.contatos[i].ano_nascimento);
        getchar();

        printf("Informe o email: ");
        fgets(agenda.contatos[i].email, 50, stdin);

        printf("Informe o telefone: ");
        fgets(agenda.contatos[i].telefone, 50, stdin);

        getchar();

    }

    
    printf("=======AGENDA=========\n");

    for(int i = 0; i < 5; i++){
        printf("=======CONTATO %d=========\n", (i+1));
        printf("Nome: %s\n", agenda.contatos[i].nome);
        printf("Telefone: %s\n", agenda.contatos[i].telefone);
        printf("Email: %s\n", agenda.contatos[i].email);
        printf("Ano de nascimento: %d\n", agenda.contatos[i].ano_nascimento);

    }


}