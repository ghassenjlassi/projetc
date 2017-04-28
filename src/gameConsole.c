/**
 * \file gameConsole.c
 * \brief Le programme principal
 * \author O'Calm
 * \version 0.1
 * \date 27 avril 2017
 *
 * Le programme principal en mode console ;)
 *
 */
#include "gameConsole.h"

Grid *Grd=NULL;

void  main(){
	printf("ColorFlood\n");
	unsigned int side,limit;
	printf("Veuillez saisir la taille de la grille et le nombre de coup (format : side <espace> limite): ");
	fflush(stdin);
	scanf("%d %d",&side,&limit);
	printf("\n");
	Grd=initGridRandom(side,6);
	
	bool end=false;
	unsigned int x,y;
	unsigned int move=1; //le nombre de coup joués

	while(!end){
		showGrid(Grd);

		printf("Coup %d/%d : Saisir position(x (espace) y) :",move,limit);
                scanf("%d %d",&x,&y);
                printf("\n");

                colorFlood(Grd,x,y);
		move=move+1;	
		if(checkFullGrid(Grd))
			end=true;
	}
}

void showGrid(Grid* grd){
	unsigned int i,j;
	for(i=0;i<grd->size;i++){
		for(j=0;j<grd->size;j++){
			printf("%c ",grd->block[i][j]);
		}
		printf("\n");
	}
}

void showMenu(){
	printf("1) Initialiser la grille vide\n");	
	printf("2) Initialiser la grille au hasard\n");
	printf("3) Initialiser la grille avec un fichier\n");
	printf("4) Changer la couleur d'une case\n");
	printf("5) Remplissage/ColorFlood\n");
	printf("6) Tester si la grile est pleine\n");
	printf("7) Détruire la grille\n");
	printf("8) Quitter\n");
	printf("Que voulez-vous faire ? : ");
}
