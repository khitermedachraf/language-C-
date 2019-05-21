#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h" //on inclus notre tableaux.h qui contient les prototype

int main(int argc, char *argv[])
{
    int tableau[4] = {5, 15, 3, 36}; //on initialise notre tableau
    int tableauC[4] = {0}; //on initialise notre tableauCopie pour l'exercice 3
    sommeTableau(tableau, 4);  // on fait apelle au fonction
    moyenneTableau(tableau, 4);
    copie(tableau, tableauC, 4);
    ordonnerTableau(tableau, 4);
    maximumTableau(tableau, 4, 14);
 
    return 0;
}
