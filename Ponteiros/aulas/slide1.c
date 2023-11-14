#include <stdio.h>

int main( )
{
   int i = 2;
   int j = i * i; //4
   int *k = &i; //2
   int m = *k * *k; //2 * 2 = 4
   *k = j * *k * m; //4 * 2 * 4 = 32
 
   printf("%d %d %d %d", i, j, *k, m );
   return 0;
}

