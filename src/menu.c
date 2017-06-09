#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


void menu(){
	int opt = 0;
	printf("Digite uma opcao\n");
	printf(" 1 - Novo Jogo\n 2 - Score\n 3 - Sair\n");
	while( opt == 0 || opt > 3)
	{
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  printf(" >>>>> 1\n");
			  break;
			case 2:
			  printf(" >>>>> 2\n");
			  break;
			case 3:
			  printf(" >>>>> 3\n");
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}