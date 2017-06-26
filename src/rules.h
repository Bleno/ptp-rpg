#include "structs.h"
#include "util.h"

extern Game game;

void duel(Player *player, Player *enemy);
void rules(int victory, Player *player, Player *enemy);
void empate(Player  *player, Player *enemy);
void finalRules(Player  *player, Player *enemy);

int calculatePercente(int total, int atual);