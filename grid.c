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

	//pas sûr que c'est correct!! 

	int i;
	Grid grid_final = NULL;
	grid_final = (Grid) malloc(size*sizeof(char *));
	for (i=0 ; i<size ; i++)
	{
		grid_final[i] = (char *) malloc (size*sizeof(char));
	}
	return grid_final;
}

void releaseGrid(Grid grd){
	//TODO: Destruction de la grille -> free()
	return NULL;
}
// Fonciton random qui rends des valeurs entre [a,b[
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

Grid initGridRandom(int size){
	//TODO: Appel de createGrid(size)  DONE
	//TODO: Affectation de toutes les valeurs de la grille avec des couleurs au hasard -> rand() % 6 DONE
	int i,j,r;
	
	grid_final = createGrid(size);
	
	for (i = 0; i<size ; i++)
	{
		for (j = 0 ; j<size ; j++0)
		{
			r = (rand() % 6)+1 ;
			switch (r)
			{
				case 1:
				grid_final[i][j]='R';
				break;

				case 2:
				grid_final[i][j]='V';
				break;

				case 3:
				grid_final[i][j]='B';
				break;

				case 4:
				grid_final[i][j]='J';
				break;

				case 5:
				grid_final[i][j]='O';
				break;

				case 6:
				grid_final[i][j]='M';
				break;

			} 

		}
	} 

	return grid_final;
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
	