#include <stdio.h>
#include <stdlib.h>

typedef struct Liste Liste ;
struct Liste
{
    int info ;
    struct Liste *suiv ;
};
typedef Liste* Pliste ;

Liste* Ajout_debut (Liste * T, int x) ;

int main()
{
    Liste *T=NULL ,*P=NULL ;
    int x ;
    printf("Donnez la valeur a inserer au debut:\n");
    scanf("%d", &x);
    Ajout_debut(T, x) ;
    Affiche(P);

    return 0;
}
Liste* Ajout_debut (Liste *T, int x)
{
     Liste *P= malloc(sizeof(Liste));
     P->info = x ;
     P->suiv = T ;
     return P ;
};
void Affiche (Liste* Q)
{
  Liste *C;
  C= Q;
  if (Q==NULL)
  {
      printf("La liste est vide");
  }
  else
  {
      while (C != NULL)
      {
          printf("%d-->", C->info);
          C=C->suiv;
      }
  }
};
