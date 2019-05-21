/*
 * ALSDD - Récursivité - 2018/2019
 * Déclaration du modèle des listes linéaires chaînées LLC
*/


#ifndef LLC_H
#define LLC_H

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

#endif

