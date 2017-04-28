#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
	if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
	{
		fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//Nommage de la fenetre
	SDL_WM_SetCaption("ColorFlood OCalm",NULL);

	// Coloration de la surface ecran en blanc
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
         
	// Creation d'un rectangle
	SDL_Rect position;
	SDL_Surface *rectangle = NULL;
	rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
	position.x = 0; // Les coordonnées de la surface seront (0, 0)
	position.y = 0;

	// Remplissage du rectangle ne rouge
	SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 0, 0)); 
	SDL_BlitSurface(rectangle, NULL, ecran, &position);

	// Rafraichissement de la fenetre
	SDL_Flip(ecran); 

	pause(); // Mise en pause du programme
	SDL_Quit(); // Arrêt de la SDL

	return EXIT_SUCCESS; // Fermeture du programme
}

void pause()
{
	int continuer = 1;
	SDL_Event event;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}
}
