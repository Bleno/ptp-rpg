#include "menu.h"


extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);

MenuItem createMenuItem(){
	MenuItem item;
	return item;
}

void initMenuItems()
{
	int i;
	Entity entity;
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

	menuItem[0].entity.sprite = getSprite(MAIN_MENU_ITEM1_SELECTED);
	printf("menu 1\n");
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
	if(input.up == 1){
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
	}else if(input.down == 1){
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
	}
}

void drawMenu()
{
	SDL_FillRect(game.screen, NULL, 0);

	drawMainMenu();

	SDL_Flip(game.screen);

	SDL_Delay(80);
}

void drawMainMenu()
{
	int i;

	for (i = 0; i < 3; i++)
	{
		drawImage(menuItem[i].entity.sprite, menuItem[i].entity.x, menuItem[i].entity.y);
	}
}