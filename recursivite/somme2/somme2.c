/*
 * ALSDD - Récursivité - 2018/2019
 * Une autre version de la somme des n entiers naturels 1+2+...+n
 * avec plus d'affichage de traces et de mise en évidence 
 * des imbrications des appels.
*/



#include <stdio.h>

int somme( int imb, int n );


int main ( void )
{
   int n, s;

   printf( "main: Donner un nombre " );
   scanf( " %d", &n );
  
   s = somme( 0, n );

   printf( "main: La somme des %d premiers entiers naturels est : %d \n\n", n, s );
   return 0;
}


int somme( int imb, int n )
{
   int i, result=0;
   char tab[50];

   for (i=0; i<imb; i++) tab[i] = '\t';
   tab[imb] = '\0';

   printf( "\t%s1- Début de somme: imb=%d, n=%d et result=%d\n", tab, imb, n, result );   
   if ( n == 0 ) {
   	printf( "\t%s2- Milieu de somme: result=0\n", tab );
	result = 0;
   }
   else {
   	printf( "\t%s2- Milieu de somme: result=%d+somme(%d,%d)\n", tab, n, imb+1, n-1 );
	result = n + somme(imb+1, n-1 );
   }
   printf( "\t%s3- Fin de somme:   imb=%d, n=%d et result=%d\n", tab, imb, n, result );
   return result;
}

