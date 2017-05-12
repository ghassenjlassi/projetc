/**
 * \file grid.h
 * \brief Declaration des fonctions de grille.
 * \author O'Calm
 * \version 0.1
 * \date 19 avril 2017
 *
 * Déclaration des fonctions de creation, de modifiaction, de destructions de la grille.
 *
 */

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 /**
 * \struct bool
 * \brief Définition du type bool
 */
typedef int bool;
#define true 1
#define false 0

 /**
 * \struct Grid
 * \brief Objet grille pour le jeu.
 *
 * grid est une structure pour definir la grille du jeu colorflood.
 * elle est definie par des cases (block) et la taille (size) de son coté.
 * litteralement la grille est : char block[size][size]
 *
 */
typedef struct{
	unsigned char ** block; /**< les cases de la grille. */
	unsigned int size;	/**< le nombre de case d'un coté de la grille(carré). */
} Grid
;

/**
 * \fn Grid createGrid(int size)
 * \brief Fonction de création d'une nouvelle grille vide.
 *
 * \param size taille de la grille carrée a créer.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid* createGrid(int size);


/**
 * \fn Grid createGrid2(Grid* g)
 * \brief Fonction de création d'une nouvelle grille par copie d'une ancienne grille.
 *
 * \param g grille qu'on veut copier.
 * \return nouvelle grille copié de la grille g de depart
 */
Grid* createGrid2(Grid* g);

/**
 * \fn releaseGrid(Grid *grd)
 * \brief Fonction de destruction d'une grille.
 *
 * \param grd la grille à detruire.
 */

void releaseGrid(Grid *grd);

/**
 * \fn Grid* initGridRandom(int size)
 * \brief Fonction de création d'une nouvelle grille rempli avec des valeurs aléatoires.
 *
 * \param size taille de la grille carrée a créer.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid* initGridRandom(int size);


/**
 * \fn Grid* initGridFromFile(char* file)
 * \brief Fonction de création d'une nouvelle grille, avec un fichier d'entrée.
 *
 * \param file le fichier pour instancier la grille.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid* initGridFromFile(char* file);


/**
 * \fn bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color)
 * \brief Fonction de changement la couleur d'une case en x,y par la couleur f.
 *
 * \param grd la grille à modifier.
 * \param x la coordonnée x de la case à modifier.
 * \param y la coordonnée y de la case à modifier.
 * \param color la couleur de la case à modifier.
 * \return true si couleur correctement changée, false sinon.
 */
void changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color);


/**
 * \fn char *** identifyComponent4(Grid grd)
 * \brief Fonction d'indentifiaction de la composante 4 connexe.
 *
 * \param grd la grille à utiliser.
 * \return un tableau des cases de la composante 4-connexe.
 */
char *** identifyComponent4(Grid grd);


/**
 * \fn void colorFill(Grid *grd,unsigned int x,unsigned int y,char colorTarget, char colorRep)
 *
 * \brief Fonction de remplissage sur la case selectionnée
 *
 * \param grd la grille à modifier.
 * \param x la coordonnée x de la case selectionnée(case de départ).
 * \param y la coordonnée y de la case selectionnée(case de départ).
 * \param colorTarget la couleur à appliquer.
 * \param colorRep la couleur des cases à modifier.
 */
void colorFill(Grid *grd,unsigned int x,unsigned int y,char colorTarget,char colorRep);

/**
 * \fn void colorFlood(Grid *grd,unsigned int x,unsigned int y)
 *
 * \brief Fonction de remplissage de la composante 4 connexe en utilisant la couleur de la case selectionnée 
 *
 * \param grd la grille à modifier.
 * \param x la coordonnée x de la case selectionnée.
 * \param y la coordonnée y de la case selectionnée.
 */
void colorFlood(Grid *grd,unsigned int x,unsigned int y);

/**
 * \fn void colorFlood2(Grid *grd,unsigned char color)
 *  
 * \brief Fonction de remplissage de la composante 4 connexe en utilisant la couleur de la case selectionnée 
 * 
 * \param grd la grille à modifier.
 * \param color la couleur à appliquer.
 **/
void colorFlood2(Grid *grd, unsigned char color);

/**
 * \fn Grid* colorFlood3(Grid *grd,unsigned char color)
 *  
 * \brief Fonction de remplissage de la composante 4 connexe en utilisant la couleur de la case selectionnée 
 * 
 * \param grd la grille à modifier.
 * \param color la couleur à appliquer.
 * \return la nouvelle grille après le remplissage 
 **/
Grid* colorFlood3(Grid *grd,unsigned char color);




/**
 * \fn bool checkFullGrid(Grid* grd)
 * \brief Fonction de test de la présence de la même valeur dans toutes les cases.
 *
 * \param grd la grille à tester.
 * \return true si grille remplie avec la même valeur, false sinon.
 */
bool checkFullGrid(Grid* grd);











