/*
 *	Mesure de performances des algo de tri
 *	Chap Complexité / ALSDD / 1CPI / ESI / 2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  	// pour time(...) et time_t
#include <sys/time.h> 	// pour gettimeofday(...) et struct timeval

/* Déclarations des principales fonctions ... */
void init_tab(int n, int indic);		// initialise le tableau avec n nombres 
						// aléatoires, croissants ou décroissants (selon indic)
void affich_tab(int n);				// affiche le contenu du tableau 
int verif(int n);				// vérifie si le tableau est ordonné ou non
int intcmp(const void *a, const void *b);	// fonction de comparaison pour qsort
void tri_ins(int n);				// implémentation du tri par insertion récursif
void tri_ins_it(int n);				// implémentation du tri par insertion itératif
void tri_select( int n );			// implémentation du tri par sélection
void tri_bulles( int n );			// implémentation du tri à bulles
void tri_fus(int a, int b);			// implémentation du tri par fusion
void tri_rapide(int a, int b);			// implémentation du tri rapide (tri de Hoare)

/* Déclaration des variables globales ... */
int *T;		// Le tableau à trier
int *tmp;	// Tableau temporaire utilise dans tri_fus



/***************************************************
 * Programme principal : main                      *
 ***************************************************/

int main( void )
{
   char *algo[] = {"bulles", "insertion_rec", "insertion", "selection", "fusion", "rapide", "qsort" };
   int i; 
   int n;		// Nombre d'éléments à trier ( = taille du tableau) 
   int methode;	  	// numéro de l'algo de tri à utiliser
   int indic = 0; 	// indicateur de l'ordre des valeurs en entrées. Utilisée dans init_tab
		   	// (0:aléatoire, 1:ordre croissant 2:ordre décroissant)
   long t; 		// pour le calcul du temps d'exécution (microsecondes)
   struct timeval tv1, tv2; // pour récupérer avec 'gettimeofday(...)' 
			    // les temps de début et de fin de traitement

   /* choix de l'algorithme ...*/
   do {
      printf("Quel algorithme de tri utiliser ?\n");
      for (i = 0; i < 7; i++)
	printf("\t%d: %s\n", i, algo[i]);
      printf("\tnum: ");
      scanf(" %d", &methode);
   } while ( methode < 0 || methode > 6 );

   /* Nombre d'éléments à trier ...*/
   printf("Nombre d'éléments: ");
   scanf(" %d", &n);

   /* Disposition des valeurs initiale ...*/
   do {
      printf("Les valeurs à générer initialement sont : \n");
      printf("\t0: aléatoires ?\n");
      printf("\t1: en ordre croissant ?\n");
      printf("\t2: en ordre décroissant ?\n");
      printf("\tnum: ");
      scanf(" %d", &indic);
   } while ( indic < 0 || indic > 2 );


   printf( "Initialisation du tableau avec %d valeurs %s ...", \
	   n, (indic==0? "aléatoires" : (indic==1 ? "croissantes" : "décroissantes")) );
   fflush(stdout);  // pour forcer l'affichage sans attendre le '\n' dans le printf

   init_tab(n, indic);	 // alloue et initialise le tableau T

   printf(" effectuée\n");

   if (n < 100) affich_tab(n);

   switch(methode) {

	case 0 : printf("tri à bulles ... "); 
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_bulles(n);
		 gettimeofday(&tv2,NULL);
		 break;

	case 1 : printf("tri par insertion (version recursive) ... "); 
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_ins(n);
		 gettimeofday(&tv2,NULL);
		 break;

	case 2 : printf("tri par insertion (version iterative) ... ");
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_ins_it(n);
		 gettimeofday(&tv2,NULL);
		 break;

	case 3 : printf("tri par selection ... ");
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_select(n);
		 gettimeofday(&tv2,NULL);
		 break;

	case 4 : printf("tri fusion ... ");
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_fus(0,n-1);
		 gettimeofday(&tv2,NULL);
		 break;

	case 5 : printf("tri rapide de base ... ");
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 tri_rapide(0,n-1);
		 gettimeofday(&tv2,NULL);
		 break;

	case 6 : printf("tri qsort ... ");
		 fflush(stdout);
		 gettimeofday(&tv1,NULL);
		 qsort(T, n, sizeof(int), intcmp);
		 gettimeofday(&tv2,NULL);
		 break;
   }

   // durée de l'opération de tri en microseconde ...
   t = (tv2.tv_sec - tv1.tv_sec)*1000000 + (tv2.tv_usec - tv1.tv_usec);

   printf(" effectué\n");
   if (n < 100 ) affich_tab(n);

   if ( verif(n) ) 
	printf("Verification complete : le tableau est BIEN TRIE \n");
   
   if ( t > 999999 )
      	printf("\t\ttemps d'execution = %ld s et %ld ms\n\n", t / 1000000, (t % 1000000) / 1000);
   if ( t > 999 && t < 1000000 )
      	printf("\t\ttemps d'execution = %ld ms\n\n", t/1000);
   if ( t < 1000 )
      	printf("\t\ttemps d'execution = %ld microsec\n\n", t);
   
   free(T);

   return 0;

}  // fin main



