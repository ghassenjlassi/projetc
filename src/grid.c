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

Grid* createGrid(int size,int couleur){
	int i;
	Grid *grid_final;
	grid_final=malloc(1*sizeof(Grid));
	grid_final->size = size;
	grid_final->couleur = couleur;
	grid_final->block = malloc(size*sizeof(char *));
	for (i=0 ; i<size ; i++)
	{
		grid_final->block[i] = malloc (size*sizeof(char));
	}
	return grid_final;
}

void releaseGrid(Grid *grd){
	unsigned int i;
	for (i=0 ; i < grd->size ; i++)
	{
		free(grd->block[i]);
		grd->block[i] = NULL;
	}
	free(grd->block);
	free(grd);
	grd=NULL;
}

Grid* initGridRandom(int size, int c){
	int i,j,r;
	srand(time(NULL));
	Grid *grid_final = createGrid(size,c);
	for (i = 0; i<size ; i++)
	{
		for (j = 0 ; j<size ; j++)
		{
			r = (rand() % c)+1 ;
			switch (r)
			{
				case 1:
				grid_final->block[i][j]='R';
				break;

				case 2:
				grid_final->block[i][j]='V';
				break;

				case 3:
				grid_final->block[i][j]='B';
				break;

				case 4:
				grid_final->block[i][j]='J';
				break;

				case 5:
				grid_final->block[i][j]='O';
				break;

				case 6:
				grid_final->block[i][j]='M';
				break;
			}
		}
	}
	return grid_final;
}

Grid* initGridFromFile(char* file){
	FILE *fd = fopen(file,"r+");
	if(fd == NULL){
		return NULL;
	}
	fseek(fd,0,SEEK_SET);
	char buf;
	int size= 0;

	while (fread(&buf,sizeof(char),1,fd)) size++;
	fseek(fd,0,SEEK_SET);

	int sideSize=(int)sqrt((float)size);
	Grid *grd;
	grd=createGrid(sideSize,6);
	int i,j;

	for(i=0;i<sideSize;i++){
		for(j=0;j<sideSize;j++){
			fread(&buf,sizeof(char),1,fd);
			grd->block[i][j]=buf;
		}
	}
	fclose(fd);
	return grd;
}

void changeCaseColor(Grid *grd,unsigned int x,unsigned int y,char color){
	grd->block[x][y]=color;
}

/*char *** identifyComponent4(Grid grd){
	//TODO: Identifier la composante...
	return NULL;
}*/

void colorFill(Grid *grd,unsigned int x,unsigned int y,char colorTarget,char colorRep){
	// voir https://en.wikipedia.org/wiki/Flood_Fill
	if(colorTarget == colorRep)
		return;
	if(colorTarget != grd->block[x][y])
		return;
	grd->block[x][y]=colorRep;
	if(x!=0)
		colorFill(grd,x-1,y,colorTarget,colorRep);
	if(x!=grd->size-1)
			colorFill(grd,x+1,y,colorTarget,colorRep);
	if(y!=0)
			colorFill(grd,x,y-1,colorTarget,colorRep);
	if(y!=grd->size-1)
			colorFill(grd,x,y+1,colorTarget,colorRep);
	return;
}

void colorFlood(Grid *grd,unsigned int x,unsigned int y){
	colorFill(grd,0,0,grd->block[0][0],grd->block[x][y]);	
}


void colorFlood2(Grid *grd,unsigned char color){
	colorFill(grd,0,0,grd->block[0][0],color);
}

bool checkFullGrid(Grid* grd){
	int i,j;
	char value = grd->block[0][0];
	int size = grd->size;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(grd->block[i][j] != value)
				return false;
	return true;
}
