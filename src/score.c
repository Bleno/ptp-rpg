#include "score.h"


extern TTF_Font *loadFont(char *, int);
extern void closeFont(TTF_Font *);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern void menuScene(void);

void addStrings(char** str1, const char* str2,char del)
{
    size_t len1 = *str1 ? strlen(*str1) : 0;
    size_t len2 = str2 ? strlen(str2) : 0;
    char *res = realloc(*str1, len1 + len2 + 2);
    if (res)
    {
        res[len1] = del;
        memcpy(res + len1 + 1, str2, len2);
        res[len1 + 1 + len2] = 0;
        *str1 = res;
    }
}

char* readScore(){
	FILE * arq;
	char nome[50], *ptr = NULL;

	arq = fopen("score.data", "r");
	if( arq == NULL){
	  printf("Erro ao abrir o arquivo!");
	}else{
	  printf("*************************\n*        RECORDS        *\n*************************\n");
	  while(fgets(nome, sizeof(nome), arq)){
		  printf(" %s ", nome);
		  addStrings(&ptr, nome, '\n');
	  }
	}
	  
	printf("\n*************************\n");
	fclose(arq);
	return ptr;
}


void countScore(int *score, int mainChar, int enemy){
	/*
	// HIERAQUIA     | CORRESPONDENTES
	// 3. MAGO       |  
	// 2. ARQUEIRO   |
	// 1. GUERREIRO  | 
	// 0. MAGO || 3  | */
	if(mainChar == enemy){
		*score += 150;
	}else if( (mainChar == 3 && enemy == 2) || (mainChar == 2 && enemy == 1)  || (mainChar == 1 && enemy == 3) ){
		*score += 100;
	}else if((mainChar == 3 && enemy == 1) || (mainChar == 1 && enemy == 2)  || (mainChar == 2 && enemy == 3)){
		*score += 200;
	}
	storeScore(*score);
}

void storeScore(int score){
  FILE * arq;
  arq = fopen("score.data", "a+");
  if( arq == NULL){
      printf("Erro ao abrir o arquivo!");
  }else{
      fprintf(arq, "%d\n", score);
      fclose(arq);
  }
}



void drawScore()
{
	TTF_Font *title = NULL, *goBack = NULL;
	SDL_Surface *bg = NULL;
	SDL_Rect pos;
	SDL_Event e;
	int loop = 1;

	/* Background */
	bg = IMG_Load("gfx/arena.png");
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(bg, NULL, game.screen, &pos);

	
	/* titulo */
	title = loadFont("font/OpenSans-Regular.ttf", 22);
	drawString("RECORDS", 10, 10, title, 1, 0);
	
	/* Voltar */
	goBack = loadFont("font/OpenSans-Regular.ttf", 16);
	drawString("[ESC] Para voltar", 10, (game.screen->h - 30) , goBack, 1, 0);


	getScore();
	
	SDL_Flip(game.screen);
	SDL_FreeSurface(bg);



	while(loop != 0)
	{
		SDL_WaitEvent(&e);

		if(e.key.keysym.sym == SDLK_ESCAPE)
		{
			loop = 0;
		}
	}



	closeFont(title);
	closeFont(goBack);
	SDL_FillRect(game.screen,NULL,0x000000);
	menuScene();
}


int* criaArray(int len){
	int *arr = NULL, i;
	FILE *f;

	f = fopen("score.data", "r");
	if( f == NULL){
	  drawString("Não há records", 10, 50, game.font, 1, 0);
	}else{

		arr = malloc(sizeof(int) * len);
		for (i = 0; i < len; i++)
		{
			fscanf(f, "%d", arr);
		}
		fclose(f);
	}
	return arr;
}


void getScore()
{
	TTF_Font *font = NULL;
	int i, posLIne = 50 ;
	FILE * arq;
	char nome[50], text[50];
	int *pontos = NULL;
	  /* score */

  	font = loadFont("font/OpenSans-Regular.ttf", 16);


	arq = fopen("score.data", "r");
	if( arq == NULL){
	  printf("Erro ao abrir o arquivo!");
	}else{
	  i = 1;
	  while(fgets(nome, sizeof(nome), arq)){

		sprintf(text, "%d: %s", i, nome);
		drawString(text, 10, posLIne, font, 1, 0);
		i++;
		posLIne += 20;
	  }
	  pontos = criaArray(i);
	  fclose(arq);

	}
	  


}