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
#include <stdio.h>

//#include "gameConsole.h"
#include "grid.h"
#include "getKey.h"

Grid *Grd=NULL;

void showGrid(Grid* grd){
	unsigned int i,j;
	for(i=0;i<grd->size;i++){
		for(j=0;j<grd->size;j++){
			printf("%c ",grd->block[i][j]);
		}
		printf("\n");
	}
}

int  main(){
	char reponse = '1';
	int limit,side;
	int status=1;
	while(reponse=='1'){

		system("clear"); /*clear for linux / cls for windows*/
		/*User input for side and limit*/
		do{	
			printf("ColorFlood O'Calm\n\n");
			status=1;
			printf("Veuillez saisir la taille de la grille et le nombre de coup (format : side <espace> limite): ");
			scanf("%d %d",&side,&limit); printf("\n");
			fflush(stdin);

			if(side<3 || side>24 ){
				printf("!-- Taille comprise entre 3 et 24 uniquement !--\n");
			}else if (limit<6){
				printf("!-- Le nombre de coup doit etre supérieur ou egal à 6 !--\n");
			}else {
				status=0;
			}
		}while(status);
		system("clear");

		if(Grd!=NULL){ /* on détruit la grille si elle a déjà été initialisée avant */
			releaseGrid(Grd);
		}

		Grd=initGridRandom((unsigned int)side);
		bool end=false;
		int end_condition=0;
		char c;
		int move=1; //le nombre de coup joués

		//if(checkFullGrid(Grd)){ /*check victory condition in case of unitary grid*/
		//		end=true;
		//		end_condition=1;
		//	}

		while(!end){
			printf("ColorFlood O'Calm\n\n");
			showGrid(Grd);
			do{	/* user input for game*/
				status = 1;
				printf("\nCoup %d/%d - Couleur? [R,V,B,J,O,M]\n",move,limit);
				while((c=getKey()) == '\n' || c == EOF);
				switch(c){
					case 'R': colorFlood2(Grd,c);move++;status=0;break;
					case 'r': colorFlood2(Grd,c-32);move++;status=0;break;
					case 'V': colorFlood2(Grd,c);move++;status=0;break;
					case 'v': colorFlood2(Grd,c-32);move++;status=0;break;
					case 'B': colorFlood2(Grd,c);move++;status=0;break;
					case 'b': colorFlood2(Grd,c-32);move++;status=0;break;
					case 'J': colorFlood2(Grd,c);move++;status=0;break;
					case 'j': colorFlood2(Grd,c-32);move++;status=0;break;
					case 'O': colorFlood2(Grd,c);move++;status=0;break;
					case 'o': colorFlood2(Grd,c-32);move++;status=0;break;
					case 'M': colorFlood2(Grd,c);move++;status=0;break;
					case 'm': colorFlood2(Grd,c-32);move++;status=0;break;
					default : printf("!-- La couleur doit etre dans [R,V,B,J,O,M] --!");
				}
			}while(status);

			if(move>limit){  /*checks if player is out of moves*/
				end=true;
				end_condition=0;
			}

			if(checkFullGrid(Grd)){ /*checks if grid is full*/
				end=true;
				end_condition=1;
			}
			system("clear");
		}

		if(end_condition==0){
			system("clear"); /*clear for linux / cls for windows*/
			showGrid(Grd);
			printf("Tu as perdu :(\n");
		}
		else{
			system("clear"); /*clear for linux / cls for windows*/
			showGrid(Grd);
			printf("Tu as gagne :)\n");
		}
		printf("\nJouer encore?\n1.Oui\n2.Non (ou n'importe quelle touche !)\n");
		//scanf("%i",&reponse);
		/* lecture si le joueur veut rejouer*/
		while((reponse=getKey()) == '\n' || reponse== EOF );
	}
	releaseGrid(Grd);
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
