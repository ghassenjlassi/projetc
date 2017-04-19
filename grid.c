/**
 * \file grid.c
 * \brief Fonctions de grille.
 * \author O'Calm
 * \version 0.1
 * \date 19 avril 2017
 *
 * Fonctions de creation, de modifiaction, de destructions de la grille.
 *
 */

#include "grid.h"

// ---------- Declaration des fonctions --------------------

Grid createGrid(int size){
	//TODO: Instanciation dynamique de la grille
	return NULL;
}

void releaseGrid(Grid grd){
	//TODO: Destruction de la grille -> free()
	return NULL;
}

Grid initGridRandom(int size){
	//TODO: Appel de createGrid(size)
	//TODO: Affectation de toutes les valeru de la grille avec des couleurs au hasard -> rand() % 6
	return NULL;
}

Grid initGridFromFile(char* file){
	//TODO: Ouverture et lecture de la taille du fichier
	//TODO: Definir size avec la taille du fichier
	//TODO: Appel de createGrid(size)
	//TODO: Affectation de toutes les cases avec les valeurs du fichier
	return NULL;
}

bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color){
	//TODO: Verifie que la couleur existe
	//TODO: Changement de couleur
	return false;
}

char *** identifyComponent4(Grid grd){
	//TODO: Identifier la composante...
	return NULL;
}

void colorFlood(Grid *grd,unsigned int x,unsigned int y,char color){
	// voir https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion#Variante_4-connexe
	//TODO: Coder !
	return NULL;
}
//algo du pot de peinture/Composante 4 Connexe

bool checkFullGrid(Grid grd){
	//TODO: Test si toute la grille a la meme valeur
	return false;
}
	