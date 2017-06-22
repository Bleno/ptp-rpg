#include "menu.h"

extern void chooseInterface(void);
extern void drawScore(void);

void menu(){
	int opt = 0;
	int loop = 1;
	while( loop == 1)
	{
		printf("Digite uma opcao\n");
		printf(" 1 - Novo Jogo\n 2 - Records\n 3 - Sair\n");
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  fflush(stdin);
			  choose();
			  break;
			case 2:
			  fflush(stdin);
			  score();
			  break;
			case 3:
			  fflush(stdin);
			  printf("Goodbye!\n");
			  exit(0);
			  break;
			default:
			  fflush(stdin);
			  printf("opcao invalida!\n");
		}
	}

}


int drawMenu(){

	SDL_Surface *b1 = NULL, *b2 = NULL, *b3 = NULL;
	SDL_Rect posB1, posB2, posB3;
	SDL_Event event;
	int compteur = 1, compteur2 = 1, i = 1;

	/* Centralizar o menu */
	posB1.x = (screen->w / 2) - 55;
	posB1.y = screen->h / 2;

	posB2.x = (screen->w / 2) - 43;
	posB2.y =  (screen->h / 2) + 40;

	posB3.x = (screen->w / 2) - 20 ;
	posB3.y = (screen->h / 2) + 80;

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
									compteur2 = 0;
									chooseInterface();
									break;
								case 2:
									drawScore();
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

	SDL_FreeSurface(b1);
	SDL_FreeSurface(b2);
	SDL_FreeSurface(b3);

	return 0;

}
