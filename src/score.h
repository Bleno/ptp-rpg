#include "structs.h"
#ifndef  SCORE_H_
#define  SCORE_H_

extern Game game;

void score();

void countScore(int *score, int mainCharClass, int enemyClass);

void storeScore(int score);

void initScene();

void getScore();

int* criaArray(int len);

#endif /* SCORE_H_ */