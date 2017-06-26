#include "structs.h"
#ifndef  BATTLE_H_
#define  BATTLE_H_

extern Game game;
extern Player player;

Player enemy;
int loopBattleScene, battle, relationMenu[6] = { PEDRA, TESOURA, PAPEL,  PEDRA_ENEMY, TESOURA_ENEMY,  PAPEL_ENEMY  };
int indexBattleMenu;

Entity lifeBar[2], background;
MenuItem menuWeaponItem[2];

int relationMenuEnemy[3] = { PEDRA_ENEMY, TESOURA_ENEMY, PAPEL_ENEMY  };
/*
void battle(struct character mainChar);

void chooseEnemy( struct character * enemy);

void chooseWeapon(struct character * player, struct character * enemy);

void duel(struct character * player, struct character * enemy);

void rules(int victory, struct character * mainChar, struct character * enemy);

void empate(struct character * mainChar, struct character * enemy);

void finalRules(struct character * mainChar, struct character * enemy);



void battleInterface(int classePlayer);
void startPlayers();
void updateLife(struct character *player, struct character *enemy);
float calculatePercente(float total, float atual);
SDL_Surface *barLife(float percente);

*/

void setBattleBackground();
void setLifeBar();
void setScore();
void setBattleName(int num);
void setPlayer();
void chooseEnemy();

void controlWeapon();
void setWeaponMenu();
SDL_Surface *barLife(int playerPercent);

#endif /* BATTLE_H_ */