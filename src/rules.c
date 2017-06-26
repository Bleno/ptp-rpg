#include "rules.h"


extern void drawString(char *, int, int, TTF_Font *, int, int);

/* **************************************************************
****
****         REGRAS DE BATALHA
****
*
*
*  *** */


int calculatePercente(int total, int atual){
  int aux, resp;
  aux = atual * 100;
  resp = aux / total;
  return resp;
}



void empate(Player  *player, Player *enemy){
    player->sequence = 0;
    enemy->sequence = 0;
}


void rules(int victory, Player *player, Player *enemy){
   /* victory 0 - enemy, 1 player */
   if(victory == 1){
        if( player->classe == 1 && enemy->classe == 3){ /* // vitoria do guerreiro contra o mago */
            if( player->sequence == 1 ){
                enemy->hp = enemy->hp - (player->damage * 2);
                printf("Double attack\n");
            }else{
                enemy->hp = enemy->hp - player->damage;
                player->sequence = 1;
            }
        }else if(player->classe == 2 && enemy->classe == 1){ /* vitoria do arqueiro contra o guerreiro */
            int chance = 0;
            chance = randInt(10);
            if( chance > 3){
                enemy->hp = enemy->hp - player->damage;
            }else{
                player->hp += 200;
                enemy->hp = enemy->hp - 200;
            }
        }else if(player->classe == 3 && enemy->classe == 2){ /* vitoria mago contra arqueiro */
            enemy->hp -= player->damage;
            player->total_hp += player->damage;
        }else if(player->classe == 1 && enemy->classe == 2){ /* vitoria do guerreiro contra o arqueiro */
            int chance = randInt(2);
            if (chance == 2)
            {
                printf("## Attack Bloqued ##\n");
            }else{
                enemy->hp = enemy->hp - enemy->damage;
            }
        }else{
                enemy->hp = enemy->hp - player->damage;
                player->sequence = 0;
        }
   }else{
        if(player->classe == 2 && enemy->classe == 1){ /* vitoria guerreiro contra arqueiro */
            int chance = randInt(2);
            if (chance == 2)
            {
                printf("## Attack Bloqued ##\n");
            }else{
                player->hp = player->hp - enemy->damage;    
            }
        }else if(player->classe == 3 && enemy->classe == 2){ /* vitoria arqueiro contra o mago */
            int chance = randInt(10);
            if( chance > 4){
                player->hp = player->hp - enemy->damage;
            }else{
                enemy->hp -= 100;
                printf("## Counter-attack ##\n");
            }
        }else if( player->classe == 3 && enemy->classe == 1){/* vitoria do guerreiro contra o mago */
            if( player->sequence == 1 ){
                player->hp = player->hp - (enemy->damage * 2);
                printf("Double attack\n");
            }else{
                player->hp = player->hp - enemy->damage;
                enemy->sequence = 1;
            }
        }else{
            player->hp = player->hp - enemy->damage;
        }
   }
}

void duel(Player *player, Player *enemy){
    /*
    //1 pedra
    //2 tesoura
    //3 papel
    */
    int w = player->weapon;
    int e = enemy->weapon;


    printf("******** DUELO ***************\n");
    if(w == e){
        printf("Empate\n");
        drawString("Empate", 0, 0, game.font, 1, 1);
        empate(player, enemy);
    }else{
        if(w == 3 && e == 1){
            printf("Você ganhou!\n");
            enemy->hp = enemy->hp - player->damage;
            rules(1, player, enemy);
        }else if( w == 1 && e ==  2){
            printf("Você ganhou!\n");
            rules(1, player, enemy);
        }else if(w == 2 && e == 3){
            printf("Você ganhou!\n");
            enemy->hp = enemy->hp - player->damage;
        }else{
            printf("Você perdeu!\n");
            rules(0, player, enemy);
        }
    }
 
}



void finalRules(Player  *player, Player *enemy){
    int hp;
    if( player->classe == 1 && enemy->classe == 3 && player->hp > 0){ /* // vitoria do guerreiro contra o mago  */
        player->sequence = 0;
        player->total_hp += 100;
        hp = player->hp + (player->hp * 0.5);  /* // 50% de hp pela vitória  */
        if( hp > player->total_hp){
            player->hp = player->total_hp;
        }else{
            player->hp = hp;
        }
    }else if( player->classe == 2 && enemy->classe == 1 ){ /*  //vitoria do arqueiro contra o guerreiro  */
        hp = player->hp + ( player->hp * 0.3 );  /* //30% de hp pela vitoria  */
        if(hp > player->total_hp){
            player->hp = player->total_hp;
        }else{
            player->hp = hp;
        }
    }else if( player->classe == 3 && enemy->classe == 2){ /*  // vitoria mago contra arqueiro  */
        hp = player->hp + (player->hp * 0.7);  /* // 70% pela vitoria   */
        if( hp > player->total_hp ){
            player->hp = player->total_hp;
        }else{
            player->hp = hp;
        }
    }
}




/****
  FIM REGRAS DE BATALHA
****/
