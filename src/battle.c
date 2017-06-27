#include "battle.h"

extern void drawImage(SDL_Surface *, int, int);
extern void delay(unsigned int );
extern SDL_Surface *getSprite(int);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern Player createPlayer(int);
extern MenuItem createMenuItem();
extern void duel(Player *, Player *);
extern void gameOverScene();
extern int calculatePercente(int, int);
extern void finalRules(Player *, Player *);
extern void countScore(int *, int, int);


void initBattleScene(){

  setBattleBackground();

  setLifeBar();

  setScore();

  setPlayer();

  chooseEnemy();

  setWeaponMenu();
}

void setScore(){
  char text[20];

  /* score */
  sprintf(text, "SCORE: %05d", game.score);
  drawString(text, 10, 10, game.font, 1, 0);
  /* score */

  /* DISPLAY HP */
  sprintf(text, "HP: %d/%d", player.hp, player.total_hp);
  drawString(text, 20, 30, game.font, 0, 0);
  

  sprintf(text, "HP: %d/%d", enemy.hp, enemy.total_hp);
  drawString(text, game.screen->w - 100, 30, game.font, 0, 0);
  /* DISPLAY HP */


}

void setBattleName(int numBattle){
  char text[20];

  /* score */
  sprintf(text, "BATTLE: %d", numBattle);
  drawString(text, 10, 100, game.font, 1, 0);
}

void setLifeBar(){
  lifeBar[0].sprite = getSprite(LIFE_100);
  lifeBar[1].sprite = getSprite(LIFE_100);

  lifeBar[0].x = 10;
  lifeBar[0].y = 10;

  lifeBar[1].x = game.screen->w - 110;
  lifeBar[1].y = 10;
}


void setBattleBackground(){
  background.sprite = getSprite(BACKGROUND_BATTLE);
  background.x = 0;
  background.y = 0;
}

void setWeaponMenu(){
  /* Player 0
  *  Enemy 1
  */

  menuWeaponItem[0] = createMenuItem();
  menuWeaponItem[0].index = 0;
  menuWeaponItem[0].entity.sprite = getSprite( PEDRA );

  menuWeaponItem[1] = createMenuItem();
  menuWeaponItem[1].index = 1;
  menuWeaponItem[1].entity.sprite = getSprite( PEDRA_ENEMY );


  menuWeaponItem[0].entity.x = 0;
  menuWeaponItem[0].entity.y = game.screen->h / 2;

  menuWeaponItem[1].entity.x = game.screen->w - 80;
  menuWeaponItem[1].entity.y = game.screen->h / 2;

}

void chooseEnemy( ){
  int r = 0;
  r = randInt(3);
  printf("%d\n", r);
  enemy =  createPlayer(r);

  enemy.entity.x = game.screen->w - 50;
  enemy.entity.y = game.screen->h - 80;
  switch(r)
  {
    case 1:
      enemy.entity.sprite = getSprite(ENEMY_WARRIOR);
      break;
    case 2:
      enemy.entity.sprite = getSprite(ENEMY_ARCHER);
      break;
    case 3:
      enemy.entity.sprite = getSprite(ENEMY_WIZARD);
      break;
    default:
      break;
  }

}


void setPlayer(){
  /* o player já foi iniciado em outra cena.
     Agora só precisa iniciar o sprite e a posição */
  player.entity.x = 15;
  player.entity.y = game.screen->h - 80;
  switch(player.classe)
  {
    case 1:
      player.entity.sprite = getSprite(PLAYER_WARRIOR);
      break;
    case 2:
      player.entity.sprite = getSprite(PLAYER_ARCHER);
      break;
    case 3:
      player.entity.sprite = getSprite(PLAYER_WIZARD);
      break;
    default:
      break;
  }

}


void updateLife()
{
  int enemyPercent = 0, playerPercent = 0;
  
  enemyPercent = calculatePercente(enemy.total_hp, enemy.hp);
  playerPercent = calculatePercente(player.total_hp, player.hp);

  lifeBar[0].sprite = barLife(playerPercent);
  lifeBar[1].sprite = barLife(enemyPercent);
}


