#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"


int main()
{
    Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    suppression(maListe);

    afficherListe(maListe);
    ///********************

    printf("\n\n \t Maintenant c est *** La PILE ***\n") ;
       Pile *maPile = initialiserPile();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("\n\n \t Maintenant c est *** La FILE ***\n") ;
    File *maFile = initialiserFile() ;
    enfiler(maFile,4);
    enfiler(maFile,8);
    enfiler(maFile,15);
    enfiler(maFile,16);
    enfiler(maFile,23);
    enfiler(maFile,42);
    printf("\nEtat de la file :\n\n\n");
    afficherFile(maFile) ;

    printf("\n\n Je defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));
    printf("\nEtat de la file :\n\n\n");
    afficherFile(maFile) ;
    printf("\n\n\t\t  FUCK YOU ************") ;
    return 0;
}

