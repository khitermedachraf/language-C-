#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void viderBuffer() ;
int lire(char *chaine, int longueur) ;
long lireLong() ;
double lireDouble();

char lireChar() ;


///###################################################################
int main(int argc, char *argv[])
{
    char nom[10];

    printf("Quel est votre nom ? ");
    lire(nom, 10);
    printf("Ah ! Vous vous appelez donc %s !woooow\n\n", nom);

    lire(nom, 10);
    printf("Ah ! Vous vous appelez donc %s !woooow\n\n", nom);

    long age = 0;

    printf("Quel est votre age ? ");
    age = lireLong();
    printf("Ah ! Vous avez donc %ld ans !\n\n", age);

      double poids = 0;

    printf("Combien pesez-vous ? ? ");
    poids = lireDouble();
    printf("Ah !  Vous pesez donc  %f Kg !\n\n", poids);

        char charect ;
    printf("Ecrez qlq  choses ? ? ");
    charect= lireChar();
    printf("Ah !  la 1 ere lettre ecrite est  %c  !\n\n", charect);





    return 0;
}
///###########################################################################


void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}
////////////////////////////////////////////////////////////////////////////////////

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire

    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////

double lireDouble()
{
    char *positionVirgule = NULL;
    char nombreTexte[100] = {0}; // 100 cases devraient suffire

    if (lire(nombreTexte, 100))
    {
        positionVirgule = strchr(nombreTexte,',');
        if (positionVirgule != NULL) { *positionVirgule = '.';}

        // Si lecture du texte ok, convertir le nombre en double et le retourner
        return strtod(nombreTexte, NULL);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

char lireChar()
{
    char Texte[10] = {0}; // 100 cases devraient suffire

    if (lire(Texte, 10))
    {
        // Si lecture du texte ok, renvoyer la 1 ere lettre
        return Texte[0];
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}
