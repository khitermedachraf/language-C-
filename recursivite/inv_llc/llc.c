/*
 * ALSDD - Récursivité - 2018/2019
 * Implémentation du modèle des listes linéaires chaînées LLC
*/

#include "llc.h"


void Allouer( Tptr *p )
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


