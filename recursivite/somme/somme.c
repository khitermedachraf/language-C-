/*
 * ALSDD - Récursivité - 2018/2019
 * Exemple de la somme des n entiers naturels 1+2+...+n
*/



#include <stdio.h>

int somme( int n );


int main ( void )
{
   int n, s;

   printf( "main: Donner un nombre " );
   scanf( " %d", &n );
  
   s = somme( n );

   printf( "main: La somme des %d premiers entiers naturels est : %d \n\n", n, s );
   return 0;
}


int somme( int n )
{
   int result;

   printf( "Début  de somme \tn=%d \n", n );   
   if ( n == 0 )
	result = 0;
   else 
	result = n + somme( n-1 );
   printf( "Fin    de somme \tn=%d  result=%d\n", n, result );
   return result;
}

