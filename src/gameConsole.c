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
#include "getKey.c"

Grid *Grd=NULL;

void  main(){
	printf("ColorFlood\n");
	unsigned int side,limit,reponse;
	reponse = 1;
	while(reponse==1){
		system("clear"); /*clear for linux / cls for windows*/
		printf("Veuillez saisir la taille de la grille et le nombre de coup (format : side <espace> limite): ");
		fflush(stdin);
		scanf("%d %d",&side,&limit);
		printf("\n");
		Grd=initGridRandom(side,6);
			
		bool end=false;
		int end_condition=0;
		int status;
		char c;
		unsigned int move=1; //le nombre de coup joués
		
		if(checkFullGrid(Grd)){ /*check victory condition in case of unitary grid*/
				end=true;
				end_condition=1;
			}
	
		while(!end){
			showGrid(Grd);
			do{
				status = 1;
				fflush(stdin);
				printf("\nCoup %d/%d - Couleur? [R,V,B,J,O,M]\n",move,limit);
				c=getKey();
				switch(c){
					case 'R': colorFlood2(Grd,c);move++;status=0;break;
					case 'V': colorFlood2(Grd,c);move++;status=0;break;
					case 'B': colorFlood2(Grd,c);move++;status=0;break;
					case 'J': colorFlood2(Grd,c);move++;status=0;break;
					case 'O': colorFlood2(Grd,c);move++;status=0;break;
					case 'M': colorFlood2(Grd,c);move++;status=0;break;
				}
				if(status)printf("!-- La couleur doit etre dans [R,V,B,J,O,M] --!");
			}while(status);
			
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
			printf("Tu as perdu :(\n");
		}
		else{
			system("clear"); /*clear for linux / cls for windows*/
			printf("Tu as gagne :)\n");
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
