
// structure représentant un Tableau Dynamique Ordonné (TDO)
struct TabOrd {
	int NbElem;	// nb d'éléments insérés
	int Taille;	// nb maximum d'éléments
	int *Contenu;	// le tableau des éléments
};
typedef struct TabOrd TDO;	// TDO est un aliase de 'struct TabOrd'

// alloue un TDO vide de taille 'tailleMax' entiers
TDO *AllouerTab( int tailleMax );

// pour remplir le TDO t avec n valeurs aléatoires, puis l'ordonner avec qsort
int Remplir( int n, TDO *t );

// pour libérer le TDO t
void LibererTab( TDO *t );

// recherche dichotomique de v dans le TDO t. Retourne l'indice de v et trouv
int Rech( int v, TDO *t, int *trouv );

// insère v par décalages dans le TDO t de manière à maintenir l'ordre
int Ins( int v, TDO *t );

// affiche les éléments du TDO t
void Affich( TDO *t );


