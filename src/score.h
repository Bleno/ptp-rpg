#include "defs.h"
#ifndef  SCORE_H_
#define  SCORE_H_

extern SDL_Surface *screen, *backgroundImage;

void score();

void countScore(int *score, int mainCharClass, int enemyClass);

void storeScore(int score);

void initScene();

void getScore();

#endif /* SCORE_H_ */