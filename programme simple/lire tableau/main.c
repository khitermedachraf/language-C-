#include <stdio.h>
#include <stdlib.h>
 void lect1D ( int *T , int taille) {
    for (int i=0 ; i < taille ; i++) {
        printf(" T[%d]=", i ) ;
        scanf("%d",&T[i]) ;
    }
    return ;
 }
 void ecrit1D (int*T , int taille) {
    for (int i=0 ; i< taille ; i++) {

        printf(" %d |" , T[i]) ;
    }

 }

 int max_tab (int *tab , int  taille) {
  int i=0 ; int max= tab[0] ;
  for (i=0 ; i < taille ; i++) {

    if ( tab[i] > max ) {
        max= tab[i] ;
    }
  }
  return(max) ;
 }

 int min_tab (int *tab , int  taille) {
  int i=0 ; int min= tab[0] ;
  for (i=0 ; i < taille ; i++) {

    if ( tab[i] < min ) {
        min= tab[i] ;
    }
  }
  return(min) ;
 }

int main()
{
    int N ;
    printf("Donner la taille  du tableau  : " );
    scanf("%d" , &N) ;
    int tab[ N ] ;
    lect1D(tab, N ) ;
    printf("\n\n");
    ecrit1D (tab ,  N);
    printf("\n\n");
    printf("la grande valeure du tableau est : %d" ,max_tab (tab, N)) ;
    printf("\n\n");
    printf("la petite valeure du tableau est : %d" ,min_tab (tab, N)) ;
    printf("\n\n");
    printf("Hello world!\n");
    return 0;
}
