#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilisateur.h"







int main(int argc, char *argv[])
{
    creation_DataB();
    int choix =0 ;
   do
   {


                /// Afficher le Menu initial.
            ///Begin
        printf("\n     #Services disponibles sur l'app : \n");
        printf("     *********************************\n\n");
        printf("\t\t\t\t\t\t\t\t Connection au tant qu'un administrateur systeme $:\n");
        printf("\t\t\t\t\t\t\t\t root@root@root@root@root@root@root@root@root@root@\n\n");
        printf("0- Recherche d'un utilisateur .\n");
        printf("1- Creation d'un nouveau utilisateur .\n");
        printf("2- Suppression d'un utilisateur .\n");
        printf("3- Modification d'un utilisateur .\n");
        printf("4- Affichage d'un utilisateur .\n");
        printf("5- Votre liste de suggestion . \n") ;
        printf("6- Abonnement d'un utilisateur .\n");
        printf("7- L'affichage de la liste de followings pour un utilisateur .\n") ;
        printf("8- Sauvgarde de DATA-BASE .\n") ;
        printf("9- Restauration .\n\n\t\t PS: \n ") ;
        printf("                              Si vous fetes un sauvgarde avant une restauration \n");
        printf("                               vous risquez de perdre vos anciennes informations .\n");
        printf("99- Exit .\n\n");
        printf("     #Votre choix est : ");


        scanf("%d",&choix);


            ///End .


/// Traitement d'information
        ///Begin

    switch (choix)
{
case (9):
    restauration() ;
    printf("\n\n\t\t\t\t  Restauration ...");
    printf("\n\t\t\t\t  ****************");
    break ;
case 0 : /// pour trouver esq l'utilisateur existe ou pas .

    printf("\n\n\n\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n") ;
    printf(" 1- Recherche par nom .\n");
    printf(" 2- Recherche par ville .\n");
    printf(" 3- Recherche par centre d'interet .\n");
    int choix1 = 0 ;
    printf("\n\n\t\t Votre choix  : ");
    scanf("%d",&choix1);
    switch (choix1)
    {
        case 1 :  recherche_par_nom() ; /// pour trouver esq l'utilisateur existe ou pas en utilisant son nom .
            break ;
        case 2 :  recherche_par_ville() ; /// pour trouver esq l'utilisateur existe ou pas en utilisant sa ville .
            break ;
        case 3 :  recherche_par_octet() ; /// pour trouver esq l'utilisateur existe ou pas en utilisant son centre d'interet  .
            break ;

    }



    break;


case 1: /// Creation d'un nouveau utilisateur
       printf("\n\n Nom d'utilisateur : ");
       char newname[25] ;
       scanf("%s",newname);
       utilisateur* tete ;
       tete = detect_lettre(newname);/// Detecter en quelle case[26 cases = 26 lettres] il faut stocker le nom d'utilisateur

       int cpt0= 1   ;
       static utilisateur* last_user = NULL; /// [static] pour que la variable sea creer juste pr la 1ere fois .
       utilisateur* pointeur0 ;
       pointeur0 = tete ;
       while (suivant(pointeur0 )!= NULL)
       {
           cpt0 ++ ;
           pointeur0 =suivant(pointeur0) ;

       }

       if (cpt0 == 1  )
       {

           last_user = tete ;
           last_user = creation_utilisateur(last_user,newname) ;
       }
     else { last_user = creation_utilisateur(pointeur0,newname) ; }




    break;



case 2:
   printf("\n\n Nom d'utilisateur : ");
    char newname1[25] ;
    scanf("%s",newname1);
    suppression(newname1);

  break;




case 3: /// c est pour modifier les information d'un utilisateur


  modification_utilisateur();

  break;




case 4:
  printf("\n\n");
  affichage_utilisateur () ;
  break;


case  5 :
    printf("\n\n");
    suggestion_par_octet();
    break;
case 6 :
    printf("\n\n");
    abonnement_utilisateur () ;
    break ;
case 7 :
    printf("\n\n");
    printf(" Donner le nom de l'utilisateur qui vous souhaitez afficher sa liste de followings : ");
    char name7[25] ;
    scanf("%s",name7);
    aff_liste_followings(name7);
    break;

case 8 :
    Sauvgarde() ;
    break;

case 99:
  printf(" ");

  break;
default:
  printf("\n\n\t\tVous avez entrer un faux choix ... \n\n");
  printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n" ) ;
  break;
}


        ///End.

   } while (choix!= 99) ;

    printf("\n\n ");
    printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n" ) ;


    free_DATABAse () ;




    return 0;
}
