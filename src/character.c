#include "defs.h"
#include "character.h"
#include <stdio.h>


struct character create_character(int type){
	struct character mainChar;
	switch(type){
		case 1:
			mainChar.total_hp = WARRIOR_HP;
			mainChar.hp = WARRIOR_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			mainChar.classe = 1;
			mainChar.sequence = 0;
			break;
		case 2:
			mainChar.total_hp = ARROW_HP;
			mainChar.hp = ARROW_HP;
			mainChar.damage = ARROW_DAMAGE;
			mainChar.classe = 2;
			break;
		case 3:
			mainChar.total_hp = WIZARD_HP;
			mainChar.hp = WIZARD_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			mainChar.classe = 3;
			break;
		default:
			mainChar.total_hp = WIZARD_HP;
			mainChar.hp = WIZARD_HP;
			mainChar.damage = WARRIOR_DAMAGE;
			mainChar.classe = 3;
		
	}
	return  mainChar;
}

const char* chars[3] = {"Guerreiro", "Arqueiro", "Mago"};

// char* chars(){
// 	char* persons[] = {"Guerreiro", "Arqueiro", "Mago"};
// 	return persons;
// }