#include <stdio.h>
#include <string.h>

typedef struct st_pessoa {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

int numPessoasAdicionadas = 0;

Pessoa criar(){
  Pessoa added;
  getchar();
  scanf("%[^\n]", added.nome);
  scanf("%d", &added.idade);
  scanf(" %c", &added.sexo);
  return added;
}

void inserir(Pessoa vetorDePessoas[200], Pessoa add){
  vetorDePessoas[numPessoasAdicionadas] = add;
  numPessoasAdicionadas++;
}

void deletar(Pessoa vetorDePessoas[200], Pessoa del){
  int posDel, aux = 0;
  //Vê quais são as posições das pessoas que tem que deletar
  for(int i = 0; i < numPessoasAdicionadas; i++){
    if(vetorDePessoas[i].idade == del.idade && vetorDePessoas[i].sexo == del.sexo && strcmp(vetorDePessoas[i].nome, del.nome) == 0){
      posDel = i; //1
      aux++;
    }
  }
  //muda as posições do vetor      
  for(int i = posDel; i < numPessoasAdicionadas; i++){
    vetorDePessoas[i] = vetorDePessoas[i+1];
  }
  numPessoasAdicionadas = numPessoasAdicionadas - aux;
}

void imprimir(Pessoa vetorDePessoas[200]){
  for(int i = 0; i < numPessoasAdicionadas; i++){
    printf("%s,%d,%c\n", vetorDePessoas[i].nome, vetorDePessoas[i].idade, vetorDePessoas[i].sexo);
  }
}

int main() {
  Pessoa vetorDePessoas[200];
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