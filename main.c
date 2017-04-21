#include "grid.c"
#include <stdio.h>

void main(){
	int size=16;
	int i,j;
Grid g = initGridFromFile("grilleTest.txt");
	for (i=0;i<size;i++){
		for(j=0;j<size;j++)
			printf("%c ",g.block[i][j]);
		printf("\n");
	}
}
