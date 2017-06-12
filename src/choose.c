#include <stdio.h>
#include <stdlib.h>
#include "choose.h"
#include "character.h"
#include "battle.h"


void choose(){
	int opt = 0;
	struct character mainChar;
	printf("Escolha sua classe\n");
	printf(" 1 - Guerreiro\n 2 - Arqueiro\n 3 - Mago\n");
	while( opt == 0 || opt > 3)
	{
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  mainChar = create_character(opt);
			  printf("Você escolheu Guerreiro!\n Helth: %0.f, \n Damage %0.f\n", mainChar.hp, mainChar.damage);
			  battle(mainChar);
			  break;
			case 2:
			  mainChar = create_character(opt);
			  printf("Você escolheu Arqueiro!\n Helth: %0.f, \n Damage %0.f\n", mainChar.hp, mainChar.damage);
			  battle(mainChar);
			  break;
			case 3:
			  mainChar = create_character(opt);
			  printf("Você escolheu Mago!\n Helth: %0.f, \n Damage %0.f\n", mainChar.hp, mainChar.damage);
			  battle(mainChar);
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}