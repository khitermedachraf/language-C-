/*
 **************************************
 *  implémentation du module maillon  *
*           (Modèle des LLC)          *
 **************************************
*/


#include <stdlib.h>	// pour malloc et free

#include "maillon.h"	


void Allouer( Tptr *p )
// c-a-d struct maillon **p
{
   *p = malloc( sizeof(struct Tmaillon) );
}


void Liberer( Tptr *p )
{
   free( *p );
}


void Aff_val( Tptr p, Tval v )
{
   p->val = v;
}


void Aff_adr( Tptr p, Tptr q )
{
   p->adr = q;
}


Tval Valeur( Tptr p )
{
   return p->val;
}


Tptr Suivant( Tptr p )
{
   return p->adr;
}


