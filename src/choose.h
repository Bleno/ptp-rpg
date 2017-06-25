#include "structs.h"
#ifndef  CHOOSE_H_
#define  CHOOSE_H_

extern Game game;
extern Sprites sprite[MAX_SPRITES];

MenuItem menuItem[3];
Entity selectItem, background;
int loopChooseScene, menuIndex;

void choose();
void drawChooseMenu();
void doMenu();
void setChooseBackground();
void initChooseMenuItems();
void doChooseMenu();
void drawChooseMenu();

#endif /* CHOOSE_H_ */