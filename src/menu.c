#include "menu.h"


extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);
extern void drawScore(void);
extern void delay(unsigned int);
extern void getInput(void);
extern void chooseInterface();

MenuItem createMenuItem(){
	MenuItem item;
	return item;
}

void initMenuItems()
{
	int i;

	printf("initMenuItems\n");
	for (i = 0; i < 3; i++)
	{
		menuItem[i] = createMenuItem();
		menuItem[i].index = i;
	}
}


void initMainMenu()
{
	initMenuItems();
	menuIndex = 0;
	printf("initMainMenu\n");

	printf("init background\n");
	setBackground();

	menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1_SELECTED);
	menuItem[1].entity.sprite = getSprite(MAIN_MENU_ITEM2);
	menuItem[2].entity.sprite = getSprite(MAIN_MENU_ITEM3);
	printf("imagens\n");
	/* Centralizar o menu */
	menuItem[0].entity.x = (game.screen->w / 2) - 55;
	menuItem[0].entity.y = game.screen->h / 2;

	menuItem[1].entity.x = (game.screen->w / 2) - 43;
	menuItem[1].entity.y =  (game.screen->h / 2) + 40;

	menuItem[2].entity.x = (game.screen->w / 2) - 20 ;
	menuItem[2].entity.y = (game.screen->h / 2) + 80;
	printf("fim initMainMenu\n");
}


void doMenu()
{
	SDL_Event e;

	while(SDL_PollEvent(&e)){

		switch(e.type){

			case SDL_KEYDOWN:

				switch (e.key.keysym.sym)
				{
					case SDLK_UP:

						switch(menuIndex)
						{
							case 0:
								menuIndex = 2;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM3_SELECTED);
								menuItem[1].entity.sprite = getSprite(MAIN_MENU_ITEM2);
								menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1);
								break;
							case 1:
								menuIndex = 0;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM1_SELECTED);
								menuItem[1].entity.sprite = getSprite(MAIN_MENU_ITEM2);
								menuItem[2].entity.sprite = getSprite(MAIN_MENU_ITEM3);
								break;
							case 2:
								menuIndex = 1;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM2_SELECTED);
								menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1);
								menuItem[2].entity.sprite = getSprite(MAIN_MENU_ITEM3);
								break;
							default:
								break;
						}
						break;
					case SDLK_DOWN:
						switch(menuIndex)
						{
							case 0:
								menuIndex = 1;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM2_SELECTED);
								menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1);
								menuItem[2].entity.sprite = getSprite(MAIN_MENU_ITEM3);
								break;
							case 1:
								menuIndex = 2;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM3_SELECTED);
								menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1);
								menuItem[1].entity.sprite = getSprite(MAIN_MENU_ITEM2);
								break;
							case 2:
								menuIndex = 0;
								menuItem[menuIndex].entity.sprite = getSprite(MAIN_MENU_ITEM1_SELECTED);
								menuItem[1].entity.sprite = getSprite(MAIN_MENU_ITEM2);
								menuItem[2].entity.sprite = getSprite(MAIN_MENU_ITEM3);
								break;
							default:
								break;
						}
						break;
					case SDLK_RETURN:
						loopMenuScene = 0;
						break;
					default:
						break;
				}
			default:
				break;
		}
	}

}

void drawMenu()
{
	SDL_FillRect(game.screen, NULL, 0);

	drawMainMenu();

	SDL_Flip(game.screen);

	SDL_Delay(130);
}

void drawMainMenu()
{
	int i;

	drawImage(background.sprite, background.x, background.y);

	for (i = 0; i < 3; i++)
	{
		drawImage(menuItem[i].entity.sprite, menuItem[i].entity.x, menuItem[i].entity.y);
	}
}

void setBackground(){
	background.sprite = getSprite(BACKGROUND);
	background.x = 0;
	background.y = 0;
}

void menuScene(){
  unsigned int frameLimit = SDL_GetTicks() + 16;
  loopMenuScene = 1;

  /* init position menu */

  initMainMenu();

  
  while (loopMenuScene == 1)
  {

    doMenu();

    drawMenu();
    
    delay(frameLimit);

    frameLimit = SDL_GetTicks() + 16;

  }

  switch(menuIndex)
  {
  	case 0:
  		printf("Novo jogo\n");
  		chooseInterface();
  		break;
  	case 1:
  	    printf("scoreScene\n");
  	    drawScore();
  	    break;
  	case 2:
  		exit(0);
  }
}