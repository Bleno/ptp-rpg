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