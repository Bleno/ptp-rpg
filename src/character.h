#include "structs.h"
#ifndef CHARACTER_H_
#define CHARACTER_H_ 


/*
  WARRIOR
 */
#define WARRIOR_HP 700
#define WARRIOR_DAMAGE 100

/*
  ARROW
 */
#define ARROW_HP 600
#define ARROW_DAMAGE 100

/*
  WIZARD
 */
#define WIZARD_HP 500
#define WIZARD_DAMAGE 100



/* Charazou
 " 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n"
*/
struct character {
	float total_hp;
	float hp;
	float damage;
	int classe;
	int weapon;
	int sequence;
	char  * name;
	SDL_Surface * sprite;
	SDL_Rect * position;
};


struct character create_character(int t );

extern const char* chars[3];

#endif /* CHARACTER_H_ */