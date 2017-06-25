#include "structs.h"

#ifndef MENU_H_
#define MENU_H_

extern Game game;
extern Sprites sprite[MAX_SPRITES];
extern MenuControl input;

void menuScene();
void drawMenu();
void doMenu();
void drawMainMenu();
void setBackground();
MenuItem createMenuItem();
void initMenuItems();


MenuItem menuItem[3];
int menuIndex, loopMenuScene;
Entity background;

#endif /* MENU_H_ */