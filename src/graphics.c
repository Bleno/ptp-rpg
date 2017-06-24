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
	
	image = SDL_DisplayFormat(temp);
	
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
	loadSprite( BACKGROUND, "gfx/arena.png");
	loadSprite( MAIN_MENU_ITEM1, "gfx/btn1.png");
	loadSprite( MAIN_MENU_ITEM2, "gfx/btn2.png");
	loadSprite( MAIN_MENU_ITEM3, "gfx/btn3.png");
	loadSprite( MAIN_MENU_ITEM1_SELECTED, "gfx/btn1_selected.png");
	loadSprite( MAIN_MENU_ITEM2_SELECTED, "gfx/btn2_selected.png");
	loadSprite( MAIN_MENU_ITEM3_SELECTED, "gfx/btn3_selected.png");
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