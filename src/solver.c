#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "grid.h"
#include "solver.h"


solveur(Grid *g, int n, Pile solution, int profondeur) {
		int i;
		Grid *g2;


			// déclarations des variables locales i, g2, ...
			for (i=0; i<6; i=i+1) { // pour toutes les couleurs possibles
			solution = empiler(solution,i);
			char tab[6] = {'R','V','B','J','O','M'};
			 
			g2 = colorFlood2(g, tab[i]);
			if (terminaison(g2))
			uneSolutionTrouvee(solution);
			else solveur(g2, n, solution, profondeur+1);
			depiler(&solution);
}
}


void empiler(Pile *pile, int nvNombre)
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