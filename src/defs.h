#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

/*
  WARRIOR
 */
#define WARRIOR_HP 700
#define WARRIOR_DAMAGE 100

/*
  ARROW
 */
#define ARROW_HP 600
#define ARROW_DAMAGE 100

/*
  WIZARD
 */
#define WIZARD_HP 500
#define WIZARD_DAMAGE 100


#define MAX_BATTLES 10

/* GAME INTEFACE DEFINITIONS */

#define MAX_SPRITES 10

enum
{
	BACKGROUND,
	MAIN_MENU_ITEM1,
	MAIN_MENU_ITEM2,
	MAIN_MENU_ITEM3,
	MAIN_MENU_ITEM1_SELECTED,
	MAIN_MENU_ITEM2_SELECTED,
	MAIN_MENU_ITEM3_SELECTED
};