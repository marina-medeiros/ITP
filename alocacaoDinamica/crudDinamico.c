#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

int posPessoas = 0;

Pessoa criar(){
  Pessoa added;
  getchar();
  scanf("%[^\n]", added.nome);
  scanf("%d", &added.idade);
  scanf(" %c", &added.sexo);
  return added;
}

void inserir(Pessoa *vetorDePessoas, Pessoa add){
  vetorDePessoas[posPessoas] = add;
  printf("Pessoa adicionada %d: %s, %d, %c\n", posPessoas, vetorDePessoas[posPessoas].nome, vetorDePessoas[posPessoas].idade, vetorDePessoas[posPessoas].sexo);
  posPessoas++;
  vetorDePessoas = realloc(vetorDePessoas, sizeof(Pessoa) * (posPessoas + 1));
  //printf("Pessoa adicionada %d: %s, %d, %c\n", posPessoas, vetorDePessoas[posPessoas-1].nome, vetorDePessoas[posPessoas-1].idade, vetorDePessoas[posPessoas-1].sexo);
}

void deletar(Pessoa *vetorDePessoas, Pessoa del){
  int posDel, aux = 0;
  for(int i = 0; i < posPessoas; i++){
    if(vetorDePessoas[i].idade == del.idade && vetorDePessoas[i].sexo == del.sexo && strcmp(vetorDePessoas[i].nome, del.nome) == 0){
      posDel = i;
      aux++;
      break;
    }
  }
  for(int i = posDel; i < posPessoas; i++){
    vetorDePessoas[i] = vetorDePessoas[i+1];
  }
  posPessoas = posPessoas - aux;
  vetorDePessoas = realloc(vetorDePessoas, sizeof(Pessoa) * (posPessoas + 1));
  
}

void imprimir(Pessoa *vetorDePessoas){
  for(int i = 0; i < posPessoas; i++){
    printf("%d %s, %d, %c\n", posPessoas, vetorDePessoas[i].nome, vetorDePessoas[i].idade, vetorDePessoas[i].sexo);
  }
  printf("%d %s, %d, %c\n", posPessoas, vetorDePessoas[0].nome, vetorDePessoas[0].idade, vetorDePessoas[0].sexo);
}

int main() {
  Pessoa *vetorDePessoas = malloc(sizeof(Pessoa) * (posPessoas+1));
  char acao = 'x';
  
  while(acao != 'p'){
    scanf(" %c", &acao);
    if(acao == 'i'){
      inserir(vetorDePessoas, criar());
    }else if (acao =='d'){
      deletar(vetorDePessoas, criar());
    }
  }
  imprimir(vetorDePessoas);
}