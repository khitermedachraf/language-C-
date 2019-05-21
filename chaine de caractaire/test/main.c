#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Je mets le prototype en haut. Comme c'est un tout
petit programme je ne le mets pas dans un .h, mais
en temps normal (dans un vrai programme), j'aurais placé
le prototype dans un fichier .h bien entendu */


void decoupeMinutes(int* h, int* m);

int main(int argc, char *argv[])
{
    int heures = 0, minutes = 90;
    int *h ,*m ;
    h= &heures ; m= &minutes ;

    /* On a une variable minutes qui vaut 90.
    Après appel de la fonction, je veux que ma variable
    "heures" vaille 1 et que ma variable "minutes" vaille 30 */

    decoupeMinutes(h, m);

    printf("%d heures et %d minutes", heures, minutes);

    char letter ='?';
    printf("\n le nombre ASCII est : %d \n    c vrai . ",letter);
    printf("\n\n");
            char* chaine= "I will love Hadjer "; // Tableau de 6 char pour stocker une chaine

printf("%s",chaine) ;

printf("\n\n");

char prenom[100];
char phrase[100];

    printf("Comment t'appelles-tu Mon BEBE ;) ? ");
    scanf("%s", prenom);
    printf("Salut %s, je suis heureux de te rencontrer !", prenom);
    printf("\n\n");
    printf(" Donnez A Hadjer une tres belle phrase .. pour qu'elle complete ? ");
    scanf("%s",phrase);
    printf("\n\n") ;

    int longueurChaine = 0;

    // On récupère la longueur de la chaîne dans longueurChaine
    longueurChaine = strlen(phrase);

    // On affiche la longueur de la chaîne
    printf("La belle phrase {%s} fait (%d) caracteres de long", phrase, longueurChaine);
    printf("\n\n") ;

     /* On crée une chaîne "chaine" qui contient un peu de texte
    et une copie (vide) de taille 100 pour être sûr d'avoir la place
    pour la copie */

    char chaine1[] = "Texte pour test", copie[100] = {0};

    strcpy(copie, chaine1); // On copie "chaine" dans "copie"

    // Si tout s'est bien passé, la copie devrait être identique à chaine1
    printf("chaine1 vaut : %s\n", chaine1);
    printf("copie vaut : %s\n", copie);
    printf("\n\n");

     /* On crée 2 chaînes. chaine1 doit être assez grande pour accueillir
    le contenu de chaine2 en plus, sinon risque de plantage */
    char chaine11[100] = "Salut Mon ami ", chaine2[] = "Ingenieur Achraf .";

    strcat(chaine11, chaine2); // On concatène chaine2 dans chaine1

    // Si tout s'est bien passé, chaine1 vaut "Salut Mateo21"
    printf("chaine1 vaut : %s\n", chaine11);
    // chaine2 n'a pas changé :
    printf("chaine2 vaut toujours : %s\n", chaine2);
    printf("\n\n");

      char chaine111[] = "Texte de test", chaine22[] = "Texte de test";

    if (strcmp(chaine111, chaine22) == 0) // Si chaînes identiques
    {
        printf("Les chaines sont identiques\n");
    }
    else
    {
        printf("Les chaines sont differentes\n");
    }


    printf("\n\n");
    char chainne[] = "Texte de test", *suiteChaine = NULL;

    suiteChaine = strchr(chainne, 'd');
    if (suiteChaine != NULL) // Si on a trouvé quelque chose
    {
        printf("Voici la fin de la chaine a partir du premier d : %s\n\n", suiteChaine);
    }
    printf("\n");
    if (strpbrk("Texte de test", "xds") != NULL)
    {
        printf("Voici la fin de la chaine a partir du premier des caracteres trouves : %s", strpbrk("Texte de test", "xds"));
    }
    printf("\n\n");
      char *suiteChainne;

    // On cherche la première occurrence de "test" dans "Texte de test" :
    suiteChainne = strstr("Texte de test", "de");
    if (suiteChaine != NULL)
    {
        printf("Premiere occurrence de (de ) dans Texte de test : %s\n", suiteChainne);
    }
    printf("\n\n");
     char chainnne[100];
    int age = 18;

    // On écrit "Tu as 18 ans" dans chaine
    sprintf(chainnne, "Tu as %d ans !", age);

    // On affiche chaine pour vérifier qu'elle contient bien cela :
    printf("%s", chainnne);

    printf("\n\n");
    printf("Erreur a la ligne %d du fichier %s\n", __LINE__, __FILE__);
    printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
    printf("\n\n");
    #define RACONTER_SA_VIE()   printf("Coucou, je m'appelle Brice\n"); \
                                printf("J'habite a Nice\n"); \
                                printf("J'aime la glisse\n");
    RACONTER_SA_VIE();

    return 0;
}

void decoupeMinutes(int* h, int* m)
{
    *h = *m / 60;  // 90 / 60 = 1
    *m = *m % 60; // 90 % 60 = 30
}
