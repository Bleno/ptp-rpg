#include "battle.h"
#include "util.h"

extern void drawImage(SDL_Surface *, int, int);
extern void delay(unsigned int );
extern SDL_Surface *getSprite(int);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern Player createPlayer(int);


void initBattleScene(){

  setBattleBackground();

  setLifeBar();

  setScore();

  setPlayer();

  chooseEnemy();
}

void setScore(){
  char text[20];

  /* score */
  sprintf(text, "SCORE: %05d", game.score);
  drawString(text, 10, 10, game.font, 1, 0);
  /* score */

}

void setBattleName(int numBattle){
  unsigned int lastTime = 0, currentTime;
  char text[20];

  /* score */
  sprintf(text, "BATTLE: %d", numBattle);
  drawString(text, 10, 10, game.font, 1, 1);
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

void drawBattleScene()
{
  int i;

  drawImage(background.sprite, background.x, background.y);


  for (i = 0; i < 2; i++)
  {
    drawImage(lifeBar[i].sprite, lifeBar[i].x, lifeBar[i].y);
  }

  drawImage(player.entity.sprite, player.entity.x, player.entity.y);
  drawImage(enemy.entity.sprite, enemy.entity.x, enemy.entity.y);
  
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
            printf("up\n");
            break;
          default:
            loopBattleScene = 0;
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
    int percente = 0;
    loopBattleScene = 1;
    battle = 1;
    /*SDL_Event e; */


    initBattleScene();

    while( loopBattleScene == 1){

      controlWeapon();

      drawScene();

      percente = calculatePercente(player.total_hp, player.hp);
      printf("%d%%\n", percente);



      delay(frameLimit);

      frameLimit = SDL_GetTicks() + 16;
    }
}