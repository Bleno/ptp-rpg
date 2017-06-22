#include "defs.h"
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
void createScene(SDL_Surface *bg, int *score);
void startPlayers();
void updateLife(struct character *player, struct character *enemy);
float calculatePercente(float total, float atual);
SDL_Surface *barLife(float percente);

int controller();
void chooseWeaponInterface(struct character * player, struct character * enemy);

#endif /* BATTLE_H_ */