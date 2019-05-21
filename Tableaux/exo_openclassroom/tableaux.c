
#include "tableaux.h" //on inclus notre tableaux.h qui contient les prototype
 
int sommeTableau(int tableau[], int tailleTableau)
{
    int i = 0, resultat = 0;
 
    printf("Exercice 1-------------------\n");
 
    for(i = 0; i < tailleTableau; i++) // on fait une boucle pour additionner nos cases
    {
        resultat = resultat + tableau[i]; // on additionne ce qui fait : 0 + tableau[0] donc 5 , puis 5 + tableau[1] donc 15 ect..
    }
 
    printf("La somme des cases du tableau est de : %d\n\n", resultat);
    return resultat;
}
 
double moyenneTableau(int tableau[], int tailleTableau)
{
    double resultat = 0, somme = 0;
    int i = 0;
 
    printf("Exercice 2-------------------\n");
 
    for(i = 0; i < tailleTableau; i++)
    {
        somme = somme + tableau[i]; // on calcule la somme comme a l'exo 1
    }
    resultat = somme / tailleTableau; //puis on divise la somme par le nombre de cases donc 4 ici
 
    printf("La moyenne du tableau est de %f\n", resultat);
    printf("-------------------");
    return resultat;
}
 
void copie(int tableau[], int tableauC[], int tailleTableau)
{
    int i = 0, aff = 0;
 
    printf("Exercice 3-------------------\n");
 
    for(i = 0; i < tailleTableau; i++)
    {
        tableauC[i] = tableau[i]; //ici tableauC[i] vaut 0 donc 0 = a tableau[1] qui vaut 5 , donc 5 ect ect..
    }
 
    for(aff = 0; aff < tailleTableau; aff++)
    {
        printf("Le tableau un vaut : %d et le tableau deux vaut %d\n", tableau[aff], tableauC[aff]);
    }
    printf("-------------------");
}
void ordonnerTableau(int tableau[], int tailleTableau)
{//Le tableau est de 5 , 15 , 3, 36 de base
    int i = 0, j = 0, r = 0, aff = 0;
    j = i++;
 
    printf("Exercice 5-------------------\n");
 
    for(i = 0; i < tailleTableau; i++)
    {
        for(j = i; j < tailleTableau; j++)
        {
            if(tableau[i] > tableau[j]) //si le tableau[0] est plus grand que le  tableau[1]
            {
                r = tableau[i]; // la variable r prend la valeur du tableau[i]
                tableau[i] = tableau[j]; // le tableau[i] prend la valeur du tableau[j]
                tableau[j] = r; // et enfin le tableau[j] prend la valeur de r (donc du tableau[i] ce qui a permis d'échanger le "place"
            } // et ainsi de suite la boucle fait son jobs
        }
    }
 
    for(aff = 0; aff < tailleTableau; aff++)
    {
        printf("Le tableau vaut maintenant : %d\n", tableau[aff]);
    }
    printf("-------------------");
 
}
void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
    int i = 0, aff = 0;
 
    printf("Exercice 4-------------------\n");
 
    for(i = 0; i < tailleTableau; i++)
    {
        if(tableau[i] > valeurMax) //ici si le tableau[i] est plus grand que la valeurMax
            tableau[i] = 0; // le tableau[i] prend la valeur 0
    }
 
    for(aff = 0; aff < tailleTableau; aff++)
    {
        printf("Les valeurs des cases sont maintenant a : %d\n\n", tableau[aff]);
    }
    printf("-------------------");
}
