
/*
 **************************************
 *  impl�mentation du module maillon  *
*           (Mod�le des LLC)          *
 **************************************
*/


#include <stdio.h>
#include <stdlib.h>	/// pour malloc et free
#include <string.h>
#include <ctype.h>
#include "utilisateur.h"


void creation_DataB ()
{

  /// Initialisation de la base de donnees
     /// Begin
    for (int i=0 ; i<26 ;i++)
        {
            tableau[i] = malloc( sizeof(utilisateur) );
        }

    printf("Initialisation de base de donnees : \n");
    printf("*********************************\n\n");
    int A = 65 ;
    for (int i=0 ; i<26 ;i++)
        {
            tableau[i]->nom[0] = A ;
            A++ ;
            tableau[i]->nom[1] = '\0' ;
            tableau[i]->suivant = NULL;
            tableau[i]->precedente = NULL ;

             for (int j = 0 ; j < 100 ; j++)
                {
                    tableau[i]->followings[j]= malloc( sizeof(utilisateur) ) ;
                     tableau[i]->followings[j]= NULL ;
                }
        }


    /// End .

}
/*
 **************************************
 *          Machine abstraire         *
 *                                    *
 **************************************
*/
////////////////////////////////////////////////////////////////////////

void allouer( utilisateur** p )
/// c-a-d struct maillon **p
{
    *p = malloc( sizeof(utilisateur) );
}
///////////////////////////////////////////////////////////////////////

void liberer (utilisateur** p )
{
    free( *p );
}

//////////////////////////////////////////////////////////////////////

void aff_nom(utilisateur* p , char* name)
{
    strcpy(p->nom,name) ;
}
///////////////////////////////////////////////////////////////////////

void aff_ville(utilisateur* p , char* village)
{
    strcpy(p->ville,village);

}
///////////////////////////////////////////////////////////////////////
void aff_adr (utilisateur* p , utilisateur* q)
{
    p->suivant = q ;
}
///////////////////////////////////////////////////////////////////////

utilisateur* suivant (utilisateur* p )
{
            return p->suivant ;
}
//////////////////////////////////////////////////////////////////////////////

utilisateur* precedent (utilisateur* p )
{
            return p->precedente ;
}
///////////////////////////////////////////////////////////////////////
/*
 **************************************
 *        Autres Fonctions            *
 *                                    *
 **************************************
*/

utilisateur* detect_lettre ( char* chaine )
{
    int i = -1 ; char charactere ; utilisateur* pointeur ;
    charactere =  toupper(chaine[0]) ; /// pour traduire la lettre en majuscule .
    do
    {
       i++ ;

    } while (charactere != tableau[i]->nom[0] && i < 26 );
    if ( i >= 26){ printf("\n\n     Desole , Mais la lettre entree n'est pas valide...") ;}
    else
    {
        pointeur = tableau[i] ;
    }

            return pointeur ;
}
///////////////////////////////////////////////////////////////////////////////7

utilisateur* creation_utilisateur(utilisateur* dernier_utilisateur ,char* name)
{
    utilisateur* q ;
    allouer(&q);
    aff_nom(q,name);
    printf("\n Nom de Ville  : ");
    scanf("%s",q->ville);
    printf("\n\nCentre d'interet (nombre binaire de 8 chiffres pr ex [11001100]), \n") ;
    printf("\t\t 1. sport, 2. cinema, 3. art, 4. sante, 5. technologie, \n");
    printf("\t\t\t6. DIY, 7.cuisine,8. voyage . \n") ;
    printf("{le bit i est a 1 si le domaine i figure parmi les centres d'interet de la personne, 0 sinon}\n");
    printf("\n\n");
    printf("\t L'octet :  ");
    long interet;
    scanf("%ld",&interet);
    q->octet=interet ;
    aff_adr(dernier_utilisateur,q);
    q->precedente = dernier_utilisateur ;
    aff_adr(q,NULL) ;
    printf("\n                    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n");


            return q ;

}
//////////////////////////////////////////////////////////////////////////////

