/**
 * \file grid.c
 * \brief Fonctions de grille.
 * \author O'Calm
 * \version 0.1
 * \date 19 avril 2017
 *
 * Fonctions de creation, de modification, de destruction de la grille.
 *
 */

#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// ---------- Declaration des fonctions --------------------

Grid createGrid(int size){
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
	//TODO : TEST
	unsigned int i;
	for (i=0 ; i < grd->size ; i++)
	{
		free(grd->block[i]);
		grd->block[i] = NULL;
	}
	free(grd->block);
	grd = NULL;
}

Grid initGridRandom(int size){
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
				grid_final.block[i][j]='O';
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
	//TODO: Ouverture et lecture de la taille du fichier
	//TODO: Definir size avec la taille du fichier
	//TODO: Appel de createGrid(size)
	//TODO: Affectation de toutes les cases avec les valeurs du fichier
	//pas sur
	FILE *fd = fopen(file,"r+");
	fseek(fd,0,SEEK_SET);
	char buf;
	int size= 0;

	while (fread(&buf,sizeof(char),1,fd)) size++;
	fseek(fd,0,SEEK_SET);

	int sideSize=(int)sqrt((float)size);
	Grid grd=createGrid(sideSize);
	int i,j;

	for(i=0;i<sideSize;i++){
		for(j=0;j<sideSize;j++){
			fread(&buf,sizeof(char),1,fd);
			grd.block[i][j]=buf;
		}
	}
	fclose(fd);
	return grd;
}

bool changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color){
	grd->block[x][y]=color;
	return true;
}

/*char *** identifyComponent4(Grid grd){
	//TODO: Identifier la composante...
	return NULL;
}*/

bool colorFlood(Grid *grd,unsigned int x,unsigned int y,char color){
	// voir https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion#Variante_4-connexe
	//TODO : Test
	if(color == grd->block[x][y])
		return true;
	else {
		grd->block[x][y]=color;
		if(x>0)
			colorFlood(grd,x-1,y,color);
		if(x<grd->size)
			colorFlood(grd,x+1,y,color);
		if(y>0)
			colorFlood(grd,x,y-1,color);
		if(y<grd->size)
			colorFlood(grd,x,y+1,color);
	}
	return false;
}

bool checkFullGrid(Grid grd){
	//TODO: Test si toute la grille a la meme valeur
	int i,j;
	char value = grd.block[0][0];
	int size = grd.size;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(grd.block[i][j] != value)
				return false;
	return true;
}
