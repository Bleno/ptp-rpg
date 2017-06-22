#include "character.h"
#ifndef  BATTLE_H_
#define  BATTLE_H_

extern SDL_Surface *screen, *backgroundImage;

struct character *enemy, *player;


void battle(struct character mainChar);

void chooseEnemy( struct character * enemy);

void chooseWeapon(struct character * player, struct character * enemy);

void duel(struct character * player, struct character * enemy);

void rules(int victory, struct character * mainChar, struct character * enemy);

void empate(struct character * mainChar, struct character * enemy);

void finalRules(struct character * mainChar, struct character * enemy);


/* INTERFACE GRAFICA */
void battleInterface(int classePlayer);

#endif /* BATTLE_H_ */