#include <stdio.h>
#include <stdlib.h>

typedef struct  Liste Liste;

struct Liste
{
    int info;
    Liste *suiv, *pred;
};

Liste* Insertion (Liste *T, int k,int val)
{
    Liste *P, *R;
    int i;
    i=0;
    R=T;
    P=(Liste*)malloc(sizeof(Liste));
    P->info=val;
    while ((R !=NULL) && (i<k) )
    {
        P=P->suiv;
        i++;
    }
    if (i==k)
    {
        if (i==0)
        {
            P->suiv=T;
            P->pred=NULL;
            if (T != NULL)
            {
                T->pred=P;
            }
            T=P;
        }
        else
        {
            (R->pred)->suiv=P;
            P->pred=R->pred;
            R->pred=P;
            P->suiv=L;
        }
    }
    return T;
}

Liste* Supp (Liste* T, int val)
{
    Liste *P;
    if (T != NULL)
    {
        if (T==val)
        {
            T=T->suiv;
            T->pred=NULL;
        }
        else
        {
            P=T;

        }
    }

}

int main()
{

    return 0;
}
