#include "gameover.h"


extern void drawString(char *, int, int, TTF_Font *, int, int);
extern void menuScene();


void drawGameOverScene(){
	SDL_FillRect(game.screen, NULL, 0);

	drawString("[ESC] Para voltar", 10, (game.screen->h - 30) , game.font, 1, 0);
	drawString("Game Over", 0, 0, game.font, 1, 1);


	SDL_Flip(game.screen);

	SDL_Delay(130);
}


void gameOverScene()
{
	int loop = 1;
	SDL_Event e;


	while(loop != 0)
	{
		SDL_WaitEvent(&e);

		drawGameOverScene();
		if(e.key.keysym.sym == SDLK_ESCAPE)
		{
			loop = 0;
		}
	}
	menuScene();


}