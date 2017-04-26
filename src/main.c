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

/**
 * \fn int main()
 * \brief Application ColorFlood
 * \return 0 en cas de succes
 */
int main(){
	printf("ColorFlood\n");
	int choix,size,x,y,c;
	char file[255], color;
	Grid *G=NULL;
	while(1) {
		showMenu();
		fflush(stdin);
		scanf("%d",&choix);
		switch (choix){
			case 1 :
				printf("Saisir la taille de la grille : et le nombre de couleur");
				fflush(stdin);
				scanf("%d",&size);
				scanf("%d",&c);
				printf("\n");
				if(G!=NULL)
					releaseGrid(G);
				G=createGrid(size,c);
				printf("Grille initialisée\n");
				break;
			case 2 :
				printf("Saisir la taille de la grille : et le nombre de couleur");
				fflush(stdin);
				scanf("%d",&size);
				scanf("%d",&c);
				printf("\n");
				if(G!=NULL)
					releaseGrid(G);
				G=initGridRandom(size,c);
				showGrid(G);
				break;
			case 3 :
				printf("Saisir le nom du fichier d'entree: ");
				fflush(stdin);
				scanf("%s",file);
				printf("\n");
				if(G!=NULL)
					releaseGrid(G);
				G=initGridFromFile(file);
				if(G!=NULL)
					showGrid(G);	
				else
					printf("Erreur de fichier\n");
				break;
			case 4 :
				printf("Saisir la position et la couleur dans la grille (tapez : x (espace) y (espace) couleur): ");
				fflush(stdin);
				scanf("%d %d %c",&x,&y,&color);
				printf("\n");
				changeCaseColor(G,x,y,color);
				showGrid(G);
				break;
			case 5:
				printf("Saisir la position de la case dans la grille (tapez : x (espace) y) : ");
				scanf("%d %d",&x,&y);
				printf("\n");
				colorFlood(G,x,y);
				showGrid(G);
				break;
			case 6:
				if(checkFullGrid(G))
					printf("Grille pleine\n");
				else 
					printf("Grille PAS pleine\n");
				break;
			case 7:
				if(G!=NULL)
					releaseGrid(G);
				break;
			case 8:
				if(G!=NULL)
					releaseGrid(G);
				return 0;
				break;
			default:
				printf("mauvais choix\n");

		}
	}
	return 0;
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
