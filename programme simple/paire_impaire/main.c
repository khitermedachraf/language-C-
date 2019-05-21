#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///  Ce programme teste si les elements de tableau sont  paires ou impaires
///  et le classer dans deux sous-tableaux deffirents .
 int main()
{
    printf("Hello world!\n");

    int tableau [10] ;
    int T1[10] ;
    int T2 [10] ;
    int j=0; int k=0 ;


    for ( int i=0 ; i < 10 ; i++ ) {
        tableau[i]= rand () ;
    }


     for ( int i=0 ; i < 10 ; i++ ) {
        if (tableau[i] % 2 == 0) {
            T1[j]= tableau [i]  ;
            j++;

        }
        else {
            T2[k]= tableau[i] ;
            k++;
        }
    }
    printf("Le tableau est  : \n\t") ;
    for ( int i=0 ; i < 10 ; i++ ) {
        printf("%d |", tableau[i] ) ;
    }

        printf("\n\n\n") ;
         printf("Le tableau des paires est  : \n\t") ;
      for ( int i=0 ; i < j ; i++ ) {
        printf("%d |", T1[i] ) ;
    }

        printf("\n\n\n") ;
     printf("Le tableau des impaires est  : \n\t") ;
      for ( int i=0 ; i < k ; i++ ) {
        printf("%d |", T2[i] ) ;
    }
    return 0;
}
