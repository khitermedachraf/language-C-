// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

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
Tptr remplissage (void) ;
 //void affichage (Tptr tete) ;
  Tptr  acces_par_valeure ( Tptr tete , int val , Tptr* adr) ;



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
Tptr remplissage (void){
    int n , val ;
    printf("creation d'une liste chainee : \n");
    printf("***********************\n") ;
    printf("Donner le nombre de maillons que vous voulez creer : ");
    scanf("%d",&n) ;
    Tptr P,Q,tete ;
    Allouer(&tete) ;
    printf("Donner une valeure initiale pour la Tete : ") ;
    scanf("%d",&val) ;
    Aff_val(tete,val);
    P=tete;
    for (int i=0 ; i <n-1 ; i++ ) {

            Allouer(&Q) ;
            int a ;
            printf("Donner la valeure de maillon : ") ;
            scanf("%d",&a) ;
            Aff_val(Q,a) ;
            Aff_adr(P,Q);
            P=Q ;
    }

    Aff_adr(Q,NULL) ;


        return(tete);
    }


   Tptr  acces_par_valeure ( Tptr tete , int val , Tptr* adr) {

        int trouv = 0 ;
        Tptr P ;
        P = tete ;

        while( P != NULL && trouv == 0 ) {

            if(Valeur(P)== val){
                trouv = 1 ;
                 *adr = P ;
            }else { P = Suivant(P);}

        }


            return (adr);
    }




