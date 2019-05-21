/*
 * ALSDD - Récursivité - 2018/2019
 * Implémentation du modèle des listes linéaires chaînées LLC
*/

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


