#include "defs.h"
#include "choose.h"
#include "score.h"

#ifndef MENU_H_
#define MENU_H_
SDL_Surface *screen, *backgroundImage;
void menu();
int drawMenu();
void Confirm(SDL_Surface *screen);
void Confirm2(SDL_Surface *screen);

#endif /* MENU_H_ */