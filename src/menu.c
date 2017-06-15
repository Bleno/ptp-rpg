#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "choose.h"
#include "score.h"


void menu(){
	int opt = 0;
	int loop = 1;
	while( loop == 1)
	{
		printf("Digite uma opcao\n");
		printf(" 1 - Novo Jogo\n 2 - Records\n 3 - Sair\n");
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  fflush(stdin);
			  choose();
			  break;
			case 2:
			  fflush(stdin);
			  score();
			  break;
			case 3:
			  fflush(stdin);
			printf("Goodbye!\n");
			  exit(0);
			  break;
			default:
			  fflush(stdin);
			  printf("opcao invalida!\n");
		}
	}

}