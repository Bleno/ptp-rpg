#include "init.h"

void init(char *title)
{
	/* Inicia SDL Video */
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Nao foi possivel iniciar SDL: %s\n", SDL_GetError());
		
		exit(1);
	}
	
	/* Abre uma tela 800 x 600 */
	
	screen = SDL_SetVideoMode(800, 600, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	
	if (screen == NULL)
	{
		printf("Nao foi possivel abrir a tela 800 x 600: %s\n", SDL_GetError());

		exit(1);
	}
	
	/* Set o title pra tela */
	
	SDL_WM_SetCaption(title, NULL);
}

void cleanup()
{
	/* libera image */
	
	if (backgroundImage != NULL)
	{
		SDL_FreeSurface(backgroundImage);
	}
	
	/* Shut down SDL */
	
	SDL_Quit();
}
