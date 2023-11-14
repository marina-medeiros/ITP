#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

Pessoa criar(){
  Pessoa added;
  getchar();
  scanf("%[^\n]", added.nome);
  scanf("%d", &added.idade);
  scanf(" %c", &added.sexo);
  return added;
}

Pessoa* inserir(Pessoa* vetorDePessoas, int* posPessoas, Pessoa add){
  vetorDePessoas[*posPessoas] = add;
  (*posPessoas)++;
  vetorDePessoas = realloc(vetorDePessoas, sizeof(Pessoa)*(*posPessoas + 1));
  return vetorDePessoas;
}

Pessoa* deletar(Pessoa* vetorDePessoas, int* posPessoas, Pessoa del){
  int posDel, aux = 0;
  for(int i = 0; i < *posPessoas; i++){
    if(vetorDePessoas[i].idade == del.idade && vetorDePessoas[i].sexo == del.sexo && strcmp(vetorDePessoas[i].nome, del.nome) == 0){
      posDel = i;
      aux++;
      break;
    }
  }
  for(int i = posDel; i < *posPessoas; i++){
    vetorDePessoas[i] = vetorDePessoas[i+1];
  }
  *posPessoas = *posPessoas - aux;
  vetorDePessoas = realloc(vetorDePessoas, sizeof(Pessoa) * (*posPessoas + 1));
  return vetorDePessoas;
}

void imprimir(Pessoa* vetorDePessoas, int posPessoas){
  for(int i = 0; i < posPessoas; i++){
    printf("%s, %d, %c\n", vetorDePessoas[i].nome, vetorDePessoas[i].idade, vetorDePessoas[i].sexo);
  }
}

int main() {
  int posPessoas = 0; 
  Pessoa* vetorDePessoas = malloc(sizeof(Pessoa) * (posPessoas+1));
  char acao = 'x';

  while(acao != 'p'){
    scanf(" %c", &acao);
    if(acao == 'i'){
      vetorDePessoas = inserir(vetorDePessoas, &posPessoas, criar());
    }else if (acao =='d'){
      vetorDePessoas = deletar(vetorDePessoas, &posPessoas, criar());
    }
  }
  imprimir(vetorDePessoas, posPessoas);
}
