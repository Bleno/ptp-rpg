#include "choose.h"
#include "character.h"
#include "battle.h"
#include "font.h"



extern void drawImage(SDL_Surface *, int, int);

void choose(){
	int opt = 0;
	struct character mainChar;
	fflush(stdout);
	printf("Escolha sua classe\n");
	printf(" 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n");
	while( opt == 0 || opt > 3)
	{
		scanf("%d", &opt);
		switch (opt){
			case 1:
			case 2:
			case 3:
			  mainChar = create_character(opt);
              mainChar.name = "Player1";
			  printf("Você escolheu %s!\n Helth: %0.f, \n Damage %0.f\n",chars[opt - 1], mainChar.hp, mainChar.damage);
			  battle(mainChar);
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}
	
	if (frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}
	
	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}


void chooseInterface(){
	unsigned int frameLimit = SDL_GetTicks() + 16;
	SDL_Surface *opt1 = NULL, *opt2 = NULL, *opt3 = NULL, *s = NULL;
	SDL_Rect posOpt1, posOpt2, posOpt3, bg, select;
	TTF_Font *font = NULL;
	SDL_Event e;
	int goBack = 1, classSelected = 1;

	backgroundImage = IMG_Load("gfx/wall.jpg");

	bg.x = 0;
	bg.y = 0;

	SDL_BlitSurface(backgroundImage, NULL, screen, &bg);

	posOpt1.y = (screen->h / 2) - 126;
	posOpt1.x = 0;

	posOpt2.y = (screen->h / 2) - 126; 
	posOpt2.x = (screen->w / 2) - 87;

	posOpt3.y = (screen->h / 2) - 126;
	posOpt3.x = screen->w - 175;

	select.x = posOpt1.x;
	select.y = posOpt1.y;


	opt1 = IMG_Load("gfx/warrior_card.png");
	opt2 = IMG_Load("gfx/arrow_card.png");
	opt3 = IMG_Load("gfx/wizzard_card.png");
	s = IMG_Load("gfx/select.png");
	SDL_BlitSurface(opt1, NULL, screen, &posOpt1);
	SDL_BlitSurface(opt2, NULL, screen, &posOpt2);
	SDL_BlitSurface(opt3, NULL, screen, &posOpt3);
	SDL_BlitSurface(s, NULL, screen, &select);
	
	font = loadFont("font/OpenSans-Regular.ttf", 16);
	drawString("Escolha sua classe", 10, 10, font, 1, 0);
	drawString("[ESC] Para voltar", 10, (screen->h - 30) , font, 1, 0);



	SDL_Flip(screen);

	while(goBack != 0)
	{
		SDL_WaitEvent(&e);

	
		switch (e.type)
		{
			
			case SDL_QUIT:
				goBack = 0;
				break;
			
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_LEFT:
						if(classSelected == 1){
							classSelected = 3;
							select.x = posOpt3.x;
							select.y = posOpt3.y;
							/*drawImage(s, posOpt3.x, posOpt3.y); */
							SDL_BlitSurface(s, &select, screen, &posOpt3);
						}else if(classSelected == 2){
							classSelected = 1;
							select.x = posOpt1.x;
							select.y = posOpt1.y;
							/*drawImage(s, posOpt1.x, posOpt1.y); */
							SDL_BlitSurface(s, &select, screen, &posOpt1);
						}else{
							classSelected = 2;
							select.x = posOpt2.x;
							select.y = posOpt2.y;
							/*drawImage(s, posOpt2.x, posOpt2.y);*/
							SDL_BlitSurface(s, &select, screen, &posOpt2);
						}
						break;
						
					case SDLK_RIGHT:
						if(classSelected == 3){
							classSelected = 1;
							drawImage(s, posOpt1.x, posOpt1.y);
						}else if(classSelected == 1){
							classSelected = 2;
							drawImage(s, posOpt2.x, posOpt2.y);
						}else{
							classSelected = 3;
							drawImage(s, posOpt3.x, posOpt3.y);

						}
						break;
					
					case SDLK_ESCAPE:
						goBack = 0;
						break;
					
					default:
					break;
				}
				break;
			
/*			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						input.left = 0;
						break;
						
					case SDLK_RIGHT:
						input.right = 0;
						break;
					
					default:
						break;
				}
				break; */
		}

		SDL_UpdateRect(screen, 0, 0, 0, 0);
		SDL_Flip(screen);
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
		printf("%d\n", classSelected);
	
	}

	SDL_FreeSurface(opt1);
	SDL_FreeSurface(opt2);
	SDL_FreeSurface(opt3);

}
