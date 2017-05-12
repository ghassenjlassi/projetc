typedef struct Element Element;

struct Element

{

    char nombre;

    Element *suivant;

};

typedef struct Pile Pile;

struct Pile

{

    Element *premier;

};
void affiche(Pile *pile);



void empiler(Pile *pile, char nvNombre);


int depiler(Pile *pile);