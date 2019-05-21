/*
 *
 * Programme de démonstration des Listes Linéaires Chaînées (LLC)
 * Génération des nombres premiers <= n
 * par vérification du voisinage des multiples de 6 (c-a-d 6k-1 et 6k+1)
 *
 * Hidouci W.K. / ALSDD / 1CPI / ESI / 2019
 *
 */



// Les E/S standards (printf, scanf, ...)
#include <stdio.h>

// pour sqrt (la racine carrée d'un nombre)
#include <math.h> 	

// pour atol (conversion d'une chaine de caractère en long int)
#include <stdlib.h>	

// pour mesurer les durées de temps: gettimeofday(...) et struct timeval
#include <sys/time.h> 	

// interface du modèle LLC
#include "maillon.h"


// Affichage d'une liste de tête p
void affich( Tptr p );


// Programme principal
int main( int argc, char *argv[] )
{
   Tptr p, dernier, tete;
   Tval x;
   int premier;
   long n, k, cpt, racine_n;
   char rep[10];
   long t; 			// durée du traitement (microsecondes)
   struct timeval tv1, tv2; 	// pour récupérer les temps avec gettimeofday(...)

   
   if ( argc == 2 )
	// récupérer le paramètre n depuis la ligne de commande ...
	n = atol( argv[1] );
   else  {
	// ou alors depuis l'entrée standard ...
	printf( "Donnez le paramètre n (>3) : " );
	scanf( " %ld", &n );
   }

   gettimeofday(&tv1,NULL);	// tv1: le temps de départ

   // Construction d'une liste avec les 2 premiers nombres premiers (2 et 3) ...
   Allouer( &tete );
   Aff_val( tete, 2 );
   Allouer( &p );
   Aff_val( p, 3 );
   Aff_adr( tete, p );
   Aff_adr( p, NULL );
   dernier = p;	// le dernier maillon de la liste

   cpt = 2;	// compteur de nombres premiers

   /* Boucle principale pour tester tous les x <= n de la forme 6k-1 ou 6k+1 */
   k = 1;
   x = 6*k - 1;
   racine_n = sqrt(n);

   while ( x <= n ) {

	// vérifier si x est premier ...
	premier = 1;
	p = Suivant(tete); // on commence les tests à partir de 3

	while ( p != NULL && premier && Valeur( p ) <= racine_n )
	   if ( x % Valeur( p ) != 0 )  // si x n'est pas divisible par Valeur(p)
		p = Suivant( p );
	   else  
		premier = 0;

	// si x est premier, l'insérer en fin de liste ...
	if ( premier ) {
	   Allouer( &p );
	   Aff_val( p, x );
	   Aff_adr( p, NULL );
	   Aff_adr( dernier, p );
	   dernier = p;
	   cpt++;
	}

	// passer au prochain nombre à tester ...
	if ( x == (6*k - 1) )   
	   x = 6*k + 1;
	else {
	   k++;
	   x = 6*k - 1;
	}

   } // fin while (x <= n)

   gettimeofday(&tv2,NULL); 	// tv2: le temps de terminaison

   // durée de l'opération en microseconde ...
   t = (tv2.tv_sec - tv1.tv_sec)*1000000 + (tv2.tv_usec - tv1.tv_usec);
      
   // Affichage du résultat ...
   printf( "Il y a %ld nombres premiers <= %ld \
	   \nLe dernier nombre premier trouvé est %ld\
	   \nTemps d'exécution = %ld ms \
	   \nAfficher toute la liste ? (o/n) :  ", cpt, n, Valeur( dernier ), t/1000 );

   scanf( " %s", rep );
   if ( rep[0] == 'o' || rep[0] =='O' ) {
      printf( "La liste des nombres premiers :\n" );
      affich( tete );
      printf( "\n" );
   }

   return 0;

} // fin_main




/* Afficher les éléments de la liste p */

void affich( Tptr p )
{

   while ( p != NULL ) {
	printf( "%ld ", Valeur(p) );
	p = Suivant(p);
   }
   printf( "#\n" );

}  // fin affich



