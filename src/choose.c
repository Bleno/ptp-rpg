#include <stdio.h>
#include <stdlib.h>
#include "choose.h"
#include "character.h"
#include "battle.h"


void choose(){
	int opt = 0;
	struct character mainChar;
	fflush(stdout);
	printf("Escolha sua classe\n");
	printf(" 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n");
	while( opt == 0 || opt > 3)
	{
		scanf("%d", &opt);
		switch (opt){
			case 1:
			case 2:
			case 3:
			  mainChar = create_character(opt);
              mainChar.name = "Player1";
			  printf("Você escolheu %s!\n Helth: %0.f, \n Damage %0.f\n",chars[opt - 1], mainChar.hp, mainChar.damage);
			  battle(mainChar);
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}