#include "defs.h"


typedef struct Label
{
	int x, y;
	int r, g, b;
	SDL_Surface *text;
} Label;


typedef struct Game
{
	int score;
	SDL_Surface *screen;
	TTF_Font *font;
} Game;

typedef struct Sprites
{
	SDL_Surface *image;
} Sprites;

typedef struct Entity
{
	int x, y;
	SDL_Surface *sprite;
} Entity;

typedef struct MenuControl
{
	int up, down, enter;
} MenuControl;


typedef struct MenuItem
{
	int index;
	Entity entity;
} MenuItem;


/* Charazou
 " 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n"
*/
typedef struct Player {
	int total_hp, hp, damage;
	int classe, weapon, sequence;
	char  *name;
	Entity entity;
} Player;
