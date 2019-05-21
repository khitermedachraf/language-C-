/*
 *  ALSDD 2019
 *  Exemple de programme utilisant le module TDO (Tableau Dynamique Ordonné)
 *
*/

#include <stdio.h>	// pour les E/S standards : printf()...
#include <stdlib.h>	// pour les fonction rand() et srand()
#include <time.h>	// pour la fonction time()

#include "tdo.h"	// Entete du module TDO


int main( void )
{
   TDO *t = NULL;
   int v, n, m;
   char rep[10];

   do {
      if ( t != NULL ) {
   	printf("Le contenu du tableau est :\n");
   	Affich( t );
      } // if
      printf("\n\t\t- M E N U -\n\n");
      printf("1) Allouer le tableau dynamique ordonné avec une certaine taille\n");
      printf("2) Détruire le tableau dynamique ordonné\n");
      printf("3) Remplir le tableau dynamique ordonné avec n valeurs initiales (aléatoirement) \n");
      printf("4) Insérer une nouvelle valeur unique dans le tableau dynamique ordonné\n");
      printf("0) Quitter le programme\n\n");
      printf("\tVotre choix : ");
      scanf(" %d", &m);
      switch(m) {
	case 1 : // Allocation d'un nouveau tableau ...
	    printf("Allocation d'un nouveau tableau ...\n");
	    if ( t != NULL ) {
		printf("un tableau existe déjà, il faut d'abord le détruire avant d'allouer un nouveau\n");
		printf("voulez-vous le détruire (o/n) ?");
		scanf(" %s", rep);
		if ( rep[0] == 'o' || rep[0] == 'O' ) {
			LibererTab( t );
			t = NULL;
		}
	    }
	    if ( t == NULL ) {
		printf("donnez la taille (en nombre d'éléments) du tableau à allouer : ");
		scanf(" %d", &n);
		t = AllouerTab( n );
	    }
	    break;

	case 2 : // Destruction d'un tableau existant ...
	    printf("Destruction du tableau courant ...\n");
	    if ( t != NULL ) {
		printf("le contenu de l'ancien tableau sera perdu par cette opération," \
			" continuez ? (o/n) ");
		scanf(" %s", rep);
		if ( rep[0] == 'o' || rep[0] == 'O' ) {
			LibererTab( t );
			t = NULL;
		}
	    }
	    break;

	case 3 : // Remplissage du tableau existant ...
	    printf("Remplissage du tableau courant ...\n");
	    if ( t != NULL ) {
		if ( t->NbElem > 0 ) {
		   printf("le contenu de l'ancien tableau sera ecrasé par cette opération,"\
			  " continuez ? (o/n) ");
		   scanf(" %s", rep);
		   if ( rep[0] == 'o' || rep[0] == 'O' ) 
			t->NbElem = 0;
		}
		if ( t->NbElem == 0 ) {
		   printf("donnez le nombre de valeurs à générée dans le tableau : ");
		   scanf(" %d", &n);
		   Remplir( n, t );
		}
	    }
	    break;

	case 4 : // Insertion d'une valeur dans le tableau dynamique ordonné ...
	    printf("Insertion d'une valeur donnée ...\n");
 	    if ( t != NULL ) {
		printf("donnez une valeurs à insérée dans le tableau : ");
		scanf(" %d", &v);
	    	Ins( v, t );
	    }
	    break;

      } // switch

   } while ( m != 0); // do

   if ( t != NULL ) LibererTab( t );

   return 0;

} // fin main()


