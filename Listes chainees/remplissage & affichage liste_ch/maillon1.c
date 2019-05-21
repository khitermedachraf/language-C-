/*
 **************************************
 *  implémentation du module maillon  *
*           (Modèle des LLC)          *
 **************************************
*/


#include <stdlib.h>	// pour malloc et free

#include "maillon1.h"


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


    void affichage (Tptr tete) {
        int cpt=0;
        printf("L'affichage : \n") ;

        printf("*****************************\n") ;
            while ( tete != NULL)  {
                printf("maillon Num %d = %ld \n",cpt,tete->val) ;
                tete = Suivant(tete) ;
                cpt++ ;
            }

        return  ;
}
