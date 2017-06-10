#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "choose.h"
#include "score.h"


void menu(){
	int opt = 0;
	printf("Digite uma opcao\n");
	printf(" 1 - Novo Jogo\n 2 - Records\n 3 - Sair\n");
	while( opt == 0 || opt > 3)
	{
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  choose();
			  break;
			case 2:
			  score();
			  break;
			case 3:
			  exit(0);
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}