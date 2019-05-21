#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int nombreMystere = 0, nombreEntre = 0;
    const int  MIN = 1;
    int continuerPartie = 1 , choix = 0;



   do {
         //Création du menu du jeu
         printf("\n\nNotre petit jeu contient trois deffirents  niveaux de difficulte : \n\n");
         printf("I) Niveau 1 : entre 1 et 100\n\n") ;
         printf("II) Niveau 2 : entre 1 et 1000 \n\n") ;
         printf("III) Niveau 3 : entre 1 et 10000 \n\n \tVotre choix :" ) ;
         scanf("%d",&choix);

switch(choix){
case 1 :{
       // Initialisation de la variable MAX .
       int MAX = 100 ;
      // Génération du nombre aléatoire

    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

         // creation  d'une variable compteur
    int compteur = 01  ;

    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */

    do
    {
        // On demande le nombre
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);

        // On compare le nombre entré avec le nombre mystère

        if (nombreMystere > nombreEntre)
           {    printf("C'est plus !\n\n");
                compteur++ ;
           }
        else if (nombreMystere < nombreEntre)
            {
                printf("C'est moins !\n\n");
                compteur++ ;
            }

        else
            printf ("Bravo, vous avez trouve le nombre mystere  en %d coups!!!\n\n",compteur);
    } while (nombreEntre != nombreMystere);
    }
break ;

case 2 :{
       // Initialisation de la variable MAX .
       int MAX = 1000 ;
      // Génération du nombre aléatoire

    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

         // creation  d'une variable compteur
    int compteur = 01  ;

    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */

    do
    {
        // On demande le nombre
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);

        // On compare le nombre entré avec le nombre mystère

        if (nombreMystere > nombreEntre)
           {    printf("C'est plus !\n\n");
                compteur++ ;
           }
        else if (nombreMystere < nombreEntre)
            {
                printf("C'est moins !\n\n");
                compteur++ ;
            }

        else
            printf ("Bravo, vous avez trouve le nombre mystere  en %d coups!!!\n\n",compteur);
    } while (nombreEntre != nombreMystere);
    }
break ;

case 3 :{
       // Initialisation de la variable MAX .
       int MAX = 10000 ;
      // Génération du nombre aléatoire

    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

         // creation  d'une variable compteur
    int compteur = 01  ;

    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */

    do
    {
        // On demande le nombre
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);

        // On compare le nombre entré avec le nombre mystère

        if (nombreMystere > nombreEntre)
           {    printf("C'est plus !\n\n");
                compteur++ ;
           }
        else if (nombreMystere < nombreEntre)
            {
                printf("C'est moins !\n\n");
                compteur++ ;
            }

        else
            printf ("Bravo, vous avez trouve le nombre mystere  en %d coups!!!\n\n",compteur);
    } while (nombreEntre != nombreMystere);
    }
break ;

}

        printf("Voulez vous rejouez une autre fois ?? \n si oui , Tapez (1) . \n sinon , Tapez (0)\n\n \tVotre decision : ") ;
        scanf("  %d",&continuerPartie);

   }  while (continuerPartie!=0 );

    return 0;
}
