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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
/*---------- Declaration des fonctions --------------------*/

Grid createGrid(int size){
	/*TODO: Instanciation dynamique de la grille
	//
	//je sais pas si ca marche vraiment mais ca compile :)
	//*/
	int i;
	Grid grid_final;
	grid_final.size = size;
	grid_final.block = NULL;
	grid_final.block = /*(char **)*/ malloc(size*sizeof(char *));
	for (i=0 ; i<size ; i++)
	{
		grid_final.block[i] = /*(char *)*/ malloc (size*sizeof(char));
	}
	return grid_final;
}

void releaseGrid(Grid *grd){
	//TODO: Destruction de la grille -> free()
	int i;
	for (i=0 ; i < grd->size ; i++)
	{
		free(grd->block[i]);
		grd->block[i] = NULL;
	}
	free(grd->block);
	grd = NULL;
}

/* Fonciton random qui rends des valeurs entre [a,b[*/
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

Grid initGridRandom(int size){
	/*//TODO: Appel de createGrid(size)  DONE
	//TODO: Affectation de toutes les valeurs de la grille avec des couleurs au hasard -> rand() % 6 DONE*/
	int i,j,r;
	
	srand(time(NULL));

	Grid grid_final = createGrid(size);
	
	for (i = 0; i<size ; i++)
	{
		for (j = 0 ; j<size ; j++)
		{
			r = (rand() % 6)+1 ;
			switch (r)
			{
				case 1:
				grid_final.block[i][j]='R';
				break;

				case 2:
				grid_final.block[i][j]='V';
				break;

				case 3:
				grid_final.block[i][j]='B';
				break;

				case 4:
				grid_final.block[i][j]='J';
				break;

				case 5:
				grid_final.block[i][j]='G';
				break;

				case 6:
				grid_final.block[i][j]='M';
				break;

			} 

		}
	} 

	return grid_final;
}

Grid initGridFromFile(char* file){
	/*TODO: Ouverture et lecture de la taille du fichier
	//TODO: Definir size avec la taille du fichier
	//TODO: Appel de createGrid(size)
	//TODO: Affectation de toutes les cases avec les valeurs du fichier
	//pas sur*/
	
	FILE* fichier = fopen(file, "r+");
/*/	int size =0;*/
	int size = fseek(fichier,0,SEEK_END);
	char* buf = malloc(size*sizeof(char));
	fseek(fichier,0,SEEK_SET);
	fread(buf,sizeof(char),size-1,fichier);
	int sideSize=(int)sqrt((float)size);
	createGrid(sideSize);
	

	



}

bool isColor(char color){
	if(color=='B' ||
	   color=='V' ||
	   color=='R' ||
	   color=='J' ||
	   color=='M' ||
	   color=='G')
		return true;
	else 
		return false;
}

bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color){
	/*//TODO: Verifie que la couleur existe
	//TODO: Changement de couleur */
	if(isColor(color)){
		grd->block[x][y]=color;
		return true;
	} else {
		return false;
	}
}

char *** identifyComponent4(Grid grd){
	/*//TODO: Identifier la composante...*/
	return NULL;
}

bool colorFlood(Grid *grd,unsigned int x,unsigned int y,char color){
	/* // voir https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion#Variante_4-connexe */
	if (!isColor(color))
		return false;

	if(color == grd->block[x][y])
		return true;
	else {
		grd->block[x][y]=color;
		if(x!=0)
			colorFlood(grd,x-1,y,color);
		if(x!=grd->size)
			colorFlood(grd,x+1,y,color);
		if(y!=0)
			colorFlood(grd,x,y-1,color);
		if(y!=grd->size)
			colorFlood(grd,x,y+1,color);
	}
}
/* //algo du pot de peinture/Composante 4 Connexe */

bool checkFullGrid(Grid grd){
	/* //TODO: Test si toute la grille a la meme valeur */
	int i,j;
	char value = grd.block[0][0];
	int size = grd.size;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(grd.block[i][j] != value)
				return true;
	return true;
}
