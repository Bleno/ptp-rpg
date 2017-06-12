#include "defs.h"
#include "character.h"


struct character create_character(int type){
	struct character mainChar;
	switch(type){
		case 1:
			mainChar.hp = WARRIOR_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			break;
		case 2:
			mainChar.hp = ARROW_HP;
			mainChar.damage = ARROW_DAMAGE;
			break;
		case 3:
			mainChar.hp = WIZARD_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			break;
		default:
		    mainChar.hp = 500;
			mainChar.damage = 100;
		
	}
	return  mainChar;
}