#include "defs.h"

extern SDL_Surface *screen, *backgroundImage;

static void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

SDL_Surface *createSurface(int width, int height);

void drawHitBox(int startX, int startY, int w, int h);

void delay(unsigned int frameLimit);