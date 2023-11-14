#include <stdio.h>

typedef struct st_smartphone {
  char modelo[40];
  int memoria;
  float processador;
  float camera;
  float bateria;
} Smartphone;

void cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
    getchar(); // Limpa o buffer do teclado
    scanf(" %[^\n]", phones[qnt_cadastrada].modelo);
    scanf("%d", &phones[qnt_cadastrada].memoria);
    scanf("%f", &phones[qnt_cadastrada].processador);
    scanf("%f", &phones[qnt_cadastrada].camera);
    scanf("%f", &phones[qnt_cadastrada].bateria);
    //scanf(" %d %f %f %f", &phones[qnt_cadastrada].memoria,  &phones[qnt_cadastrada].processador, &phones[qnt_cadastrada].camera, &phones[qnt_cadastrada].bateria);

}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin){
    int qntSmartphones = 0;

    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {

            qntSmartphones++;
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
        }
    }
    return qntSmartphones;
}

  int main() {
    Smartphone vetorDeSmartphones[200];
    Smartphone requisitosMinimos;
    char sim_nao = 's';
    int count = 0;

    while (sim_nao != 'n') {
        cadastraSmartphone(count, vetorDeSmartphones);
        count++;
        scanf(" %c", &sim_nao);
    }

    scanf(" %d %f %f %f", &requisitosMinimos.memoria, &requisitosMinimos.processador, &requisitosMinimos.camera, &requisitosMinimos.bateria);
    printf("%d smartphones encontrados.", pesquisaSmartphones(count, vetorDeSmartphones, requisitosMinimos));

  }