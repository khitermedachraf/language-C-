#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lire(char *chaine, int longueur) ;
void viderBuffer() ;
void majuscule(char *chaine);
int main()
{
    char a[2] ;
    char nom[9];
    char prenom[9];
    printf("Salut , Je suis  un simple programme creer par monsieur Achraf. ");
    printf("\n\n\t\t\t\t Alors avant hier c'etait le 18 Mars 2020.");
    printf("\n\n\t\t\t\t\t\t Umm ... je connais quelqu'un qui est ne dans ce jours la ;) ");
    printf("\n\n\t\t\t\t\t\t\t\t Mais c'est qui ? ");
    printf("\n\n\t\t\t\t\t\t\t\tC'est ");
    lire(nom,9);
    printf("\n\t\t\t\t\t\t\t\t");
    lire(prenom,9);
    majuscule(prenom);
    printf("\n\n\n\t Ahh C'est Leatitia ,Bien-sur je la connais , C'est ta deuxieme moitie Achraf ... ");
    lire(a,2);
    printf("\n\n\t%s  %s est ne le 18 Mars 2003 . elle a maintenant : 17 ans",nom,prenom);
    lire(a,2);
    printf("\n\n\t Umm %s , Comme Achraf est un peu timide , il m'a dit un secret (qu'il t'aime bien %s ;)",nom,nom);
    lire(a,2);
    printf("\n\n\t\t et maintenant il veut te dire \n\n\t\t\t\t***{ Joyeux anniversaire %s %s .A tes 100 ans nchllh } ***",nom,prenom);
    lire(a,2);
    printf("\n\n\n\t\t\t\t\t Bonne nuit THE QUEEN . %s %s",nom,prenom);


    printf("\n\n\n\n\n\n");
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

void majuscule(char *chaine)
{
    int i = 0;
    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        chaine[i] = toupper(chaine[i]);
    }
}
