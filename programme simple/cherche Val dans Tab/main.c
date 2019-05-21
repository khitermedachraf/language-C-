#include <stdio.h>
#include <stdlib.h>
#include <time.h>



    /// Rechercher  la valeure a danss le tableau tab a une dimension
    /// daont la taille est l , et son indice n , - s'il n'existe pas

    int recherche ( int tab [] , int l,int a ) {
            int i , n ;
            int f = 0 ;

            while ( ( f = 0) && i<l)  {
                if ( tab[i] = a ) { f= 1 ; n= i ;}
                else { i++ ;};
            }
            if( f=0 ) { n= -1 ;} ;


        return(  n ) ;
    }
int main()
{
    printf("Hello world!\n");
    int tableau [100] ;
    int a ;

     for ( int i=0 ; i < 100 ; i++ ) {
        tableau[i]= rand () ;
    }

     printf("Le tableau est  : \n\t") ;
    for ( int i=0 ; i < 100 ; i++ ) {
        printf("%d |", tableau[i] ) ;
    };
     printf(" Donner la valeure cherchee < a >: ") ;
        scanf("%d",&a) ;
        printf("\n\n\n\t") ;
        printf("l'indice de valeure cherchee < %d > est : %d ",a, recherche ( tableau [100], 100, a ) );
    return 0;
}
