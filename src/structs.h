#include <defs.h>


typedef struct Label
{
	int x, y;
	int r, g, b;
	SDL_Surface *text;
} Label;


typedef struct Game
{
	struct character *player;
	TTF_Font *font;
} Game;