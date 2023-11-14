#include <stdio.h>

int main( )
{
   int  x = 5;
   int *y = &x;
   int z = *y; //z recebe o valor q está no endereço de y (5)
   printf( "%i, %i, %i\n", x, *y, z );
 
   x = 7;
   printf( "%i, %i, %i\n", x, *y, z ); //
 
   *y = 2;
   printf( "%i, %i, %i\n", x, *y, z );
   return 0;

}

