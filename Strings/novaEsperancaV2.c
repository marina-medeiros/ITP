#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int validaMensagem(char mensagem[200], int indices[200], const char S[40]) {
    int i, j;
    for(i = 0; i < 200; i++) {
        if(mensagem[i] == '\0' || mensagem[i] == '\n') {
        indices[i] = -1;
        return 1;
        }

        int detectado = 0;
        for(j = 0; j < 40; j++) {
        if(S[j] == mensagem[i]) {
            detectado = 1;
            indices[i] = j;
            break;
        };
        }

        if(detectado != 1) {
        return 0;
        };
    };

    return 1;
};

void codifica(int indices[200], const char S[40], int chave[4], char mensagemCifrada[200]) {
  int key = 0, i, indiceAntigo, novoIndice;
  for(i = 0; i < 200; i++) {
    indiceAntigo = indices[i];

    if(indiceAntigo == -1) {
      mensagemCifrada[i] = '\0';
      break;
    };

    novoIndice = (indiceAntigo + chave[key]) % 40;
    key = (key + 1) % 4;

    mensagemCifrada[i] = S[novoIndice];
  }
}

int main() {
  char mensagemCifrada[200];
  char mensagem[200];
  int chave[4];
  const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

  char strchave[7];

  fgets(strchave, sizeof(strchave), stdin);

  if(strlen(strchave) > 5) {
    printf("Chave invalida!");
    return 0;
  };

  for(int i = 0; i < 4; i++) {
    chave[i] = strchave[i] - '0';
  };
  
  fflush(stdin);
  fgets(mensagem, sizeof(mensagem), stdin);

  int indices[200];

  if(validaMensagem(mensagem, indices, S)) {
    codifica(indices, S, chave, mensagemCifrada);
    printf("%s", mensagemCifrada);
  } else {
    printf("Caractere invalido na entrada!");
  };

  return 0;
};