#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "grid.c"

void pauseJeu();

int main()
{
	unsigned int size;
	fflush(stdin);
	printf("Saisir la taille de la grille");
	scanf("%d",&size);
	printf("\n");
	
	int squareSize=32;
	Grid *grd;
	grd=initGridRandom(size);

	SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(squareSize*size,squareSize*size+100, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
	if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
	{
		fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//Nommage de la fenetre
	SDL_WM_SetCaption("ColorFlood OCalm",NULL);

	// Coloration de la surface ecran en blanc
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

	// Creation des rectangles
	SDL_Rect position;
	SDL_Surface *rectangle[size][size];
	int i,j;
	position.x=0;
	position.y=0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			rectangle[i][j]= SDL_CreateRGBSurface(SDL_HWSURFACE, squareSize, squareSize, 32, 0, 0, 0, 0);
			if(grd->block[i][j]=='B') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 0, 0, 255)); 
			if(grd->block[i][j]=='V') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 0, 255, 0)); 
			if(grd->block[i][j]=='R') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 255, 0, 0)); 
			if(grd->block[i][j]=='J') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 255, 255, 0)); 
			if(grd->block[i][j]=='O') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 255, 128, 0)); 
			if(grd->block[i][j]=='M') SDL_FillRect(rectangle[i][j], NULL, SDL_MapRGB(ecran->format, 255, 100, 100)); 
			SDL_BlitSurface(rectangle[i][j], NULL, ecran, &position);
			position.x=position.x + squareSize;
		}
		position.x=0;
		position.y=position.y+squareSize;
	}

	// Rafraichissement de la fenetre
	SDL_Flip(ecran); 

	pauseJeu(); // Mise en pause du programme
	SDL_Quit(); // Arrêt de la SDL

	return EXIT_SUCCESS; // Fermeture du programme
}

void pauseJeu()
{
	int continuer = 1;
	SDL_Event event;
	SDL_Rect mousePosition;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONUP:
			//	if (event.button.button == SDL_BUTTON_RIGHT)
			//		continuer = 0;
				/* On arrête le programme si on a fait un clic droit */
			//	mousePosition.x=event.button.x;
			//	mousePosition.y=event.button.y;
				break;

		}
	}
}
