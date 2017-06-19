#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "menu.h"

int main(int argc, char *argv[]){

  int i;
  for(i = 0; i < argc; i++){
  	printf("%s\n", argv[i]);
  	if (strcmp("-interface", argv[i]) == 0){
  		printf("Usar intercace!!!\n");
  	}
  }
  menu();

  return 0;
}
