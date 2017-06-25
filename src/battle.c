#include <time.h>
#include "character.h"
#include "battle.h"
#include "util.h"
#include "score.h"
#include "font.h"


extern void drawHitBox(int , int , int , int );

void battle(struct character player){
	struct character enemy;
	int mainScore = 0, i, battle = 1;
	while(battle < MAX_BATTLES  && player.hp > 0){
		chooseEnemy( &enemy );
		printf("***************************\n BATALHA: %d\n************************\n", battle );
		while(enemy.hp > 0 && player.hp > 0){
			printf("(%s) Você:\n HP: %0.f/%0.f,\n Damage: %0.f\n", player.name, player.hp, player.total_hp, player.damage );
      printf("%s:\n HP: %0.f/%0.f,\n Damage: %0.f\n", enemy.name, enemy.hp, enemy.total_hp, enemy.damage );
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
    printf("******** DUELO ***************\n");
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
   SDL_Surface *bg = NULL;
   SDL_Rect posPlayer, posEnemy;
   SDL_Event e;
   int loop = 1, score = 0, battle = 1;
   struct character player, enemy;
   
   createScene(bg, &score);
   



  posPlayer.x = 10;
  posPlayer.y = screen->h - 130;

  posEnemy.x  = screen->w - 50;
  posEnemy.y  = screen->h - 50;

   
    chooseEnemy(&enemy);
   player =  create_character(classePlayer);
   enemy.sprite = IMG_Load("gfx/a0-e.png");
   player.sprite = IMG_Load("gfx/wz0.png");
   posPlayer.x = 10;

   SDL_BlitSurface(player.sprite, NULL, screen, &posPlayer);
   SDL_BlitSurface(enemy.sprite, NULL, screen, &posEnemy);

   startPlayers();

   SDL_Flip(screen);

   while(battle < MAX_BATTLES  && player.hp > 0)
   {

      chooseWeaponInterface(&player, &enemy);

      duel(&player, &enemy);

      updateLife(&player, &enemy);

      SDL_WaitEvent(&e);

      if(e.key.keysym.sym == SDLK_ESCAPE)
      {
         battle = 11;
      }
      battle++;
      
   }

  finalRules(&player, &enemy);

   SDL_FreeSurface(bg);
}


void createEnemy(){

}


void createScene(SDL_Surface *bg, int *score){
  SDL_Rect pos;
  TTF_Font *font;
  char text[20];

  /*background */
    bg = IMG_Load("gfx/rpg-battle.jpg");
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(bg, NULL, screen, &pos);
  /*background */

  /* score */
  sprintf(text, "SCORE: %05d", *score);
  font = loadFont("font/OpenSans-Regular.ttf", 16);
  drawString(text, 10, 10, font, 1, 0);
  /* score */

  SDL_Flip(screen);

}

void startPlayers(){

  SDL_Surface *lifePlayer, *lifeEnemy;
  SDL_Rect posLife, posLifeEnemy;
  posLife.x = 10;
  posLife.y = 10;

  posLifeEnemy.x = screen->w - 110;
  posLifeEnemy.y = 10;
  lifePlayer = IMG_Load("gfx/life.png");
  lifeEnemy = IMG_Load("gfx/life.png");
  SDL_BlitSurface(lifePlayer, NULL, screen, &posLife);
  SDL_BlitSurface(lifeEnemy, NULL, screen, &posLifeEnemy);
  SDL_Flip(screen);

}

void updateLife(struct character *player, struct character *enemy){
  float playerPercent = 0, enemyPercent = 0;

  SDL_Surface *lifePlayer, *lifeEnemy;
  SDL_Rect posLife, posLifeEnemy;
  posLife.x = 10;
  posLife.y = 10;

  posLifeEnemy.x = screen->w - 110;
  posLifeEnemy.y = 10;
  enemyPercent = calculatePercente(enemy->total_hp, enemy->hp);
  playerPercent = calculatePercente(player->total_hp, player->hp);




  lifeEnemy = barLife(enemyPercent);
  lifePlayer = barLife(playerPercent);

  SDL_BlitSurface(lifePlayer, NULL, screen, &posLife);
  SDL_BlitSurface(lifeEnemy, NULL, screen, &posLifeEnemy);
  SDL_Flip(screen);

}


float calculatePercente(float total, float atual){
  float aux, resp;
  aux = atual * 100;
  resp = total / aux;
  printf("resp %f\n",resp );
  return resp;
}


SDL_Surface *barLife(float playerPercent){
  SDL_Surface *lifePlayer = NULL;
  if(playerPercent > 90){
    lifePlayer = IMG_Load("gfx/life90.png");
  }else if(playerPercent > 80 && playerPercent < 90){
    
    lifePlayer = IMG_Load("gfx/life80.png");
  }else if(playerPercent > 70 && playerPercent < 80){
    
    lifePlayer = IMG_Load("gfx/life70.png");
  }else if(playerPercent > 60 && playerPercent < 70){
    
    lifePlayer = IMG_Load("gfx/life60.png");
  }else if(playerPercent > 50 && playerPercent < 60){
    
    lifePlayer = IMG_Load("gfx/life50.png");
  }else if(playerPercent > 40 && playerPercent < 50){
    
    lifePlayer = IMG_Load("gfx/life40.png");
  }else if(playerPercent > 30 && playerPercent < 40){
    
    lifePlayer = IMG_Load("gfx/life30.png");
  }else if(playerPercent > 20 && playerPercent < 30){
    
    lifePlayer = IMG_Load("gfx/life20.png");
  }else if(playerPercent > 10 && playerPercent < 20){
    
    lifePlayer = IMG_Load("gfx/life10.png");
  }else if( playerPercent < 10){
    lifePlayer = IMG_Load("gfx/life0.png");
  }

  return lifePlayer;
}




int controller(){

  SDL_Surface *b1 = NULL, *b2 = NULL, *b3 = NULL;
  SDL_Rect posB1, posB2, posB3;
  SDL_Event event;
  int compteur = 1, compteur2 = 1, i = 1;

  /* Centralizar o menu */
  posB1.x = (screen->w / 2);
  posB1.y = (screen->h / 2) - 80;

  posB2.x = (screen->w / 2);
  posB2.y =  (screen->h / 2);

  posB3.x = (screen->w / 2);
  posB3.y = (screen->h / 2) + 80;

  while( compteur != 0){

    switch(i)
    {
      case 1:
        SDL_FreeSurface(b1);
        SDL_FreeSurface(b2);
        SDL_FreeSurface(b3);
        b1 = IMG_Load("gfx/pedra_selected.png"); /*//img_selected */
        b2 = IMG_Load("gfx/tesoura.png");
        b3 = IMG_Load("gfx/papel.png");
        SDL_BlitSurface(b1, NULL, screen, &posB1);
        SDL_BlitSurface(b2, NULL, screen, &posB2);
        SDL_BlitSurface(b3, NULL, screen, &posB3);
        SDL_Flip(screen);
        printf("btn1\n");
        break;
      case 2:
        SDL_FreeSurface(b1);
        SDL_FreeSurface(b2);
        SDL_FreeSurface(b3);
        b1 = IMG_Load("gfx/pedra.png");
        b2 = IMG_Load("gfx/tesoura_selected.png"); /*//img_selected */
        b3 = IMG_Load("gfx/papel.png");
        SDL_BlitSurface(b1, NULL, screen, &posB1);
        SDL_BlitSurface(b2, NULL, screen, &posB2);
        SDL_BlitSurface(b3, NULL, screen, &posB3);
        SDL_Flip(screen);
        printf("btn2\n");

        break;
      case 3:
        SDL_FreeSurface(b1);
        SDL_FreeSurface(b2);
        SDL_FreeSurface(b3);
        b1 = IMG_Load("gfx/pedra.png");
        b2 = IMG_Load("gfx/tesoura.png");
        b3 = IMG_Load("gfx/papel_selected.png"); /*//img_selected */
        SDL_BlitSurface(b1, NULL, screen, &posB1);
        SDL_BlitSurface(b2, NULL, screen, &posB2);
        SDL_BlitSurface(b3, NULL, screen, &posB3);
        SDL_Flip(screen);
        printf("btn3\n");

        break;

    }

    compteur2 = 1;

    while(compteur2 != 0)
    {
      SDL_WaitEvent(&event);

      switch(event.type)
      {
        case SDL_QUIT:
          compteur = 0;
          break;
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {
            case SDLK_UP:
              switch(i)
              {
                case 1:
                  i = 3;
                  break;
                case 2:
                  i = 1;
                  break;
                case 3:
                  i = 2;
                  break;
              }
              break;
            case SDLK_DOWN:
              switch(i)
              {
                case 1:
                  i = 2;
                  break;
                case 2:
                  i = 3;
                  break;
                case 3:
                  i = 1;
                  break;
              }
              break;
            case SDLK_ESCAPE:
              compteur = 0;
              break;
            case SDLK_RETURN:
              switch(i)
              {
                case 1:
                  compteur = 0;
                  printf("opcao 1\n");
                  break;
                case 2:
                  compteur = 0;
                  printf("opcao 2\n");
                  break;
                case 3:
                  compteur = 0;
                  printf("opcao 3\n");
                  break;
              }
              break;
          }
          break;
      }

      compteur2 = 0;
      printf("while\n");
    }
  }

  SDL_FreeSurface(b1);
  SDL_FreeSurface(b2);
  SDL_FreeSurface(b3);

  return i;

}



void chooseWeaponInterface(struct character * player, struct character * enemy){
  enemy->weapon = randInt(3);
  player->weapon = controller();
}


void initBattleScene(){

}

void battleScene(){
    unsigned int frameLimit = SDL_GetTicks() + 16;
    loopBattleScene = 1;

    while( loopBattleScene == 1){
      delay(frameLimit);

      frameLimit = SDL_GetTicks() + 16;
    }
}