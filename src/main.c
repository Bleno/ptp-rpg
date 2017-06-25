#include "main.h"


extern void init(char *);
extern void cleanup(void);
extern void loadAllSprites(void);
extern TTF_Font *loadFont(char *, int);
extern void menuScene(void);

int main(int argc, char *argv[]){

  init("PTP - RPG");
  
  /* invoca a função limpar tela ao sair */
  atexit(cleanup);


  game.font = loadFont("font/OpenSans-Regular.ttf", 16);
  
  /* Load all sprites */
  loadAllSprites();

  menuScene();

  return 0;
}
