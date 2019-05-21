#include <stdio.h>
#include <stdlib.h>
    struct record {
        int x ;
        int y  ;
        char name [100] ;

    };

     struct record fct1 (){
        struct record variable ;
        variable.x= 55 ;
        variable.y =100;
        variable.name[100]= "khiter Med Achraf"  ;
     };
//     struct record one {
//        char nom [25] ;
//        char prenom [25] ;
//        int age ;
//      };
int main()
{
    struct record fct1 () ;
    struct record variable ;
    printf("l'enregistrement  est   :  %d        %d     %s ", variable.x,variable.y,variable.name) ;
    printf("\n\n\t") ;
    printf("Hello world!\n");
    return 0;
}
