#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void Confirm(SDL_Surface *screen);
void Confirm2(SDL_Surface *screen);


int main(int argc, char *argv[]){
	SDL_Surface *screen = NULL, *fond = NULL, *b1 = NULL, *b2 = NULL, *b3 = NULL;
	SDL_Rect  posFond, posB1, posB2, posB3;
	SDL_Event event;
	int compteur = 1, compteur2 = 1, i = 1;

	SDL_Init(SDL_INIT_VIDEO);
	putenv("SDL_VIDEO_WINDOW_POS=center");

	screen = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(screen == NULL){
		printf("Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("teste menu", NULL);

	/*posFond.x = 0;
	posFond.y = 0; */

	posB1.x = (screen->w / 2) - 20;
	posB1.y = screen->h / 2;

	posB2.x = (screen->w / 2) - 10;
	posB2.y =  (screen->h / 2) + 40;

	posB3.x = (screen->w / 2) - 5 ;
	posB3.y = (screen->h / 2) + 80;

	/*fond = IMG_Load("gfx/dexter.jpg"); */

	while( compteur != 0){

		switch(i)
		{
			case 1:
				SDL_FreeSurface(b1);
				SDL_FreeSurface(b2);
				SDL_FreeSurface(b3);
				b1 = IMG_Load("gfx/btn1_selected.png"); /*//img_selected */
				b2 = IMG_Load("gfx/btn2.png");
				b3 = IMG_Load("gfx/btn3.png");
				/*SDL_BlitSurface(fond, NULL, screen, &posFond);*/
				SDL_BlitSurface(b1, NULL, screen, &posB1);
				SDL_BlitSurface(b2, NULL, screen, &posB2);
				SDL_BlitSurface(b3, NULL, screen, &posB3);
				SDL_Flip(screen);
				printf("btn1\n");
				break;
			case 2:
				SDL_FreeSurface(b1);
				SDL_FreeSurface(b2);
				SDL_FreeSurface(b3);
				b1 = IMG_Load("gfx/btn1.png");
				b2 = IMG_Load("gfx/btn2_selected.png"); /*//img_selected */
				b3 = IMG_Load("gfx/btn3.png");
				/*SDL_BlitSurface(fond, NULL, screen, &posFond);*/
				SDL_BlitSurface(b1, NULL, screen, &posB1);
				SDL_BlitSurface(b2, NULL, screen, &posB2);
				SDL_BlitSurface(b3, NULL, screen, &posB3);
				SDL_Flip(screen);
				printf("btn2\n");

				break;
			case 3:
				SDL_FreeSurface(b1);
				SDL_FreeSurface(b2);
				SDL_FreeSurface(b3);
				b1 = IMG_Load("gfx/btn1.png");
				b2 = IMG_Load("gfx/btn2.png");
				b3 = IMG_Load("gfx/btn3_selected.png"); /*//img_selected */
				/*SDL_BlitSurface(fond, NULL, screen, &posFond);*/
				SDL_BlitSurface(b1, NULL, screen, &posB1);
				SDL_BlitSurface(b2, NULL, screen, &posB2);
				SDL_BlitSurface(b3, NULL, screen, &posB3);
				SDL_Flip(screen);
				printf("btn3\n");

				break;

		}

		compteur2 = 1;

		while(compteur2 != 0)
		{
			SDL_WaitEvent(&event);

			switch(event.type)
			{
				case SDL_QUIT:
					compteur = 0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_UP:
							switch(i)
							{
								case 1:
									i = 3;
									break;
								case 2:
									i = 1;
									break;
								case 3:
									i = 2;
									break;
							}
							break;
						case SDLK_DOWN:
							switch(i)
							{
								case 1:
									i = 2;
									break;
								case 2:
									i = 3;
									break;
								case 3:
									i = 1;
									break;
							}
							break;
						case SDLK_ESCAPE:
							compteur = 0;
							break;
						case SDLK_RETURN:
							switch(i)
							{
								case 1:
									/*SDL_FreeSurface(fond);*/
									SDL_FreeSurface(b1);
									SDL_FreeSurface(b2);
									SDL_FreeSurface(b3);

									Confirm2(screen);
									SDL_Flip(screen);
									break;
								case 2:
									Confirm(screen);
									break;
								case 3:
									compteur = 0;
									break;
							}
							break;
					}
					break;
			}

			compteur2 = 0;
		}
	}

	/*SDL_FreeSurface(fond);*/
	SDL_FreeSurface(b1);
	SDL_FreeSurface(b2);
	SDL_FreeSurface(b3);

	SDL_Quit();

	return EXIT_SUCCESS;

}


void Confirm(SDL_Surface *screen)
{
	SDL_Surface *fond = NULL;
	SDL_Rect pos;
	SDL_Event e;
	int compteur = 1;
	fond = IMG_Load("gfx/choose.png");

	pos.x = 0;
	pos.y = 0;

	SDL_BlitSurface(fond, NULL, screen, &pos);
	SDL_Flip(screen);

	while(compteur != 0)
	{
		SDL_WaitEvent(&e);

		if(e.key.keysym.sym == SDLK_ESCAPE)
		{
			compteur = 0;
		}
	}

	SDL_FreeSurface(fond);
}


void Confirm2(SDL_Surface *screen)
{
	SDL_Surface *fond = NULL;
	SDL_Rect pos;
	SDL_Event e;
	int compteur = 1;
	fond = IMG_Load("gfx/bg2.jpg");

	pos.x = 0;
	pos.y = 0;

	SDL_BlitSurface(fond, NULL, screen, &pos);
	SDL_Flip(screen);

	while(compteur != 0)
	{
		SDL_WaitEvent(&e);

		if(e.key.keysym.sym == SDLK_ESCAPE)
		{
			compteur = 0;
		}
	}

	SDL_FreeSurface(fond);
}