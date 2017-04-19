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
 * \struct grid
 * \brief Objet grille pour le jeu.
 *
 * grid est une structure pour definir la grille du jeu colorflood
 * elle est definie par des cases (block) et sa taille (size) correspondant au nombre de carre sur un cote
 *
 */
//typedef char ** grid;
typedef struct{
	unsigned char ** block;
	unsigned int size;
} Grid
;

//creation de la grille dynamiquement -> maloc/caloc/...
/**
 * \fn createGrid
 * \brief Fonction de création d'une nouvelle grille vide
 *
 * \param size taille de la grille carrée a créer
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid createGrid(int size);


/**
 * \fn releaseGrid
 * \brief Fonction de destruction d'une grille 
 *
 * \param grd la grille à detruire
 */
void releaseGrid(Grid grd);


// init de la grille avec des couleurs au hasard -> random()
/**
 * \fn initGridRandom
 * \brief Fonction de création d'une nouvelle grille rempli avec des valeurs aléatoires
 *
 * \param size taille de la grille carrée a créer
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid initGridRandom(int size);


/**
 * \fn initGridFromFile
 * \brief Fonction de création d'une nouvelle grille, avec un fichier d'entrée
 *
 * \param file le fichier pour instancier la grille
 * \param size taille de la grille carrée
 * \return Instance nouvellement allouée d'un objet de type Grid ou NULL.
 */
Grid initGridFromFile(char* file);


/**
 * \fn changeCaseColor
 * \brief Fonction de changement la couleur d'une case en x,y par la couleur f
 *
 * \param grd la grille à modifier
 * \param x la coordonnée x de la case à modifier
 * \param y la coordonnée y de la case à modifier
 * \param color la couleur de la case à modifier
 * \return true si couleur correctement changée, false sinon
 */
bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color);


/**
 * \fn changeCaseColor
 * \brief Fonction d'indentifiaction de la composante 4 connexe
 *
 * \param grd la grille à utiliser
 * \return un tableau des cases de la composante 4-connexe
 */
char *** identifyComponent4(Grid grd);


/**
 * \fn colorFlood
 * \brief Fonction de remplissage sur la case selectionnée
 *
 * \param grd la grille à modifier
 * \param x la coordonnée x de la case selectionnée(case de départ)
 * \param y la coordonnée y de la case selectionnée(case de départ)
 * \param color la couleur de la case à modifier
 * \return true si couleur correctement changée, false sinon
 */
void colorFlood(Grid *grd,unsigned int x,unsigned int y,char color);
// voir https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion#Variante_4-connexe
//algo du pot de peinture/Composante 4 Connexe


/**
 * \fn checkFullGrid
 * \brief Fonction de test de la présence de la même valeur dans toutes les cases
 *
 * \param grd la grille à tester
 * \return true si grille remplie avec la même valeur, false sinon
 */
bool checkFullGrid(Grid grd);
