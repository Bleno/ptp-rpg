#include "defs.h"
#include "character.h"


struct character create_character(int type){
	struct character mainChar;
	switch(type){
		case 1:
			mainChar.hp = WARRIOR_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			mainChar.classe = 1;
			mainChar.sequence = 0;
			break;
		case 2:
			mainChar.hp = ARROW_HP;
			mainChar.damage = ARROW_DAMAGE;
			mainChar.classe = 2;
			break;
		case 3:
			mainChar.hp = WIZARD_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			mainChar.classe = 3;
			break;
		default:
		    mainChar.hp = 500;
			mainChar.damage = 100;
		
	}
	return  mainChar;
}