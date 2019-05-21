
/*
 *********************************
 *  interface du module maillon  *
 *      (Modèle des LLC)         *
 *********************************
*/


#ifndef LLC_H
#define LLC_H


// Tval : Type du champ 'valeur' d'un maillon
typedef long Tval;	// par exemple: long int

// Tptr : Type d'un pointeur vers maillon
typedef struct Tmaillon *Tptr;

// Structure d'un maillon
struct Tmaillon {
	Tval val;
	Tptr adr;	// c-a-d struct maillon *adr;
};

// Declaration des fonctions
void Allouer( Tptr *p );
void Liberer( Tptr *p );
void Aff_val( Tptr p, Tval v );
void Aff_adr( Tptr p, Tptr q );
Tval Valeur( Tptr p );
Tptr Suivant( Tptr p );
Tptr remplissage (void) ;
 void affichage (Tptr tete) ;

#endif

