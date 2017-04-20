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

 /**
 * \struct Grid
 * \brief Objet grille pour le jeu.
 *
 * grid est une structure pour definir la grille du jeu colorflood.
 * elle est definie par des cases (block) et sa taille (size) correspondant au nombre de carre sur un cote.
 *
 */
typedef struct{
	unsigned char ** block;
	unsigned int size;
} Grid
;

/**
 * \fn Grid createGrid(int size)
 * \brief Fonction de création d'une nouvelle grille vide.
 *
 * \param size taille de la grille carrée a créer.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid createGrid(int size);


/**
 * \fn void releaseGrid(Grid grd)
 * \brief Fonction de destruction d'une grille.
 *
 * \param grd la grille à detruire.
 */
void releaseGrid(Grid grd);

/**
 * \fn Grid initGridRandom(int size)
 * \brief Fonction de création d'une nouvelle grille rempli avec des valeurs aléatoires.
 *
 * \param size taille de la grille carrée a créer.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid initGridRandom(int size);


/**
 * \fn Grid initGridFromFile(char* file)
 * \brief Fonction de création d'une nouvelle grille, avec un fichier d'entrée.
 *
 * \param file le fichier pour instancier la grille.
 * \param size taille de la grille carrée.
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid initGridFromFile(char* file);


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
bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color);


/**
 * \fn char *** identifyComponent4(Grid grd)
 * \brief Fonction d'indentifiaction de la composante 4 connexe.
 *
 * \param grd la grille à utiliser.
 * \return un tableau des cases de la composante 4-connexe.
 */
char *** identifyComponent4(Grid grd);


/**
 * \fn bool colorFlood(Grid *grd,unsigned int x,unsigned int y,char color)
 *
 * \brief Fonction de remplissage sur la case selectionnée
 *
 * \param grd la grille à modifier.
 * \param x la coordonnée x de la case selectionnée(case de départ).
 * \param y la coordonnée y de la case selectionnée(case de départ).
 * \param color la couleur de la case à modifier.
 * \return true si couleur correctement changée, false sinon.
 */
bool colorFlood(Grid *grd,unsigned int x,unsigned int y,char color);

/**
 * \fn bool checkFullGrid(Grid grd)
 * \brief Fonction de test de la présence de la même valeur dans toutes les cases.
 *
 * \param grd la grille à tester.
 * \return true si grille remplie avec la même valeur, false sinon.
 */
bool checkFullGrid(Grid grd);