SDL_Surface *barLife(int playerPercent){
  SDL_Surface *lifePlayer = NULL;

  if(playerPercent == 100){
    lifePlayer = getSprite(LIFE_100);
  }
  else if(playerPercent >= 90 && playerPercent < 100){
    lifePlayer = getSprite(LIFE_90);
  }else if(playerPercent >= 80 && playerPercent < 90){
    
    lifePlayer = getSprite(LIFE_80);
  }else if(playerPercent >= 70 && playerPercent < 80){
    
    lifePlayer = getSprite(LIFE_70);
  }else if(playerPercent >= 60 && playerPercent < 70){
    
    lifePlayer = getSprite(LIFE_60);
  }else if(playerPercent >= 50 && playerPercent < 60){
    
    lifePlayer = getSprite(LIFE_50);
  }else if(playerPercent >= 40 && playerPercent < 50){
    
    lifePlayer = getSprite(LIFE_40);
  }else if(playerPercent >= 30 && playerPercent < 40){
    
    lifePlayer = getSprite(LIFE_30);
  }else if(playerPercent >= 20 && playerPercent < 30){
    
    lifePlayer = getSprite(LIFE_20);
  }else if(playerPercent >= 10 && playerPercent < 20){
    
    lifePlayer = getSprite(LIFE_10);
  }else {
    lifePlayer = getSprite(LIFE_0);
  }

  return lifePlayer;
}

void drawBattleScene()
{
  int i;

  drawImage(background.sprite, background.x, background.y);

  setScore();

  setBattleName(battle);

  for (i = 0; i < 2; i++)
  {
    drawImage(lifeBar[i].sprite, lifeBar[i].x, lifeBar[i].y);
  }

  drawImage(player.entity.sprite, player.entity.x, player.entity.y);
  drawImage(enemy.entity.sprite, enemy.entity.x, enemy.entity.y);


  drawImage(menuWeaponItem[0].entity.sprite, menuWeaponItem[0].entity.x, menuWeaponItem[0].entity.y);
  drawImage(menuWeaponItem[1].entity.sprite, menuWeaponItem[1].entity.x, menuWeaponItem[1].entity.y);


  updateLife();
}

void drawScene()
{
  SDL_FillRect(game.screen, NULL, 0);

  drawBattleScene();

  SDL_Flip(game.screen);

  SDL_Delay(100);
}



void controlWeapon(){
  SDL_Event e;

  while(SDL_PollEvent(&e))
  {
    switch(e.type)
    {
      case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {
          case SDLK_UP:
            if(indexBattleMenu == 0){
              indexBattleMenu = 2;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }else if( indexBattleMenu == 2){
              indexBattleMenu = 1;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }else{
              indexBattleMenu = 0;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }
            break;
          case SDLK_DOWN:
            if(indexBattleMenu == 0){
              indexBattleMenu = 1;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }else if( indexBattleMenu == 1){
              indexBattleMenu = 2;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }else{
              indexBattleMenu = 0;
              menuWeaponItem[0].entity.sprite = getSprite(relationMenu[indexBattleMenu]);
            }
            break;
          case SDLK_RETURN:
              enemy.weapon = randInt(3);
              menuWeaponItem[1].entity.sprite = getSprite( relationMenuEnemy[enemy.weapon - 1] );
              player.weapon = indexBattleMenu + 1;
              printf("enemy> %d\n player> %d\n", enemy.weapon, player.weapon);
              duel(&player, &enemy);
              break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
}





void battleScene(){
    unsigned int frameLimit = SDL_GetTicks() + 16;
    loopBattleScene = 1;
    battle = 1;
    indexBattleMenu = 0;
    game.score = 0;
    /*SDL_Event e; */


    initBattleScene();

    while( loopBattleScene == 1 && player.hp > 0 && battle < MAX_BATTLES){
      chooseEnemy();
      setBattleName(battle);
      SDL_Delay(300);

      while(enemy.hp > 0 && player.hp > 0){
        controlWeapon();

        drawScene();

        delay(frameLimit);

        frameLimit = SDL_GetTicks() + 16;
      }
      finalRules(&player, &enemy);
      if(player.hp > 0){
        countScore(&game.score, player.classe, enemy.classe);
        printf("\n*** SCORE: %d ***\n", game.score);
      }
      battle++;

    }
    if(player.hp <= 0){
      gameOverScene();
    }
}