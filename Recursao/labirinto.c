# include <stdio.h>
#include <string.h>

int procuraCaminho(int x, int y, int LimX, int LimY, char mapa[LimX][LimY], int check[LimX][LimY]){
  int achou;

  if(mapa[x][y] == 'F'){ 
    printf("Chegou em %d %d\n", x, y);
    return 1;
  }
  if(x-1 >=0 && (mapa[x-1][y] == '0' || mapa[x-1][y] == 'F') && check[x-1][y] == 0){
    check[x][y] = 1;
    achou = procuraCaminho(x-1, y, LimX, LimY, mapa, check);
    //check[x][y] = 0;

    if(achou){
      printf("E antes veio de %d %d\n", x, y);
      return 1;
    }
  }
  if(x+1 <LimX && (mapa[x+1][y] == '0' || mapa[x+1][y] == 'F') && check[x+1][y] == 0){
    check[x][y] = 1;
    achou = procuraCaminho(x+1, y, LimX, LimY, mapa, check);
    //check[x][y] = 0;

    if(achou){
      printf("E antes veio de %d %d\n", x, y);
      return 1;
    }
  }
  if(y-1 >=0 && (mapa[x][y-1] == '0' || mapa[x][y-1] == 'F') && check[x][y-1] == 0){
    check[x][y] = 1;
    achou = procuraCaminho(x, y-1, LimX, LimY, mapa, check);
    //check[x][y] = 0;

    if(achou){
      printf("E antes veio de %d %d\n", x, y);
      return 1;
    }
  }
  if(y+1 < LimY && (mapa[x][y+1] == '0' || mapa[x][y+1] == 'F') && check[x][y+1] == 0){
    check[x][y] = 1;
    achou = procuraCaminho(x, y+1, LimX, LimY, mapa, check);
    //check[x][y] = 0;

    if(achou){
      printf("E antes veio de %d %d\n", x, y);
      return 1;
    }
  }

  return 0;
}

int main(){
  int x, y;
  int posI, posY;

  scanf("%d %d", &x, &y);

  char mapa[x][y];
  int visitado[x][y];

  memset(visitado, 0, sizeof(visitado));

  for(int i = 0; i<x; i++)
    for(int j=0; j<y; j++)
      scanf(" %c", &mapa[i][j]);

  scanf("%d %d", &posI, &posY);

  mapa[posI][posY] = 'F';

  scanf("%d %d", &posI, &posY);

  if(!procuraCaminho(posI, posY, x, y, mapa, visitado)){
    printf("Nao ha caminho valido...\n");
  }
  else{
    printf("Onde tudo comecou\n");
  }

  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
        printf("%d", visitado[i][j]);
    }
    printf("\n");
  }

  return 0;
}