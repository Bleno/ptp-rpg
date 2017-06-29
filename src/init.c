#include "init.h"

void init(char *title)
{
	/* Inicia SDL Video */
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Nao foi possivel iniciar SDL: %s\n", SDL_GetError());
		
		exit(1);
	}

	/* Iniciar Fontes */
	
	if (TTF_Init() < 0)
	{
		printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

		exit(1);
	}
	
	/* Tenta centralizar a tela */
	putenv("SDL_VIDEO_WINDOW_POS=center");
	
	/* Abre uma tela 600 x 480 */
	
	game.screen = SDL_SetVideoMode(600, 400, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

	
	if (game.screen == NULL)
	{
		printf("Nao foi possivel abrir a tela 800 x 600: %s\n", SDL_GetError());

		exit(1);
	}
	
	/* Set o title pra tela */
	
	SDL_WM_SetCaption(title, NULL);


	if ( !SDL_ShowCursor(SDL_DISABLE))
	{
		printf("Cursor Error: %s\n", SDL_GetError());

		exit(1);
	}

	/* cONFIGURANDO AUDIO */
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
	{
		printf("Could not open audio: %s\n", Mix_GetError());
		
		exit(1);
	}
}

void cleanup()
{
	int i;

	/* libera image */
	
	printf("Limpar imagens da memoria\n");
	
	/* Shut down SDL */

	for (i=0;i<MAX_SPRITES;i++)
	{
		if (sprite[i].image != NULL)
		{
			SDL_FreeSurface(sprite[i].image);
		}
	}

	
	SDL_Quit();
}
