/*
 * ALSDD - Récursivité - 2018/2019
 * Exemple de l'inversion d'une liste linéaire chaînée LLC
 * (le modèle des LLC est défini dans "llc.h" et est implémenté dans "llc.c")
*/

#include <stdio.h>
#include <stdlib.h>


// Type du champ 'valeur' d'un maillon
typedef char Tval;

typedef struct Tmaillon *Tptr;

// Structure d'un maillon
struct Tmaillon {
	Tval val;
	Tptr adr;
};

// L'interface du module
void Allouer( Tptr *p );
void Liberer( Tptr *p );
void Aff_val( Tptr p, Tval v );
void Aff_adr( Tptr p, Tptr q );
Tval Valeur( Tptr p );
Tptr Suivant( Tptr p );

// Pour afficher la liste de tête p
void affich( Tptr p );
// Pour inverser la liste L1, le résultat est retourné dans L2
void inv( Tptr L1, Tptr *L2 );



int main( int argc, char *argv[] )
{
   Tptr p, q, L1, L2;
   Tval x;
   int n, i;

   // Récupérer la taille de la liste ...
   if ( argc == 2 )
	// depuis la ligne de commande (si elle est donnée)
	n = atoi( argv[1] );
   else {
	// sinon la récupérer par scanf
	printf("Donnez la taille de la liste à construire : ");
	scanf(" %d", &n);
   }

   // Construction d'une liste de n maillons ...
   L1 = NULL;
   for (i=0; i<n; i++) {
   	Allouer( &p );
   	if ( L1 == NULL )
	    L1 = p;
	else
	    Aff_adr( q, p );
   	Aff_val( p, 'A'+i );	// chaque maillon contiendra une lettre
	q = p;
   }
   if ( L1 != NULL )
	Aff_adr( p, NULL );

   // Affichage de la liste initiale ...
   printf( "Prog. Principal: La liste à l'état initial L1 = " );
   affich( L1 );

   // Inversion de la liste ...
   inv( L1, &L2 );

   // Affichage du résultat après l'inversion ...
   printf( "Prog. Principal: La liste résultat L2 = " );
   affich( L2 );

   return 0;
}



// Pour afficher les elts d'une liste
void affich( Tptr p )
{
   while ( p != NULL ) {
	printf( " %c -", Valeur(p) );
	p = Suivant(p);
   }
   printf( "#\n" );
}


// Inverser la liste L1, le résultat sera dans *L2
void inv( Tptr L1, Tptr *L2 )
{
   printf( "Entrée dans inv: L1 = " ); affich(L1);

   if ( L1 != NULL )
	if ( Suivant( L1 ) != NULL ) {
	   inv( Suivant(L1) , L2 );
	   Aff_adr( Suivant(L1), L1 );
	   Aff_adr( L1, NULL );
	}
	else
	   *L2 = L1;
   else
	*L2 = NULL;

   printf( "Sortie de inv: L2 =   " ); affich(*L2);
}