void suppression (char* nom)
{
    utilisateur *lettre , *p , *q ;
    lettre = detect_lettre(nom);

    while(  ( strcmp(lettre->nom , nom)!= 0 )&& (suivant(lettre)!= NULL) )
        {
                lettre = suivant(lettre);
        }

        if ( ( strcmp(lettre->nom , nom) == 0 ) )
        {
            p = lettre ;
            q = precedent(lettre);
            aff_adr(q, suivant(p));
            if ((suivant(p)!= NULL))
            {
                 p=suivant(p);
                (p->precedente) = q ;

            }
            liberer(&p);
            printf("\n\t\t\t ###L'utilisateur [%s] a ete supprimme ...###\n\n",nom);

        }
        else{( printf("\n\t\t\t ###L'utilisateur [%s] n'existe pas ...###\n\n",nom) ); }



}

//////////////////////////////////////////////////////////////////////

void modification_utilisateur ()
{
    printf("\n\nLe nom de l'utilisateur : ");
    char newname2 [25];
    scanf("%s",newname2);
    utilisateur* first_lettre = detect_lettre(newname2);
    while( (strcmp(first_lettre->nom,newname2) !=0) && suivant(first_lettre )!= NULL)
    {
      first_lettre = suivant(first_lettre) ;
    }

    if ((strcmp(first_lettre->nom,newname2) == 0))
    {
        printf("NOUVELLE nom : ");
        char name[25];
        scanf("%s",name);
        strcpy(first_lettre->nom,name);
        printf("NOUVELLE ville : ");
        char village [100];
        scanf("%s",village);
        strcpy(first_lettre->ville,village);
        printf("\n\nNOUVELLE Centre d'interet (nombre binaire de 8 chiffres pr ex [11001100]), \n") ;
        printf("\t\t 1. sport, 2. cinema, 3. art, 4. sante, 5. technologie, \n");
        printf("\t\t\t6. DIY, 7.cuisine,8. voyage . \n") ;
        printf("{le bit i est a 1 si le domaine i figure parmi les centres d'interet de la personne, 0 sinon}\n");
        printf("\n\n\t L'octet :  ");
        long interet;
        scanf("%ld",&interet);
        first_lettre->octet =interet ;
        printf("\t\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
    }else {(printf("\n\n\t\tVous avez entrer un nom qui n'existe pas ... \n\n"));  printf("\t\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");}


}
///////////////////////////////////////////////////////////////////////////////////

void affichage_utilisateur ()
{
    printf("donner le nom d'utilisateur que vous souhaiter afficher ses informations : ");
    char nom[25];
    scanf("%s",nom);
    utilisateur* first = detect_lettre(nom);
    while( (strcmp(first->nom,nom) !=0) && suivant(first )!= NULL)
    {
            first = suivant(first) ;
    }

    if (strcmp(first->nom,nom) ==0)
    {

        printf("\n\n");
        printf("\t\t\t Le nom : %s \n",first->nom);
        printf("\t\t\t ????????");
        printf("\n\n");
        printf("\t\t\t La ville : %s \n",first->ville);
        printf("\t\t\t ?????????? ");
        printf("\n\n");
        printf("\t\t\t Le centre d'interet : %ld \n",first->octet);
        printf("\t\t\t ????????????????????? \n\n");
        printf("\t\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");

    } else { printf("\n\t\t L'utilisateur  n'existe pas ... \n\n"); printf("\t\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");}


}
///////////////////////////////////////////////////////////////////////////////

void recherche_par_nom ()

{
    char name [25] ;
    printf("\n\n\t\t\t La recherche \n");
    printf("\t\t\t !!!!!!!!!!!!\n") ;
    printf(" Le nom recherche : ");
    scanf("%s",name);
    utilisateur *third , *fourth;
    third = detect_lettre(name);
    int cpt0 = 0 ;
    printf("\t Resultat de recherche textuelle : ");

    while (third != NULL)
    {
        if (strcmp(third->nom,name) == 0)
        {
            cpt0 ++ ;
            printf("\t %s \t ||",name);


        }
        third = suivant(third);
    }

    if (cpt0 == 0 ){printf("\t Pas de resultat ...\n\n");}
    else{printf("\t \n");}


   fourth = detect_lettre(name);
    int cpt1 = 0 ;
    printf("\t Resultat de recherche generale (suggestion) : ");
    char *suiteChaine = NULL;


   while (fourth != NULL)
    {

        suiteChaine = strstr(fourth->nom , name);
        if ((suiteChaine != NULL) )
        {
            cpt1 ++ ;
            printf("\t %s \t ||",fourth->nom);

        }
       fourth = suivant(fourth);

    }
    if (cpt1 == 0 ){printf("\t Pas de resultat ...\n\n");}
    else{printf("\t \n");}

    printf("\n\t\t\t        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");

}

///////////////////////////////////////////////////////////////////////////////

void recherche_par_ville ()

{
    char village [100] ;
    printf("\n\n\t\t\t La recherche \n");
    printf("\t\t\t !!!!!!!!!!!!\n") ;
    printf(" La ville recherchee : ");
    scanf("%s",village);
    int cpt00 = 0 ,cpt11 = 0 ;
    utilisateur* single ;
    printf("\t Resultat de recherche textuelle : ");

    for (int i = 0 ; i < 26 ; i ++ )
    {
        single = tableau[i] ;
        while (single != NULL)
        {
            if ( strcmp(single->ville,village) == 0  )
            {
                cpt00 ++ ;
                printf("\t %s \t ||",single->nom);


            }
            single = suivant(single);
        }
    }
    if (cpt00 == 0 ){printf("\t Pas de resultat ...\n\n");}
    else{printf("\t \n");}

    printf("\t Resultat de recherche generale (suggestion) : ");
    char* suite = NULL  ;

    for (int i = 0 ; i < 26 ; i ++ )
    {
        single = tableau[i] ;
        while (single != NULL)
        {
            suite = strstr(single->ville,village);
            if ( suite != NULL  )
            {
                cpt11 ++ ;
                printf("\t %s \t ||",single->nom);


            }
            single = suivant(single);
        }
    }
    if (cpt11 == 0 ){printf("\t Pas de resultat ...\n\n");}
    else{printf("\t \n");}


    printf("\n\t\t\t        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
}

////////////////////////////////////////////////////////////////////////////////

void recherche_par_octet()
{
    int nombre ;
    printf("\n\n\t\t\t La recherche \n");
    printf("\t\t\t !!!!!!!!!!!!\n") ;
    printf(" Le centre d'interet recherchee : ");
    scanf("%d",&nombre );
    utilisateur *single;
    int i , cpt00 = 0 ;
    printf("\t Resultat de recherche textuelle : ");

    for (i = 0 ; i < 26 ; i ++ )
    {
        single = tableau[i] ;
        while (single != NULL)
        {
            if (single->octet == nombre )
            {
                cpt00 ++ ;
                printf("\t %s \t ||",single->nom);


            }
            single = suivant(single);
        }
    }
    if (cpt00 == 0 ){printf("\t Pas de resultat ...\n\n");}
    else{printf("\t \n");}

        printf("\n\t\t\t        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");


}
////////////////////////////////////////////////////////////////////////////////

void suggestion_par_nom (char* suggestionName)
{
    utilisateur *fifth ;
    fifth = detect_lettre(suggestionName);


    fifth = detect_lettre(suggestionName);
    int cpt1 = 0 ;
    printf("\t Resultat de suggestion generale (Pour les abonner) : ");
    char *suiteChaine = NULL;


   while (fifth != NULL)
    {

        suiteChaine = strstr(fifth->nom , suggestionName);
        if ((suiteChaine != NULL) )
        {
            cpt1 ++ ;
            printf("\t %s \t ||",fifth->nom);

        }
       fifth = suivant(fifth);

    }
    if (cpt1 == 0 ){printf("\t Pas de suggestion ...\n\n");}
    else{printf("\t \n");}

    printf("\n\t\t\t        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");

}
////////////////////////////////////////////////////////////////////////////////

void abonnement_utilisateur () ///  pour abonner un nouveaau utilisateur .

{

    printf("\n\n\t\t\t********************** Services Abonnemet **********************\n\n") ;
    printf(" Votre nom d'utilisateur : ");
    char username[25];
    scanf("%s",username);
    printf("\nEntrez le nom d'utilisateur que vous souhaitez abonner :" );
    char sggestName[25];
    scanf("%s",sggestName);
    suggestion_par_nom(sggestName);
    printf("\n Validez le nom d'utilisateur que vous souhaitez abonner : ");
    scanf("%s",sggestName);

    /// trouver la position de l'utilisateur qui veut abonner l'autre .

    utilisateur* tete = detect_lettre(username); utilisateur* abonne ;
    int trouve = 0 ;

    while (tete != NULL && trouve == 0 )
    {
        if (strcmp(tete->nom,username)== 0 )
            {
                abonne = tete ;
                trouve = 1 ;
            }
        tete = suivant(tete);
    }

    /// trouver la position de l'utilisateur qui sera ete abonne par user .


    tete = detect_lettre(sggestName); utilisateur* surabonne ;
    trouve = 0 ;

    while (tete != NULL && trouve == 0 )
    {
        if (strcmp(tete->nom,sggestName)== 0 )
            {
                surabonne = tete ;
                trouve = 1 ;
            }
        tete = suivant(tete);
    }



    /// Ajouter l'utilisateur suggere a la liste d'abonnement .
    int i = 0 ;
    while (abonne ->followings[i]!= NULL) {i++ ;}
    abonne->followings[i]= surabonne;
    printf("\n\n\t\t **** Abonnement avec succes **** \n\n") ;
    printf("\t\t\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");





}

////////////////////////////////////////////////////////////////////////////////

int Detect_sim(int a,int b,int i)///une fonction qui fait la comparaison entre deux nombres entr�s
{
int k=0,cpt=0 , v ;///et fait retournner "10" si les chiffres communs sont �gales � i.
int s,t;
do {
s=a % 10;
t=b % 10;
if ( s==t){
        k=k+1 ;///� chaque fois qu'il y a un chiffre commun on incr�mente le k.
}
 a=a/10;
 b=b/10;
 cpt=cpt+1;
}while(cpt!=8);
if(k==i){v=10;}///si k=i alors la fonction retourne 10.
return v;
}

////////////////////////////////////////////////////////////////////////////////////

void suggestion_par_octet ()
{
    printf("\n\n Entrer le nom  : ");
    char name[25] ;
    scanf("%s",name);
    printf("\n\n");
    printf("VOTRE LISTE DE SUGGESTION :\n\n");
    ///on trouve le maillon contenant le nom entr�.
    utilisateur *single ,*q ;
    int trouve= 0 ;
    for (int i =0 ; i <26 ; i++)
    {
        single = tableau[i] ;
        single= suivant(single);
        while ((single!=NULL)&&(trouve == 0 ))
        {
           if ( strcmp(single->nom,name)==0);
           {
               q = single ;
               trouve= 1 ;
               i= 26 ;
           }
           single=suivant(single);
        }
    }

///on cherche (en bas) les utilisateurs qui ont des octets simmilaires .
    utilisateur *p;
    int cpt=0,trouv=0; int i ; int s=8;///s commence avec 8 car les octets qui sont identiques sont plus propri�taire
    while((s>4)&&(cpt<5)){///des autres et apr�s avoir parcourus toute la liste on d�cr�mente s jusqu'a ce qu'on arrive � s=5

        for (i = 0 ; i < 26 ; i ++ )/// ou le nombre de suggestions (cpt=5).
        {
            p= tableau[i] ;
            p=suivant(p);
            while((p != NULL)&&(trouv==0))
                {
                    if (strcmp(p->nom,q->nom)!=0)
                        {
                                if (Detect_sim(p->octet,q->octet,s)==10)
                                {
                                        cpt++;
                                        printf("%s\n",p->nom);
                                }
                        }
                    if (cpt>=5)
                    {
                        trouv=1;
                        i=26;
                    }
                 p = suivant(p);


                }
        }
s--;
}
if (cpt==0)///s'il le nombre de suggestion est nulle on �crit "aucune suggestion trouv�e".
    {
        printf("\n\n");
        printf("\t\t\t ******************** Aucune suggestion trouvee ... ******************** ");
        }
        return  ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_liste_followings (char* username)
{
    utilisateur* tete = detect_lettre(username);
    utilisateur *user,*aidant ;
    int trouve = 0 ;

    while (tete != NULL && trouve == 0 )
    {
        if (strcmp(tete->nom,username)== 0 )
            {
                user = tete ;
                trouve = 1 ;
            }
        tete = suivant(tete);
    }

    if (trouve == 0){printf("\n\n\t\t\t  ****** L'utilisateur n'existe pas ***** ") ; }
    else
    {
        printf("\n\n\t\t\t  ****** La liste de followings  ***** \n\n") ;
        int i = 0 ;
        while (user->followings[i] != NULL)
            {
                aidant= user->followings[i] ;
                printf("\t %s  || ",aidant->nom);
                i++ ;
            }
        if (i == 0 ){printf("\t\t  ### Pas de followings... ###");}

    }
    printf("\n\n\t\t\t\t /////////////////////////////  \n\n");
}

///////////////////////////////////////////////////////////////////////////////////////

void free_DATABAse ()
{
        utilisateur *p , *q ;
        for (int i=0 ; i<26 ;i++)
        {
            p= tableau[i];
            while ( p != NULL )
            {
                q = p ;
                p = suivant(p);
                free(q);

            }

        }
}


///////////////////////////////////////////////////////////////////////

 void Sauvgarde ()
{
    FILE *fichier = NULL ;
    fichier = fopen("sauvgarde_restauration.txt", "w");
    if (fichier == NULL)
        {
            printf("Impossible d'ouvrir le fichie [ sauvgarde/restauration.txt ]");
            exit(0);
        }
    utilisateur *user ;

      printf("\n\n\t\t\t  Sauvgarde ...");
      printf("\n\t\t\t *************** \n\n");
    for (int i=0 ; i< 26 ; i++)
    {
      user = tableau[i] ;
      user=suivant(user);

      while(user != NULL)
      {
          int j = 0 ;
          fprintf(fichier,"%s %s %ld %p %p ",user->nom,user->ville,user->octet,user->precedente,user->suivant) ;

          while ((user->followings[j])!= NULL)
          {
          fprintf(fichier,"%s ",user->followings[j]->nom);

          j++;
          }
          fprintf(fichier,"\n");

          user = suivant(user);
      }
      fprintf(fichier,"\n\n");

    }
    fclose(fichier) ;


}


///////////////////////////////////////////////////////////////////////////////

void restauration_fichier ()
{

        FILE *fichier = NULL ;
    fichier = fopen("sauvgarde_restauration.txt", "w");
    if (fichier == NULL)
        {
            printf("Impossible d'ouvrir le fichie [ sauvgarde/restauration.txt ]");
            exit(0);
        }
    utilisateur *user ;

    for (int i=0 ; i< 26 ; i++)
    {
      user = tableau[i] ;
      user=suivant(user);

      while(user != NULL)
      {
          int j = 0 ;
          fscanf(fichier,"%s %s %ld %p %p ",user->nom,user->ville,&(user->octet),&(user->precedente),&(user->suivant)) ;

          while ((user->followings[j])!= NULL)
          {
          fscanf(fichier,"%s ",user->followings[j]->nom);

          j++;
          }
          fscanf(fichier,"\n");

          user = suivant(user);
      }
      fscanf(fichier,"\n\n");

    }
    fclose(fichier) ;


}
/////////////////////////////////////////////////////////////////////////////////////////////

void suggestion_par_followers(){
printf("ENTREZ LE NOM :");
char name[50];
scanf("%s",name);///on cherche le maillon contenant le nom entr�.
utilisateur* tete = detect_lettre(name); utilisateur* user ;
    int trouve = 0 ;

    while (tete != NULL && trouve == 0 )
    {
        if (strcmp(tete->nom,name)== 0 )
            {
                user = tete ;///user contient le maillon recherch�.
                trouve = 1 ;
            }
        tete = suivant(tete);
    }
    printf("\n\n");
    printf("VOTRE LISTE DE SUGGESTION :\n\n");
    int k=0,tr=0,sugg=0,s=0,i=0,j=0,table[100],mem;
    while (user->followings[i]!=NULL){///on parcourt la liste des followers des followers de user (la r�p�tition n'est pas une faute
        trouve=i;///pour sauvegarder la valeur de i car i va varier apr�s.
    tete=user->followings[i];
        while(tete->followings[j]!=NULL)
            {
                i++;
                while (user->followings[i]!=NULL){
                if (strcmp(tete->followings[j],name)!=0){///pour ne pas sugg�rer le nom lui m�me.
                    if (strcmp(tete->followings[j],(user->followings[i])->followings[k])==0){
                        sugg++;///on trouvons un follower commun on incr�mente sugg.

                        mem=i;}
                        k++;
                        if((user->followings[i])->followings[k]==NULL){
                        i++;}

                }
               }

                i=trouve;
                k=0;
                 if (sugg!=0){table[s]=mem*100+j*10+sugg;///on enregistre la valeur de sugg dans un tableau .avec le i et le j.
                  s++;}///et apr�s on aura la fonction tableau_followers qui va trouver les 5 plus grandes valeurs de sugg
                 ///et va retourner le nom comme suggestion (comme on a aussi le i et le j).

                 sugg=0;///on r�initialise sugg.
                 mem=0;
                 j++;

        }
i=trouve+1;
j=0;
    }
 tableau_followers( &table, s, nombre_followers(user), user)   ;///s repr�sente la taille du tableau.


}
//////////////////////////////////////////////////////////////////////////////


void tableau_followers(int* t,int tai,int nb_followers,utilisateur* user){
int c,o,cpt=0;
while ((cpt<5)&&(nb_followers>0)){
for(int i=0;i<tai;i++){
c=(*(t+i)%10);
if(c==nb_followers){
        o=(*(t+i)/10)%10;
    printf("%s\n",(user->followings[*(t+i)/100])->followings[o]);
    cpt++;
}

}
 nb_followers --;

}
if(cpt==0){printf("           ~~~~~~~~~~~~~~~~~~~~~~~~  AUCUNE SUGGETION TROUVEE  ~~~~~~~~~~~~~~~~~~~~~~~~");
printf("/n/n");}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int nombre_followers(utilisateur* user){///une fonction qui donne le nombre de followers d'un utilisateur.
 int i = 0 ;
    while (user ->followings[i]!= NULL) {i++ ;}

return i;


}
//////////////////////////////////////////////////////////////////////////////////////////
void restauration_base(){
    int cpt=10;
for(int i=0;i<10;i++){
    i++;
    cpt--;

}
printf("\n\n");
printf("*************************Restauration successive*******************************\n");

///////////////////////////////////////////////////////////////////////////



}

















