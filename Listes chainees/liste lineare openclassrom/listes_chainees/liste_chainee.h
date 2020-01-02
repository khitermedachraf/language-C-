#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

Liste *initialisation();
Pile *initialiserPile();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void empiler(Pile *pile, int nvNombre) ;
int depiler(Pile *pile) ;
void afficherPile(Pile *pile) ;

#endif
