/*
 * ALSDD - Récursivité - 2018/2019
 * Algo des tours de Hanoi
*/

#include <stdio.h>

int etape = 1;

void hanoi( int n, char x, char y, char z );


int main ( void )
{

   int n;

   printf( "Donner le nombre disques à déplacer " );
   scanf( " %d", &n );

   printf( "Pour déplacer %d disques entre A et B (avec C comme intermédiaire), il faut :\n", n );
  
   hanoi( n, 'A', 'B', 'C' );

   printf( "---\n\n" );

   return 0;

}


// Transfert de n disques de x vers y en utilisant z comme intermédiaire
void hanoi( int n, char x, char y, char z )
{

   if ( n > 0 ) {
	// on commence par transférer les n-1 premiers disques de x vers z
	hanoi( n-1, x, z, y );

	// ensuite on déplace le disque restant de x vers y
   	printf( "  %2d) déplacer un disque de %c vers %c\n",etape++, x, y );   

	// et on termine par transférer les n-1 disques de z vers y
	hanoi( n-1, z, y, x );
   }

}

