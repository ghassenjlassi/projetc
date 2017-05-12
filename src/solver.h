typedef struct Element Element;

struct Element

{

    int nombre;

    Element *suivant;

};

typedef struct Pile Pile;

struct Pile

{

    Element *premier;

};
void affiche(Pile *pile);

void empiler(Pile *pile, int nvNombre);


int depiler(Pile *pile);