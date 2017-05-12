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


			// déclarations des variables locales i, g2, ...
			for (i=0; i<6; i=i+1) { 
			// pour toutes les couleurs possibles
			empiler(solution,i);
	
			char tab[6] = {'R','V','B','J','O','M'};
			 
			g2 = colorFlood3(g, tab[i]);
	
			if (checkFullGrid(g2)){
				affiche(solution);

			}
			
			else solveur(g2, n, solution, profondeur+1);
			depiler(solution);
}
}

void affiche(Pile *pile)
{
    if (pile == NULL)
    {

        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {	

        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\nfin");
}

void empiler(Pile *pile, char nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if (pile == NULL || nouveau == NULL)
    {
      
       exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
  
}


int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
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
	Grid * g;
	g = initGridFromFile("../grilles/grilleTest.txt");
	Grid *g2=createGrid2(g);
	showGrid(g2);

	Pile * p;
	p = malloc(sizeof(Pile));

	p->premier =NULL;

	solveur(g,10,p,0);

	return 1;
}