/**********************************************
 * Allocation et initialisation des tableaux  *
 **********************************************/

void init_tab(int n, int indic)	
// n le nombre d'elements du tableau à allouer
// indic = 0 :  valeurs aléatoires / 1 : valeurs en ordre croissant / 2 : valeurs en ordre décroissant
{
    int i;

    T = malloc( n * sizeof(int) );	// le tableau principal
    tmp = malloc( n * sizeof(int) ); 	// le tableau temporaire pour tri_fus
	
    if ( T != NULL ) 
	switch( indic ) {
	case 0:	// Initialiser le générateur de nombre aléatoires
       		srand( (unsigned int)time((time_t *)NULL) );
       		// Génération de n nombres aléatoires entre 0 et 2n
       		for (i=0; i<n; i++)
	  	   T[i] = 1+(int) (2.0*n*rand()/(RAND_MAX+1.0));
		break;
	case 1:	// Génération de n nombres en ordre croissant entre 1 et n
       		for (i=0; i<n; i++)
	  	   T[i] = i+1;
		break;
	case 2:	// Génération de n nombres en ordre décroissant entre n et 1
       		for (i=0; i<n; i++)
	  	   T[i] = n-i;
		break;
	} // switch
    
    else
       printf("*** Probleme dans Allocation du tableau (malloc retourne NULL)\n");

}  // fin int_tab



/***************************************************
 * Affichage des n elements du tableau T           *
 ***************************************************/

void affich_tab(int n)
{
    int i;

    printf("T: ");
    for (i=0; i<n; i++)
	    printf("%d ", T[i]);
    printf("\n");

}  // fin affich


/***************************************************
 * Verifie si le tableau T est trié (1) ou non (0) *
 ***************************************************/

int verif(int n)
{
    int i;
    int trie = 1;
    for (i=0; i<n-1 && trie; i++)
	if (T[i] > T[i+1])  trie = 0;

    return trie;

}  // fin verif



/***************************************************
 * Fonction de comparaison utilisée avec qsort     *
 ***************************************************/

int intcmp(const void *a, const void *b)
{
    if ( *(int *)a < *(int *)b )
	return -1;

    if ( *(int *)a == *(int *)b )
	return 0;

    return 1;

}  // fin intcmp



/***************************************************
 * Tri par insertion (version recursive)           *
 ***************************************************/

void tri_ins(int n)
{
   int i, stop, v;

   if (n == 1) return;

   // Trier les n-1 premiers éléments par un appel récursif ...
   tri_ins(n-1);

   // Insérer le dernier lément (T[n-1]) dans le sous-tableau trié ...
   i = n-2;
   stop = 0;
   v = T[n-1];
   while (i >= 0 && !stop) 
  	if (v >= T[i]) {
		T[i+1] = v;
		stop = 1;
	}
	else {
		T[i+1] = T[i];
		i--;
	}		
   // while
   if (!stop) T[0] = v;

}  // fin tri_ins



