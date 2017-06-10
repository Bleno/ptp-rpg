#include <stdio.h>
#include <stdlib.h>
#include "choose.h"


void choose(){
	int opt = 0;
	printf("Escolha sua classe\n");
	printf(" 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n");
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