#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r+");

    if (fichier != NULL)
    {
        /// On peut lire et écrire dans le fichier
        fputc('A', fichier); // Écriture du caractère A
        fclose(fichier); /// On ferme le fichier qui a été ouvert
        fichier = fopen("test.txt", "r+");
        fputs("Salut les Zér0s\nComment allez-vous ?", fichier);
        // On demande l'âge
        printf("Quel age avez-vous ? ");
        int age ;
        scanf("%d", &age);

        // On l'écrit dans le fichier
        fprintf(fichier, "Le Monsieur qui utilise le programme, il a %d ans", age);
        fclose(fichier); /// On ferme le fichier qui a été ouvert
    }
    else
    {
        /// On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}
