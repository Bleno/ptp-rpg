#include "structs.h"

extern Game game;
TTF_Font *loadFont(char *name, int size);
void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY);
void closeFont(TTF_Font *font);