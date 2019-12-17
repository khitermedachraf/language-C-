#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000 // Tableau de taille 1000
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;

    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    fichier = fopen("test.txt", "r");
    int score[3] = {0}; // Tableau des 3 meilleurs scores
    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
        printf("***Les meilleurs scores sont : %d, %d et %d***", score[0], score[1], score[2]);
        fclose(fichier);
    }
    ///////////////////////////////////////////////////////////
    rename("test.txt", "test_renomme.txt");


    return 0;
}
