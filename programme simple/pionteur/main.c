#include <stdio.h>
#include <stdlib.h>

void permut ( int *x , int *y ){
    int c= *x ;
    *x=*y ;
    *y=c ;
}
int main()
{
    printf("Hello world!\n");
    int *p ;
    int a;
    a= 10 ;
    p=&a ;
    printf ("%d %d %d %d",a,*p,p,&a);
    printf("\n") ;
    int x=5 ;
     int y=10 ;
    printf(" %d %d",x,y);
    permut(&x,&y) ;
    printf(" %d %d",x,y);
    return 0;
}
