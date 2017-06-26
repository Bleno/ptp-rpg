#include "choose.h"


extern void drawImage(SDL_Surface *, int, int);
extern void delay(unsigned int );
extern MenuItem createMenuItem(void);
extern void menuScene(void);
extern SDL_Surface *getSprite(int);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern Player createPlayer(int);
extern void battleScene();


void initChooseMenuItems(){
	int i;

	for (i = 0; i < 3; i++)
	{
		menuItem[i] = createMenuItem();
		menuItem[i].index = i;
	}
}

void setChooseBackground(){
	background.sprite = getSprite(BACKGROUND);
	background.x = 0;
	background.y = 0;
}

void initChooseMenu()
{
	initChooseMenuItems();
	menuIndex = 0;

	setChooseBackground();

	menuItem[0].entity.sprite = getSprite(CHOOSE_MENU_ITEM1);
	menuItem[1].entity.sprite = getSprite(CHOOSE_MENU_ITEM2);
	menuItem[2].entity.sprite = getSprite(CHOOSE_MENU_ITEM3);
	selectItem.sprite = getSprite(CHOOSE_MENU_ITEM_SELECTED);

	menuItem[0].entity.y = (game.screen->h / 2) - 126;
	menuItem[0].entity.x = 0;

	menuItem[1].entity.y = (game.screen->h / 2) - 126; 
	menuItem[1].entity.x = (game.screen->w / 2) - 87;

	menuItem[2].entity.y = (game.screen->h / 2) - 126;
	menuItem[2].entity.x = game.screen->w - 175;

	selectItem.x = menuItem[0].entity.x;
	selectItem.y = menuItem[0].entity.y;


}

void drawChooseMenuScreen()
{
	SDL_FillRect(game.screen, NULL, 0);

	drawChooseMenu();

	SDL_Flip(game.screen);

	SDL_Delay(1);
}


void drawChooseMenu()
{
	int i;

	drawImage(background.sprite, background.x, background.y);

	drawString("Escolha sua classe", 10, 10, game.font, 1, 0);
	drawString("[ESC] Para voltar", 10, (game.screen->h - 30) , game.font, 1, 0);

	for (i = 0; i < 3; ++i)
	{
		drawImage(menuItem[i].entity.sprite, menuItem[i].entity.x, menuItem[i].entity.y);
	}

	drawImage(selectItem.sprite, selectItem.x, selectItem.y);

}


void doChooseMenu()
{
	SDL_Event e;

	while(SDL_PollEvent(&e)){

		/*SDL_WaitEvent(&e); */

	
		switch (e.type)
		{
			
			case SDL_QUIT:
				break;
			
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_LEFT:
						if(menuIndex == 0){
							menuIndex = 2;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;
						}else if(menuIndex == 2){
							menuIndex = 1;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;
						}else{
							menuIndex = 0;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;
						}
						break;
						
					case SDLK_RIGHT:
						if(menuIndex == 0){
							menuIndex = 1;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;
						}else if(menuIndex == 1){
							menuIndex = 2;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;
						}else{
							menuIndex = 0;
							selectItem.x = menuItem[menuIndex].entity.x;
							selectItem.y = menuItem[menuIndex].entity.y;

						}
						break;
					case SDLK_RETURN:
						loopChooseScene = 0;
						break;
					
					case SDLK_ESCAPE:
						menuIndex = 3;
						loopChooseScene = 0;
						break;
					
					default:
					break;
				}
				break;
		}

	}
}

void chooseScene(){
	unsigned int frameLimit = SDL_GetTicks() + 16;
	loopChooseScene = 1;

	initChooseMenu();
	
	while(loopChooseScene != 0)
	{


		doChooseMenu();

		drawChooseMenuScreen();

		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}

	printf("Escollheu opção %d\n", menuIndex);

	switch(menuIndex)
	{
		case 0:
		case 1:
		case 2:
			player = createPlayer(menuIndex);
			battleScene();
			break;
		case 3:
		    printf("escolheu sair\n");
		    menuScene();
		    break;
		default:
		    menuScene();
		    break;

	}

}
