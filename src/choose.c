#include "choose.h"
#include "character.h"
#include "battle.h"
#include "font.h"



extern void drawImage(SDL_Surface *, int, int);
extern void delay(unsigned int );

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




void chooseInterface(){
	unsigned int frameLimit = SDL_GetTicks() + 16;
	SDL_Surface *opt1 = NULL, *opt2 = NULL, *opt3 = NULL, *s = NULL;
	SDL_Rect posOpt1, posOpt2, posOpt3, bg, select;
	TTF_Font *font = NULL;
	SDL_Event e;
	int goBack = 1, classSelected = 1;

	bg.x = 0;
	bg.y = 0;

	posOpt1.y = (screen->h / 2) - 126;
	posOpt1.x = 0;

	posOpt2.y = (screen->h / 2) - 126; 
	posOpt2.x = (screen->w / 2) - 87;

	posOpt3.y = (screen->h / 2) - 126;
	posOpt3.x = screen->w - 175;

	select.x = posOpt1.x;
	select.y = posOpt1.y;
	
	while(goBack != 0)
	{

	backgroundImage = IMG_Load("gfx/wall.jpg");


	SDL_BlitSurface(backgroundImage, NULL, screen, &bg);



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
							drawImage2(s, posOpt3.x, posOpt3.y);
						}else if(classSelected == 2){
							classSelected = 1;
							select.x = posOpt1.x;
							select.y = posOpt1.y;
							drawImage2(s, posOpt1.x, posOpt1.y); 
						}else{
							classSelected = 2;
							select.x = posOpt2.x;
							select.y = posOpt2.y;
							drawImage2(s, posOpt2.x, posOpt2.y);
						}
						break;
						
					case SDLK_RIGHT:
						if(classSelected == 3){
							classSelected = 1;
							select.x = posOpt1.x;
							select.y = posOpt1.y;
							drawImage2(s, posOpt1.x, posOpt1.y);
						}else if(classSelected == 1){
							classSelected = 2;
							select.x = posOpt2.x;
							select.y = posOpt2.y;
							drawImage2(s, posOpt2.x, posOpt2.y);
						}else{
							classSelected = 3;
							select.x = posOpt3.x;
							select.y = posOpt3.y;
							drawImage2(s, posOpt3.x, posOpt3.y);

						}
						break;
					case SDLK_RETURN:
						battleInterface(classSelected);
					
					case SDLK_ESCAPE:
						goBack = 0;
						break;
					
					default:
					break;
				}
				break;
		}

		
		SDL_Flip(screen);
		
		printf("%d\n", classSelected);
		SDL_FillRect(screen,NULL,0x000000);

		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}

	SDL_FreeSurface(opt1);
	SDL_FreeSurface(opt2);
	SDL_FreeSurface(opt3);
	SDL_FreeSurface(s);

}


void drawImage2(SDL_Surface *s, int x, int y)
{
	SDL_Surface *tmp = NULL;
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	tmp = IMG_Load("gfx/select.png");
	SDL_BlitSurface(tmp, NULL, screen, &pos);
	s = tmp;
	SDL_FreeSurface(tmp);
	SDL_Flip(screen);
	
}