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
	
	SDL_BlitSurface(image, NULL, screen, &dest);
}

void updateScreen()
{
	/* Blank the screen */
	
	SDL_FillRect(screen, NULL, 0);
	
	/* Draw the image to 160, 120 */
	
	drawImage(backgroundImage, 0, 0);
	
	/* Swap the image buffers */
	
	SDL_Flip(screen);
}


void drawHitBox(int startX, int startY, int w, int h)
{
	int x, y;
	Uint32 red, transparent;
	SDL_Rect dest;
	SDL_Surface *image;

	red = SDL_MapRGB(screen->format, 255, 0, 0);

	transparent = SDL_MapRGB(screen->format, 127, 255, 127);

	image = createSurface(w, h);

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}

	for (y=0;y<image->h;y++)
	{
		for (x=0;x<image->w;x++)
		{
			if (y == 0 || y == (image->h - 1))
			{
				putPixel(image, x, y, red);
			}

			else if (x == 0 || x == (image->w - 1))
			{
				putPixel(image, x, y, red);
			}

			else
			{
				putPixel(image, x, y, transparent);
			}
		}
	}

	if (SDL_MUSTLOCK(image))
	{
		SDL_UnlockSurface(image);
	}

	SDL_SetColorKey(image, SDL_RLEACCEL|SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 127, 255, 127));

	dest.x = startX;
	dest.y = startY;
	dest.w = image->w;
	dest.h = image->h;

	SDL_BlitSurface(image, NULL, screen, &dest);

	SDL_FreeSurface(image);
}


static void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
		case 1:
		case 8:
			*p = pixel;
		break;

		case 2:
		case 16:
			*(Uint16 *)p = pixel;
		break;

		case 3:
		case 24:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			}

			else
			{
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
		break;

		case 4:
		case 32:
			*(Uint32 *)p = pixel;
		break;
	}
}


SDL_Surface *createSurface(int width, int height)
{
	SDL_Surface *temp, *newSurface;

	temp = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, screen->format->BitsPerPixel, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, 0);

	newSurface = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	return newSurface;
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