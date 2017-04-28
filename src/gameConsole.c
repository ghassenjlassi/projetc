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

int check_limit(int side, int n){
	if(n>side || n<0) return 0;
	else return 1;
}

void  main(){
	printf("ColorFlood\n");
	unsigned int side,limit,reponse;
	reponse = 1;
	while(reponse==1){
		printf("Veuillez saisir la taille de la grille et le nombre de coup (format : side <espace> limite): ");
		fflush(stdin);
		scanf("%d %d",&side,&limit);
		printf("\n");
		Grd=initGridRandom(side,6);
			
		bool end=false;
		int end_condition=0;
		unsigned int x,y;
		unsigned int move=1; //le nombre de coup joués
		
		if(checkFullGrid(Grd)){ /*check in case of unitary grid*/
				end=true;
				end_condition=1;
			}
	
		while(!end){
			showGrid(Grd);
			do{
				printf("\nCoup %d/%d : Saisir position(x (espace) y) :",move,limit);
						scanf("%d %d",&x,&y);
			}while(!check_limit(side,x) || !check_limit(side,y));
			
			colorFlood(Grd,x,y);
			move=move+1;
			
			if(move>limit){  /*checks if player is out of moves*/
				end=true; 
				end_condition=0;
			}
			if(checkFullGrid(Grd)){
				end=true;
				end_condition=1;
			}
		}
		if(end_condition==0){
			system("clear"); /*clear for linux / cls for windows*/
			printf("Tu as perdu :(");
		}
		else{
			system("clear"); /*clear for linux / cls for windows*/
			printf("Tu as gagne :)");
		}
		printf("\nJouer encore?\n1.Oui\n2.Non\n");
		scanf("%i",&reponse);
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
