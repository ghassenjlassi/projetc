#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "grid.h"
#include "solver.h"


void solveur(Grid *g, int n, Pile *solution, int profondeur) { //n:
	int i;
	Grid *g2;
	char tab[6] = {'R','V','B','J','O','M'};

	if(profondeur==n)
		return;
	// déclarations des variables locales i, g2, ...
	for (i=0; i<6; i=i+1) {
		// pour toutes les couleurs possibles
		empiler(solution,tab[i]);
		g2 = createGrid2(g);
		colorFlood2(g2, tab[i]);
		//showGrid(g2);
		//printf("\n");
		if (checkFullGrid(g2)){
			affiche(solution);
		}else{
			solveur(g2, n, solution, profondeur+1);
		}
		depiler(solution);
		releaseGrid(g2);
	}
//	releaseGrid(g2);
}

void affiche(Pile *pile)
{
	if (pile == NULL)
	{
		return;
//		exit(EXIT_FAILURE);
	}
	printf("Solution trouve : ");
	Element *actuel = pile->premier;
	while (actuel != NULL)
	{
		printf("%c ", actuel->couleur);
		actuel = actuel->suivant;
	}
	free (actuel);
	printf("\nfin de la solution\n");
}

void empiler(Pile *pile, char nvCouleur)
{
	Element *nouveau = malloc(sizeof(*nouveau));

	if (pile == NULL || nouveau == NULL)
	{
		return;
//		exit(EXIT_FAILURE);
	}

	nouveau->couleur = nvCouleur;
	nouveau->suivant = pile->premier;
	pile->premier = nouveau;
}

char depiler(Pile *pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}

	char couleurDepile = 0;
	Element *elementDepile = pile->premier;

	if (pile != NULL && pile->premier != NULL){
		couleurDepile = elementDepile->couleur;
		pile->premier = elementDepile->suivant;
		free(elementDepile);
	}

	return couleurDepile;
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

int main(){
	printf("Solveur O'Calm Force Brute\n");
	//INIT de la grille
	printf("Saisir la grille a evaluer : ");
	char file[255];
	scanf("%s",file);
	Grid * g;
	g = initGridFromFile(file);

	//DEFINIR la profondeur max
	printf("\n Saisir la profondeur max :");
        int max;
	scanf("%d",&max);

	//RECHERCHE des solutions
	printf("\nGRILLE:\n");
	showGrid(g);
	printf("\n### Debut du solveur ###\n\n");

	Pile * p;
	p = malloc(sizeof(Pile));
	p->premier =NULL;

	solveur(g,max,p,0);

	printf("\n### Fin du solveur ###\n");
	releaseGrid(g);
		
	free(p);
	return 0;
}
