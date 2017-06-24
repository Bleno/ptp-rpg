#include "structs.h"

#ifndef MENU_H_
#define MENU_H_

extern Game game;
extern Sprites sprite[MAX_SPRITES];
extern MenuControl input;

void menu();
void drawMenu();
void doMenu();
void drawMainMenu();


MenuItem menuItem[3];
int menuIndex;

#endif /* MENU_H_ */