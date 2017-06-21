#include "main.h"
#include "menu.h"


extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern SDL_Surface *loadImage(char *);
extern void updateScreen(void);

int main(int argc, char *argv[]){

  int i, mode = 0;

  for(i = 0; i < argc; i++){
  	printf("%s\n", argv[i]);
  	if (strcmp("-interface", argv[i]) == 0){
  		printf("Usar intercace!!!\n");
      mode = 1;
  	}
  }

  if(mode == 1){
    interface();
  }
  else{
    menu();
  }

  return 0;
}


void interface(){

  int go;
  /* Start up SDL */
  
  init("PTP - RPG");
  
  /* Limpa tela ao sair */
  atexit(cleanup);

  go = 1;
  
  backgroundImage = loadImage("gfx/startBg.png");
  /* If we get back a NULL image, just exit */
  
  if (backgroundImage == NULL)
  {
    exit(0);
  }
  
  /* Loop indefinitely for messages */
  
  while (go == 1)
  {
    getInput();
    
    updateScreen();

    go = drawMenu();
    
    /* Sleep briefly to stop sucking up all the CPU time */
    
    SDL_Delay(16);
  }
  
  /* Exit the program */
  
  exit(0);
}