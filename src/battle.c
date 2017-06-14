#include <stdio.h>
#include <time.h>
#include "defs.h"
#include "character.h"
#include "battle.h"
#include "util.h"


void battle(struct character mainChar){
	struct character enemy;
	int weapon, weaponEnemy;
	chooseEnemy( &enemy );
	while(enemy.hp > 0 && mainChar.hp > 0){
		printf("Seu inimigo:\n HP: %0.f,\n Damage: %0.f\n", enemy.hp, enemy.damage );
		printf("Você:\n HP: %0.f,\n Damage: %0.f\n", mainChar.hp, mainChar.damage );
		chooseWeapon(&weapon, &weaponEnemy);
		duel(&weapon, &weaponEnemy, &mainChar, &enemy);
		//enemy.hp = 0;
	}

}


void duel(int * weapon, int * weaponEnemy, struct character * mainChar, struct character * enemy){
 //1 pedra
 //2 tesoura
 //3 papel
 printf("Duello\n");
 int w = *weapon;
 int e = *weaponEnemy;
 if(w == e){
 	printf("Empate\n");
 }else{
 	if(w == 3 && e == 1){
 		printf("Você ganhou!\n");
 		enemy->hp = enemy->hp - mainChar->damage;
 		rules(1, mainChar, enemy);
 	}else if( w == 1 && e ==  2){
 		printf("Você ganhou!\n");
 		rules(1, mainChar, enemy);
 	}else if(w == 2 && e == 3){
 		printf("Você ganhou!\n");
 		enemy->hp = enemy->hp - mainChar->damage;
 	}else{
 		printf("Você perdeu!\n");
 		rules(0, mainChar, enemy);
 	}
 }
 
}


void rules(int victory, struct character * mainChar, struct character * enemy){
   //victory 0 - enemy, 1 mainChar
   if(victory == 1){
   		if( mainChar->classe == 1){// vitoria do guerreiro
   			if( mainChar->sequence == 1 ){
   				enemy->hp = enemy->hp - (mainChar->damage * 2);
   			}else{
   				enemy->hp = enemy->hp - mainChar->damage;
   				mainChar->sequence = 1;
   			}
   		}
   }else{
   	    mainChar->hp = mainChar->hp - enemy->damage;
   }
}


void chooseWeapon(int * weapon, int * weaponEnemy){
	int w = 0;
	*weaponEnemy = randInt(3);
	while(w > 3 || w <= 0){
		printf("Escolha sua arma! 1- Pedra 2 - Tesoura- 3 Papel:\n");
		scanf("%d", &w);
		if(w > 3 || w <= 0){
		  printf("Opção inválida\n");
		}
	}
	*weapon = w;
}

void chooseEnemy( struct character * enemy ){
	//srand( time( NULL ) );
	int r = randInt(3);
	printf("%d\n", r);
	*enemy = ( struct character ) create_character(r);
}