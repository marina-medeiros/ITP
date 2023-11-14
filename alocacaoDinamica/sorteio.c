#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  char **PARTICIPANTES = NULL;
  int N = 0;
  int *sorteados = NULL;
  int semente;

  PARTICIPANTES = (char **)malloc(sizeof(char *));

  char nome[100];

  while (1) {
    scanf("%[^\n]", nome);
    getchar();

    if (strcmp(nome, "acabou") == 0) {
      break;
    }

    PARTICIPANTES[N] = (char *)malloc(strlen(nome) + 1);

    strcpy(PARTICIPANTES[N], nome);
    N++;

    PARTICIPANTES = (char **)realloc(PARTICIPANTES, (N + 1) * sizeof(char *));
  }

  scanf("%d", &semente);
  srand(semente);

  sorteados = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    sorteados[i] = 0;
  }

  while (1) {
    int indice_participante = rand() % N;

    if (sorteados[indice_participante] == 0) {
      printf("%s\n", PARTICIPANTES[indice_participante]);
      sorteados[indice_participante] = 1;
    }

    int todosSorteados = 1;

    for (int i = 0; i < N; i++) {
      if (sorteados[i] == 0) {
        todosSorteados = 0;
        break;
      }
    }

    if (todosSorteados) {
      break;
    }
  }

  for (int i = 0; i < N; i++) {
    free(PARTICIPANTES[i]);
  }

  free(PARTICIPANTES);
  free(sorteados);

  return 0;
}