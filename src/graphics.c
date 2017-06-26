#include "graphics.h"


SDL_Surface *loadImage(char *name)
{
	/* Load the image using SDL Image */
	
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;
	
	if (temp == NULL)
	{
		printf("Failed to load image %s\n", name);
		
		return NULL;
	}
	
	/* Make the background transparent */
	
	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, 0, 0, 0));
	
	/* Convert the image to the screen's native format */
	
	image = SDL_DisplayFormatAlpha(temp);
	
	SDL_FreeSurface(temp);
	
	if (image == NULL)
	{
		printf("Failed to convert image %s to native format\n", name);
		
		return NULL;
	}
	
	/* Return the processed image */
	
	return image;
}

void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;
	
	/* Set the blitting rectangle to the size of the src image */
	
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;
	
	/* Blit the entire image onto the screen at coordinates x and y */
	
	SDL_BlitSurface(image, NULL, game.screen, &dest);
}

void updateScreen()
{
	/* Blank the screen */
	
	/* SDL_FillRect(screen, NULL, 0); */
	
	/* Draw the image to 160, 120 */
	
	/* drawImage(backgroundImage, 0, 0); */
	
	/* Swap the image buffers */
	
	/* SDL_Flip(screen); */
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

void loadSprite(int index, char *name)
{
	/* Load the image into the next slot in the sprite bank */
	
	if (index >= MAX_SPRITES || index < 0)
	{
		printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
		
		exit(1);
	}
	
	sprite[index].image = loadImage(name);
	printf("loadSprite\n");
	
	if (sprite[index].image == NULL)
	{
		printf("saiu image null\n");
		exit(1);
	}
}

void loadAllSprites()
{
	printf("loadAllSprites\n");
	/* MAIN MENU SCENE */
	loadSprite( BACKGROUND, "gfx/arena.png");
	loadSprite( MAIN_MENU_ITEM1, "gfx/btn1.png");
	loadSprite( MAIN_MENU_ITEM2, "gfx/btn2.png");
	loadSprite( MAIN_MENU_ITEM3, "gfx/btn3.png");
	loadSprite( MAIN_MENU_ITEM1_SELECTED, "gfx/btn1_selected.png");
	loadSprite( MAIN_MENU_ITEM2_SELECTED, "gfx/btn2_selected.png");
	loadSprite( MAIN_MENU_ITEM3_SELECTED, "gfx/btn3_selected.png");

	/* CHOOSE MENU SCENE */
	loadSprite(BACKGROUND_CHOOSE_MENU, "gfx/wall.jpg");
	loadSprite(CHOOSE_MENU_ITEM1, "gfx/warrior_card.png");
	loadSprite(CHOOSE_MENU_ITEM2, "gfx/arrow_card.png");
	loadSprite(CHOOSE_MENU_ITEM3, "gfx/wizzard_card.png");
	loadSprite(CHOOSE_MENU_ITEM_SELECTED, "gfx/select.png");

	/* BATTLE SCENE */
	loadSprite(BACKGROUND_BATTLE, "gfx/rpg-battle.png");
	loadSprite(LIFE_0,  "gfx/life0.png");
	loadSprite(LIFE_10, "gfx/life10.png");
	loadSprite(LIFE_20, "gfx/life20.png");
	loadSprite(LIFE_30, "gfx/life30.png");
	loadSprite(LIFE_40, "gfx/life40.png");
	loadSprite(LIFE_50, "gfx/life50.png");
	loadSprite(LIFE_60, "gfx/life60.png");
	loadSprite(LIFE_70, "gfx/life70.png");
	loadSprite(LIFE_80, "gfx/life80.png");
	loadSprite(LIFE_90, "gfx/life90.png");
	loadSprite(LIFE_100,"gfx/life100.png");

	loadSprite(PLAYER_WIZARD, "gfx/wizard/wz0.png");
	loadSprite(PLAYER_ARCHER, "gfx/archer/a0.png");
	loadSprite(PLAYER_WARRIOR,"gfx/warrior/wr0.png");

	loadSprite(ENEMY_WIZARD, "gfx/wizard/wz0-e.png");
	loadSprite(ENEMY_ARCHER, "gfx/archer/a0-e.png");
	loadSprite(ENEMY_WARRIOR,"gfx/warrior/wr0-e.png");
}

SDL_Surface *getSprite(int index)
{
	printf("%d\n", index);
	if (index >= MAX_SPRITES || index < 0)
	{
		printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
		
		exit(1);
	}

	if(sprite[index].image == NULL){
		printf("Sprite is null\n");
	}
	
	return sprite[index].image;
}