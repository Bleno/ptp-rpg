#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include "menu.h"


void score(){
	int opt = 0;
	char * line;
	FILE *fp = fopen("score.data", "ab");

	if (fp == NULL)
	{
		printf("Falha ao carregar score");
		
		exit(1);
	}
	fscanf(fp, "%s", line);
	if(line == NULL){
		printf("Não há records!\n");
	}else{
    	printf("%s\n", line );
	}

	while( opt != 1)
	{
		printf(" 1 - Voltar \n");
		scanf("%d", &opt);
		switch (opt){
			case 1:
			  menu();
			  break;
			default:
			  printf("opcao invalida!\n");
		}
	}

}


void countScore(int *score, int mainChar, int enemy){
	// HIERAQUIA     | CORRESPONDENTES
	// 3. MAGO       |  
	// 2. ARQUEIRO   |
	// 1. GUERREIRO  | 
	// 0. MAGO || 3  |
	if(mainChar == enemy){
		*score += 150;
	}else if( (mainChar == 3 && enemy == 2) || (mainChar == 2 && enemy == 1)  || (mainChar == 1 && enemy == 3) ){
		*score += 100;
	}else if((mainChar == 3 && enemy == 1) || (mainChar == 1 && enemy == 2)  || (mainChar == 2 && enemy == 3)){
		*score += 200;
	}
}