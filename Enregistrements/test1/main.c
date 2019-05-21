#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct personne personne ;
struct personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];

    int age;
    ///int garcon; // Booléen : 1 = garçon, 0 = fille
};

int main()
{
    printf("Hello world!\n");
    personne joueur[2] ;


         for (int i=-1 ;i<1 ;i++)
         {
            printf("Joueur Num %d \n",i+2) ;
            printf("*************\n");
            printf("Quel est votre nom ? ");
            scanf("%s", joueur[i].nom);
            printf("Votre prenom ? ");
            scanf("%s", joueur[i].prenom);
            printf("Votre adresse ? ");
            scanf("%s",joueur[i].adresse );
            printf("Votre age ?" ) ;
            scanf("%d\n",&joueur[i].age);

         };




    return 0;

}
