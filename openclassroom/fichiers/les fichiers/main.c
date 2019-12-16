#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r+");

    if (fichier != NULL)
    {
        /// On peut lire et �crire dans le fichier
        fputc('A', fichier); // �criture du caract�re A
        fclose(fichier); /// On ferme le fichier qui a �t� ouvert
        fichier = fopen("test.txt", "r+");
        fputs("Salut les Z�r0s\nComment allez-vous ?", fichier);
        // On demande l'�ge
        printf("Quel age avez-vous ? ");
        int age ;
        scanf("%d", &age);

        // On l'�crit dans le fichier
        fprintf(fichier, "Le Monsieur qui utilise le programme, il a %d ans", age);
        fclose(fichier); /// On ferme le fichier qui a �t� ouvert
    }
    else
    {
        /// On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}
