#include "main.h"


extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void initMainMenu(void);
extern void drawMenu(void);
extern void doMenu(void);
extern void loadAllSprites(void);
extern void delay(unsigned int);

int main(int argc, char *argv[]){

  int i, mode = 0;

  for(i = 0; i < argc; i++){
  	printf("%s\n", argv[i]);
  	if (strcmp("-interface", argv[i]) == 0){
  		printf("Usar interface!!!\n");
      mode = 1;
  	}
  }

  if(mode == 1){
    interface();
  }
  else{
    printf("Sem interface\n");
  }

  return 0;
}


void interface(){
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  
  init("PTP - RPG");
  
  /* invoca a função limpar tela ao sair */
  atexit(cleanup);

  go = 1;
  
  /* Load all sprites */
  loadAllSprites();


  /* init position menu */

  initMainMenu();

  
  while (go == 1)
  {
    getInput();

    doMenu();

    drawMenu();
    
    delay(frameLimit);

    frameLimit = SDL_GetTicks() + 16;

  }
  

  
  exit(0);
}