/*
 *  ALSDD 2019
 *  Implémentation du module "Tableau Dynamique Ordonné" TDO
 *
*/


#include <stdlib.h>	// pour malloc(), free() ...
#include <stdio.h>	// E/S std: printf() ...
#include <time.h>	// pour la fonction time()

#include "tdo.h"


// Espace (en nombre d'éléments) à rajouter à chaque augmentation de la taille du tableau
#define DELTA 5




// Fonction de comparaison utilisée par 'qsort'
// retourne -1 si a<b, 0 si a==b et +1 si a>b
int intcmp(const void *a, const void *b)
{
    if ( *(int *)a < *(int *)b )
	return -1;
    if ( *(int *)a == *(int *)b )
	return 0;
    return 1;
}  // fin intcmp


// Alloue un tableau dynamique ordonné de taille 'tailleMax' entiers
TDO *AllouerTab( int tailleMax )
{
   TDO *t;

   // allocation de la structure struct TabOrd ...
   t = malloc( sizeof(struct TabOrd) );
   t->NbElem = 0;
   t->Taille = tailleMax;
   // allocation de la zone pour les éléments du tableau ...
   t->Contenu = malloc(  tailleMax * sizeof(int) );

   return t;
} // fin AllouerTab()


// Remplir le TDO t avec des valeurs aléatoires pouvant être identiques, 
// A la fin le tableau est trier avec 'qsort'
int Remplir( int n, TDO *t )
{
   int i;

   if ( n > t->Taille ) {
	// si la taille actuelle ne suffit pas, on réalloue une zone plus grande ...
	t->Contenu = realloc( t->Contenu, n * sizeof(int) );
	if ( t->Contenu == NULL ) {
		t->Taille = 0;
		return 0;
	}
	t->Taille = n;
   }

   // initialiser le générateur de nombre aléatoire ...
   srand( time(NULL) );  		// ou: srand( (unsigned int)time((time_t *)NULL) )

   // Générer n valeurs aléatoires dans le tableau ...
   for (i=0; i<n; i++ ) 
	t->Contenu[i] = 1 + (int) ( 2.0 * n * rand() / (RAND_MAX+1.0) );

   t->NbElem = n;

   // Tri du contenu du tableau ...
   qsort(t->Contenu, n, sizeof(int), intcmp);

   return n;

} // fin Remplir()


// pour libérer un TDO déjà alloué
void LibererTab( TDO *t )
{
   free( t->Contenu );
   free( t );
} // fin LibererTab()


// recherche dichotomique de v dans le TDO t. Retourne l'indice de v et trouv
int Rech( int v, TDO *t, int *trouv )
{
   int bi, bs, m;
   bi = 0;  bs = t->NbElem - 1;  *trouv = 0;
   while ( bi <= bs && !(*trouv) )
   {
      m = (bi + bs) / 2;
      if ( v == t->Contenu[m] ) *trouv = 1;
       else
      	   if ( v < t->Contenu[m] )  bs = m-1;
	   else bi = m+1;
   }
   if (*trouv ) 
	return m;	// l'indice de v, si elle existe
   else 
	return bi;	// l'indice où devrait être insérée v, si elle n'existe pas

} // fin Rech()


// insère v par décalages dans t de manière à maintenir l'ordre. 
// retourne 1 en cas d'insertion avec succès 
// 	 et 0 en cas d'échec (v existe déjà ou pb d'allocation)
int Ins( int v, TDO *t )
{
   int trouv;
   int i, j;

   if ( t->NbElem == t->Taille ) {
	// s'il n'y a pas de place, allouer une zone plus grande de DELTA éléments ...
   	t->Contenu = realloc( t->Contenu, (t->Taille + DELTA) * sizeof(int) );
	if ( t->Contenu == NULL ) 
		// Pb d'allocation mémoire ...
		return 0;

	t->Taille = t->Taille + DELTA;
   }
   
   i = Rech( v, t, &trouv );
   if ( !trouv ) {
	// insertion de v à la position i (par décalages) ...
	j = t->NbElem;
	while ( j > i )  {
		t->Contenu[j] = t->Contenu[j-1];
		j--;
	}
	t->Contenu[i] = v;
	t->NbElem++;
	return 1;
   }
   else
	return 0;

} // fin Ins()


// affiche les éléments du TDO t
void Affich( TDO *t )
{
   int i;
   printf("Taille = %d \nNbElem = %d\n", t->Taille, t->NbElem );
   printf("Contenu : ");
   for (i = 0; i < t->NbElem; i++)
	printf("%d|", t->Contenu[i]);
   for (i = t->NbElem; i < t->Taille; i++)
	printf("  |");

   printf("\n");

} // fin Affich()



