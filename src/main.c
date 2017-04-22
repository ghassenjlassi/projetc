/**
 * \file main.c
 * \brief Programme d'utilisation des principales fonctions du lot A
 * \author O'Calm
 * \version 0.1
 * \date 22 avril 2017
 *
 * Le programme principal ;)
 *
 */

#include "grid.c"
#include <stdio.h>

void showGrid(Grid grd);
void showMenu();

int main(){
	printf("ColorFlood\n");
	int choix,size,x,y;
	char file[255], color;
	Grid G;
	while(1) {
		showMenu();
		fflush(stdin);
		scanf("%d",&choix);
		switch (choix){
			case 1 :
				printf("Saisir la taille de la grille : ");
				fflush(stdin);
				scanf("%d",&size);
				printf("\n");
				G=createGrid(size);
				printf("Grille initialisée\n");
				break;
			case 2 :
				printf("Saisir la taille de la grille : ");
				fflush(stdin);
				scanf("%d",&size);
				printf("\n");
				G=initGridRandom(size);
				showGrid(G);
				break;
			case 3 :
				printf("Saisir le nom du fichier d'entree: ");
				fflush(stdin);
				scanf("%s",file);
				printf("\n");
				G=initGridFromFile(file);
				if(&G!=NULL)
					showGrid(G);	
				else
					printf("Erreur de fichier\n");
				break;
			case 4 :
				printf("Saisir la position et la couleur dans la grille (tapez : x (espace) y (espace) couleur): ");
				fflush(stdin);
				scanf("%d %d %c",&x,&y,&color);
				printf("\n");
				changeCaseColor(&G,x,y,color);
				showGrid(G);
				break;
			case 5:
				printf("Saisir la position de la case dans la grille (tapez : x (espace) y: ");
				scanf("%d %d",&x,&y);
				printf("\n");
				colorFlood(&G,x,y);
				showGrid(G);
				break;
			case 6:
				if(checkFullGrid(G))
					printf("Grille pleine\n");
				else 
					printf("Grille PAS pleine\n");
				break;
			case 7:
				releaseGrid(&G);
				break;
			case 8:
				return 0;
				break;
			default:
				printf("mauvais choix\n");

		}
	}
	return 0;
}

void showGrid(Grid grd){
	unsigned int i,j;
	for(i=0;i<grd.size;i++){
		for(j=0;j<grd.size;j++){
			printf("%c ",grd.block[i][j]);
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
