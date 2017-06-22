#include <stdio.h>
#include <time.h>
#include "defs.h"
#include "character.h"
#include "battle.h"
#include "util.h"
#include "score.h"


void battle(struct character player){
	struct character enemy;
	int mainScore = 0, i, battle = 1;
	while(battle < MAX_BATTLES  && player.hp > 0){
		chooseEnemy( &enemy );
		printf("***************************\n BATALHA: %d\n************************\n", battle );
		while(enemy.hp > 0 && player.hp > 0){
			printf("(%s) Você:\n HP: %0.f,\n Damage: %0.f\n", player.name, player.hp, player.damage );
         printf("%s:\n HP: %0.f,\n Damage: %0.f\n", enemy.name, enemy.hp, enemy.damage );
			chooseWeapon(&player, &enemy);
			duel(&player, &enemy);
			//enemy.hp = 0;
		}
		//printf("\e[1;1H\e[2J");
		finalRules(&player, &enemy);
		if(player.hp > 0){
			countScore(&mainScore, player.classe, enemy.classe);
			printf("\n*** SCORE: %d ***\n", mainScore);
		}
		battle++;
    }
    if(player.hp <= 0){
    	printf("\n*************\n* GAME OVER *\n* SCORE: %d*\n*************\n", mainScore);
    }
}


void finalRules(struct character * player, struct character * enemy){
	float hp;
	if( player->classe == 1 && enemy->classe == 3 && player->hp > 0){// vitoria do guerreiro contra o mago
		player->sequence = 0;
		player->total_hp += 100;
		hp = player->hp + (player->hp * 0.5); // 50% de hp pela vitória
		if( hp > player->total_hp){
			player->hp = player->total_hp;
		}else{
			player->hp = hp;
		}
	}else if( player->classe == 2 && enemy->classe == 1 ){ //vitoria do arqueiro contra o guerreiro
		hp = player->hp + ( player->hp * 0.3 ); //30% de hp pela vitoria
		if(hp > player->total_hp){
			player->hp = player->total_hp;
		}else{
			player->hp = hp;
		}
	}else if( player->classe == 3 && enemy->classe == 2){ // vitoria mago contra arqueiro
		hp = player->hp + (player->hp * 0.7); // 70% pela vitoria 
		if( hp > player->total_hp ){
			player->hp = player->total_hp;
		}else{
			player->hp = hp;
		}
	}
}


void duel(struct character * player, struct character * enemy){
    //1 pedra
    //2 tesoura
    //3 papel
    printf("Duello\n");
    int w = player->weapon;
    int e = enemy->weapon;
    if(w == e){
    	printf("Empate\n");
    	empate(player, enemy);
    }else{
    	if(w == 3 && e == 1){
    		printf("Você ganhou!\n");
    		enemy->hp = enemy->hp - player->damage;
    		rules(1, player, enemy);
    	}else if( w == 1 && e ==  2){
    		printf("Você ganhou!\n");
    		rules(1, player, enemy);
    	}else if(w == 2 && e == 3){
    		printf("Você ganhou!\n");
    		enemy->hp = enemy->hp - player->damage;
    	}else{
    		printf("Você perdeu!\n");
    		rules(0, player, enemy);
    	}
    }
 
}


void empate(struct character * player, struct character * enemy){
	player->sequence = 0;
	enemy->sequence = 0;
}


void rules(int victory, struct character * player, struct character * enemy){
   //victory 0 - enemy, 1 player
   if(victory == 1){
   		if( player->classe == 1 && enemy->classe == 3){// vitoria do guerreiro contra o mago
   			if( player->sequence == 1 ){
   				enemy->hp = enemy->hp - (player->damage * 2);
   				printf("Double attack\n");
   			}else{
   				enemy->hp = enemy->hp - player->damage;
   				player->sequence = 1;
   			}
   		}else if(player->classe == 2 && enemy->classe == 1){ // vitoria do arqueiro contra o guerreiro
   			int chance = 0;
   			chance = randInt(10);
   			if( chance > 3){
   				enemy->hp = enemy->hp - player->damage;
   			}else{
   				player->hp += 200;
   				enemy->hp = enemy->hp - 200;
   			}
   		}else if(player->classe == 3 && enemy->classe == 2){ //vitoria mago contra arqueiro
   			enemy->hp -= player->damage;
   			player->total_hp += player->damage;
   		}else if(player->classe == 1 && enemy->classe == 2){ //vitoria do guerreiro contra o arqueiro
   			int chance = randInt(2);
   			if (chance == 2)
   			{
   				printf("## Attack Bloqued ##\n");
   			}else{
   				enemy->hp = enemy->hp - enemy->damage;
   			}
   		}else{
   				enemy->hp = enemy->hp - player->damage;
   				player->sequence = 0;
   		}
   }else{
   		if(player->classe == 2 && enemy->classe == 1){ // vitoria guerreiro contra arqueiro
   			int chance = randInt(2);
   			if (chance == 2)
   			{
   				printf("## Attack Bloqued ##\n");
   			}else{
   				player->hp = player->hp - enemy->damage;	
   			}
   		}else if(player->classe == 3 && enemy->classe == 2){ //vitoria arqueiro contra o mago
   			int chance = randInt(10);
   			if( chance > 4){
   				player->hp = player->hp - enemy->damage;
   			}else{
   				enemy->hp -= 100;
   				printf("## Counter-attack ##\n");
   			}
   		}else if( player->classe == 3 && enemy->classe == 1){// vitoria do guerreiro contra o mago
   			if( player->sequence == 1 ){
   				player->hp = player->hp - (enemy->damage * 2);
   				printf("Double attack\n");
   			}else{
   				player->hp = player->hp - enemy->damage;
   				enemy->sequence = 1;
   			}
		}else{
    		player->hp = player->hp - enemy->damage;
    	}
   }
}


void chooseWeapon(struct character * player, struct character * enemy){
	int w = 0;
	enemy->weapon = randInt(3);
	while(w > 3 || w <= 0){
		printf("Escolha sua arma! 1- Pedra 2 - Tesoura- 3 Papel:\n");
		scanf("%d", &w);
		if(w > 3 || w <= 0){
		  printf("Opção inválida\n");
		}
	}
	player->weapon = w;
}

void chooseEnemy( struct character * enemy ){
	srand( time( NULL ) );
	int r = randInt(3);
	printf("%d\n", r);
	*enemy = ( struct character ) create_character(r);
   enemy->name = (char *) chars[r - 1];
}



void battleInterface(int classePlayer)
{
   SDL_Surface *fond = NULL;
   SDL_Rect pos;
   SDL_Event e;
   int compteur = 1;
   fond = IMG_Load("gfx/bg2.jpg");

   pos.x = 0;
   pos.y = 0;

   SDL_BlitSurface(fond, NULL, screen, &pos);
   SDL_Flip(screen);

   while(compteur != 0)
   {
      SDL_WaitEvent(&e);

      if(e.key.keysym.sym == SDLK_ESCAPE)
      {
         compteur = 0;
      }
   }

   SDL_FreeSurface(fond);
}