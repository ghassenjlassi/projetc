/**
 * \file solver.h
 * \brief Declaration des element du solveur.
 * \author O'Calm
 * \version 0.1
 * \date 14 mai 2017
 *
 * Déclaration des fonctions et des elements utilisés por le solveur.
 *
 */

/**
 * \struct Element
 * \brief Les elements utilisé dans la pile
 */
typedef struct Element Element;

struct Element
{
	char couleur;
	Element *suivant;
};

/**
 * \struct Pile
 * \brief Definition de la pile
 *
 */
typedef struct Pile Pile;

struct Pile
{
	Element *premier;
};

/**
 * \fn void affiche(Pile *pile)
 * \brief fonction qui fait l'affichage d'une solution
 *
 * \param pile la pile à afficher
 */
void affiche(Pile *pile);

/**
 * \fn void empiler(Pile *pile, char nvCouleur)
 * \brief on ajoute un element sur la pile 
 *
 * \param pile la pile sur laquelle on empile
 * \param nvCouleur la couleur à empiler
 */
void empiler(Pile *pile, char nvCouleur);

/**
 * \fn char depiler(Pile *pile)
 * \brief on depile un element de la pile
 *
 * \param pile la pile à dépiler
 * \return le char correspondant à la couleur qu'on depile
 *
 */
char depiler(Pile *pile);


