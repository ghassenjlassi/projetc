
#ifndef __GC_H__
#define __GC_H__
/**
 * \file gameConsole.h
 * \brief Jeu ColorFlood 
 * \author O'Calm
 * \version 0.1
 * \date 27 avril 2017
 *
 * Le jeu en mode console ;)
 *
 */

//#include "grid.c"


/**
 * \fn void main()
 * \brief programme
 */

/**
 * \fn void showGrid(Grid* grd)
 * \brief Affiche la grille en texte
 * \param *grd la grille à afficher.
 */
void showGrid(Grid* grd);

/**
 * \fn void showMenu()
 * \brief Affiche le menu du jeu
 * Propose à l'utilisateur plusieurs choix d'actions à réaliser
 */
void showMenu();
#endif
