#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "score.h"
#include "menu.h"






void score(){
	int i, opt = 0;
	FILE * arq;
	char nome[50];

	arq = fopen("score.data", "r");
	if( arq == NULL){
	  printf("Erro ao abrir o arquivo!");
	}else{
	  printf("*************************\n*        RECORDS        *\n*************************\n");
	  while(fgets(nome, sizeof(nome), arq)){
		  printf(" %s ", nome);
	  }
	  printf("\n*************************\n");
	  fclose(arq);
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