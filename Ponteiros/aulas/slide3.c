#include <stdio.h>

int main( void )
{
   int x, y = 0, *p = NULL;
   p = &y;
   x = *p;
   x = 4;
   (*p)++;
   --x;
   (*p) += x;
 
   printf( "%i %i %i", x, y, *p );
   return 0;
}
