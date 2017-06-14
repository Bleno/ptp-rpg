#include "character.h"
#ifndef  BATTLE_H_
#define  BATTLE_H_

void battle(struct character mainChar);

void chooseEnemy( struct character * enemy);

void chooseWeapon(int * weapon, int * weaponEnemy);

void duel(int * weapon, int * weaponEnemy, struct character * mainChar, struct character * enemy);

void rules(int victory, struct character * mainChar, struct character * enemy);

#endif /* BATTLE_H_ */