typedef struct Element Element;

struct Element
{
    char couleur;
    Element *suivant;
};

typedef struct Pile Pile;

struct Pile
{
    Element *premier;
};

void affiche(Pile *pile);

void empiler(Pile *pile, char nvCouleur);

char depiler(Pile *pile);
