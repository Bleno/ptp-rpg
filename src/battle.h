#include "character.h"
#ifndef  BATTLE_H_
#define  BATTLE_H_

void battle(struct character mainChar);

void chooseEnemy( struct character * enemy);

void chooseWeapon(struct character * player, struct character * enemy);

void duel(struct character * player, struct character * enemy);

void rules(int victory, struct character * mainChar, struct character * enemy);

void empate(struct character * mainChar, struct character * enemy);

void finalRules(struct character * mainChar, struct character * enemy);

#endif /* BATTLE_H_ */