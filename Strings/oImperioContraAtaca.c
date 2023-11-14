#include <stdio.h>
#include <stdbool.h>

const char S[]=
  {'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z','.',',','?',' '};

int palavraParaIndice(char palavra) {
    int k;
    for(k = 0; k < 40; k++) {
        if(palavra == S[k]) {
        return k;
        }
    }
    
    return -1;
}

void calculaIndices(char KP[28], int KPI[28]) {
    int i;
    for(i = 0; i < 28; i++) {
        KPI[i] = palavraParaIndice(KP[i]);
    }
}

void decifraMensagem(char C[200], int K[4]) {
    int indiceAntigo, indiceNovo;
    for(int i = 0; i < 200; i++) {
        if(C[i] == '\n' || C[i] == '\0') {
            break;
        } 
        else {
            indiceAntigo = palavraParaIndice(C[i]);
            indiceNovo = indiceAntigo - K[i % 4];
            indiceNovo = indiceNovo < 0? 40 + indiceNovo:indiceNovo;

            C[i] = S[indiceNovo];
        }
    }

  printf("%d%d%d%d\n%s", K[0], K[1], K[2], K[3], C);
};

void decifra(char C[200], char KP[28], int K[4]) {
  int kpIndexes[28];
  calculaIndices(KP, kpIndexes);

  int fim = 0;
  for(int i = 0; i < 173; i++) {
    int primeiroGrupoChecado = 0;
    int decifrado = 1;
    
    if(C[i] == '\n' || C[i] == '\0') {
      break;
    };

    for(int k = 0; k < 27; k++) {
      int base = k % 4;
      primeiroGrupoChecado = (base == 0 && k > 0) || primeiroGrupoChecado;

      if(C[i + k] == '\n' || C[i + k] == '\0') {
        fim = 1;
        break;
      };

      int aux = palavraParaIndice(C[i + k]) - kpIndexes[k];
      aux = aux < 0? 40 + aux:aux;

      int index = (i + base) % 4;

      if(!primeiroGrupoChecado) {
        K[index] = aux;
      } else if(K[index] != aux) {
        decifrado = 0;
        break;
      };
    };

    if(fim) {
      break;
    } else if(decifrado) {
      return decifraMensagem(C, K);
    };
  };

  printf("Mensagem nao e da Resistencia!");
};

int main() {
  const char KP[28] = "QUE A FORCA ESTEJA COM VOCE";
  
  int K[4] = {0};
  char C[200];

  fgets(C, sizeof(C), stdin);
  decifra(C, KP, K);

  return 0;
};