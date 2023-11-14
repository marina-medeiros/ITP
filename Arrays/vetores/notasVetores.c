#include <stdio.h>
#include <locale.h> 

int main() {
  setlocale(LC_ALL, "Portuguese");
  int tam, i, pos;
  float nota;

  scanf("%d", &tam);

  float vetor[tam + 1];

  // Inicialize os contadores
  int reprovados = 0, aprovados = 0, rec = 0;

  // lê as notas e coloca no vetor
  for (i = 1; i <= tam; i++) {
    scanf("%d - %f", &pos, &nota);
    vetor[pos] = nota;

    // Atualize os contadores com base nas notas
    if (nota < 5) {
      reprovados++;
    } else if (nota >= 5 && nota < 7) {
      rec++;
    } else if (nota >= 7) {
      aprovados++;
    }
  }

  // Declare os vetores com base nos contadores
  float vApro[aprovados], vRepro[reprovados], vRec[rec];
  int posApro[aprovados], posRepro[reprovados], posRec[rec];

  // Inicialize os índices dos vetores
  int idxApro = 0, idxRepro = 0, idxRec = 0;

  // Preencha os vetores de acordo com as notas
  for (i = 1; i <= tam; i++) {
    if (vetor[i] < 5) {
      vRepro[idxRepro] = vetor[i];
      posRepro[idxRepro] = i;
      idxRepro++;
    } else if (vetor[i] >= 5 && vetor[i] < 7) {
      vRec[idxRec] = vetor[i];
      posRec[idxRec] = i;
      idxRec++;
    } else if (vetor[i] >= 7) {
      vApro[idxApro] = vetor[i];
      posApro[idxApro] = i;
      idxApro++;
    }
  }

  // Imprima os resultados
  printf("Aprovados: ");
  for (i = 0; i < aprovados; i++) {
    if(i == (aprovados-1)){
        printf("%d (%.1f)\n", posApro[i], vApro[i]);
    }else{
        printf("%d (%.1f), ", posApro[i], vApro[i]);
    }
  }

  printf("Recuperação: ");
  for (i = 0; i < rec; i++) {
    if(i == (rec-1)){
        printf("%d (%.1f)\n", posRec[i], vRec[i]);
    }else{
        printf("%d (%.1f), ", posRec[i], vRec[i]);
    }
  }
  printf("Reprovados: ");
  for (i = 0; i < reprovados; i++){
    if(i == (reprovados-1)){
        printf("%d (%.1f)\n", posRepro[i], vRepro[i]);
    }else{
        printf("%d (%.1f), ", posRepro[i], vRepro[i]);
    }
  }
}