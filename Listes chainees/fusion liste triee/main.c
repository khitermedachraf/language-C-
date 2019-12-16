#include <stdio.h>
#include <stdlib.h>
typedef struct Liste Liste;
struct Liste
{
    int info;
    Liste *suiv;
};

Liste* Fusion_listes (Liste *L1, *L2)
{
    Liste *L3=NULL, *DL3=NULL;
    while (L1 != NULL && L2 != NULL)
    {
        if (L1->info <= L2->info)
        {
            if (L3 != NULL)
            {
                DL3 ->suiv =L1;
                DL3 = L1;
            }
            else
            {
                L3=L1;
                DL3=L3;
            }
            L1=L1->suiv;
        }
        else
        {
            if (L3 != NULL)
            {
                DL3 ->suiv =L2;
                DL3 = L2;
            }
            else
            {
                L3=L2;
                DL3=L3;
            }
            L2=L2->suiv;
        }
    }
    if (L1 != NULL)
    {
        DL3 ->suiv =L1;
    }
    else
    {
        DL3 ->suiv =L2;
    }
    L1=L3;
     return L1 ;

}

Liste* creation (Liste* T)
{
    Liste *P=NULL, *Q=NULL;
    int x;
    scanf("%d", &x);
    T->info = x;
    Q =T;
    scanf("%d", &x);
    while (x != -1)
    {
        P=malloc(sizeof(Liste));
        P->info =x;
        P->suiv =NULL;
        Q->suiv = P;
        Q = P;
        free(P);
        scanf("%d", &x);
    }
    return T;

}
Liste* affich (Liste* T)
{
    Liste* L=NULL;
    L=P;
    while (L != NULL)
    {
        printf("%d-->", L->info);
        L = L->suiv;
    }
}

int main()
{
    Liste *M, *N;
    printf("Remplissez la premiere liste tiree (inserez '-1' pour la terminer)\n");
    M=malloc(sizeof(Liste));
    creation(Liste* M);
    printf("Remplissez la deusieme liste triee (inserez '-1' pour la terminer)\n");
    N=malloc(sizeof(Liste));
    creation(Liste* N);
    Fusion_listes(Liste *M, *N);
    printf("Voici la fusion des 2 liste triee:\n");
    affich(Liste* M);





    return 0;
}