/***************************************************
 * Tri par insertion (version iterative)           *
 ***************************************************/

void tri_ins_it(int n)
{
    int i, j, x, stop;

    for (i=1; i<n; i++) 
	if ( T[i-1] > T[i] ) {
	   j = i - 1; stop = 0; 
	   x = T[i];
	   T[i] = T[i-1];
	   while (j > 0 && !stop)
		 if (T[j-1] <= x) {
		    stop = 1;
		    T[j] = x;
		 }
	   	 else {
		    T[j] = T[j-1];
		    j--;
		 }
	   // while j
	   if (!stop) T[0] = x;
        }
    // for i
    return;

}  // fin tri_ins_it



/***************************************************
 * Tri par selection                               *
 ***************************************************/

void tri_select( int n )
{
   int i,j,v;

   for( i=0; i<n-1; i++ )
      for( j=i+1; j<n; j++ )
	if (T[i] > T[j]) { 
	   v = T[i];
	   T[i] = T[j];
	   T[j] = v;
	}
      // for j
   // for i

}  // fin tri_select



/***************************************************
 * Tri à bulles                                    *
 ***************************************************/

void tri_bulles( int n )
{
   int i, j, v, trie;

   for( i=n-1; i>0; i-- ) {
      trie = 1;
      for( j=0; j<i; j++ )
	if (T[j] > T[j+1]) { 
	   trie = 0;
	   v = T[j];
	   T[j] = T[j+1];
	   T[j+1] = v;
	}
      if (trie) break; 
   }

}  // fin tri_bulles



/***************************************************
 * Tri fusion (version recursive)                  *
 ***************************************************/

void tri_fus(int a, int b)
{
   int m,i,j,k;

   if (a>=b) return;

   // copuer T en 2 moitiés
   m = (a+b)/2;

   tri_fus(a,m);   // tri de la 1ere moitié
   tri_fus(m+1,b); // tri de la 2eme moitié

   // fusion des 2 moitiés (déjà triées) dans tmp ...
   i = a;
   j = m+1;
   k = 0;
   while (i<=m && j<=b)
   	if (T[i] < T[j])
	   tmp[k++] = T[i++];
	else
	   tmp[k++] = T[j++];
   while (i<=m) tmp[k++] = T[i++];
   while (j<=b) tmp[k++] = T[j++];

   // recopie de tmp dans T ...
   for (j=0; j<k; j++)
	T[a+j] = tmp[j];

}  // fin tri_fus



/***************************************************
 * Tri rapide (version recursive)                  *
 ***************************************************/

int partitionner( int bi, int bs, int pivot )
{
   int tmp, i, j;

   tmp = T[pivot];	// permuter le pivot avec 
   T[pivot] = T[bs];	// dernier élément.
   T[bs] = tmp;		// Le pivot se trouve maintenant dans T[bs]


   // deplacer (entre bi et j-1) tous les elt < pivot ...
   j = bi;
   for (i=bi; i<bs; i++)
      	if ( T[i] <= T[bs] ) {
   	   tmp = T[i];
   	   T[i] = T[j];
   	   T[j] = tmp;
	   j++;
	}

   // remettre le pivot à la position j
   tmp = T[bs];
   T[bs] = T[j];
   T[j] = tmp;

   return j;  // la nouvelle position du pivot

}  // fin partitionner


void tri_rapide(int bi, int bs)
{
   int pivot;

   if ( bi < bs ) {
	pivot = (bi + bs) / 2; 			// choix du pivot (au milieu par exemple)
	pivot = partitionner( bi, bs, pivot );	// répartir les elts par rapport au pivot
	tri_rapide( bi, pivot-1 );		// tri de la 1ere partie (< pivot)
	tri_rapide( pivot+1, bs );		// tri de la 2eme partie (> pivot)
   } 

}  // fin tri_rapide




