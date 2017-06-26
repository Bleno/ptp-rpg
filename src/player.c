#include "player.h"


Player createPlayer(int type){
	Player player;
	switch(type){
		case 0:
			player.total_hp = WARRIOR_HP;
			player.hp = WARRIOR_HP;
			player.damage = WARRIOR_DAMAGE;
			player.classe = 1;
			player.sequence = 0;
			break;
		case 1:
			player.total_hp = ARROW_HP;
			player.hp = ARROW_HP;
			player.damage = ARROW_DAMAGE;
			player.classe = 2;
			break;
		case 2:
			player.total_hp = WIZARD_HP;
			player.hp = WIZARD_HP;
			player.damage = WARRIOR_DAMAGE;
			player.classe = 3;
			break;
		default:
			player.total_hp = WIZARD_HP;
			player.hp = WIZARD_HP;
			player.damage = WARRIOR_DAMAGE;
			player.classe = 3;
		
	}
	return  player;
}

const char* chars[3] = {"Guerreiro", "Arqueiro", "Mago"};
