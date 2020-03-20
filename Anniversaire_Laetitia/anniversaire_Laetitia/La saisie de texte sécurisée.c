#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Penser à inclure string.h pour strchr()

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

///////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////////////////////////////////


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

///////////////////////////////////////////////////////////////////////////////


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

