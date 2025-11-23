#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAXLENGTH   30
#define MAX_DIE     6
#define N_PLAYER    3

#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"LIVE", "DIE", "END"};

int printPlayerPosition(int player)//이거 앞에 void를 int로 바꿨어. 
{
     int i;
     for(i=0;i<N_BOARD;i++)
     {
          printf("|");
          if(i==player_position[player])
               printf("%c", player_name[player][0]);
          else
          {
              if(board_getBoardStatus(i) == BOARDSTATUS_OK)///겟 보드 스테이터스 괄호 동그란걸로 바꿈 
                  printf(" ");
              else
                  printf("X");
          }   
      }
      printf("|\n"); 
}

void printPlayerStatus(void)
{
     int i;
     printf("player status ---\n");
     for(i=0;i<N_PLAYER;i++)
     {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
     }

     printf("---------------------------------\n");
}

void initPlayer(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)    
     {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[N_PLAYER]=PLAYERSTATUS_LIVE;
        printf("Player %i's name:", i);
        scanf("%s", player_name[i]);
        fflush(stdin);
        
        int player_position[N_PLAYER];
        int player_coin[N_PLAYER];
        int player_status[N_PLAYER];
}

int gameEnd(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died? 
    for(i=0;i<N_PLAYER;i++)
    {
         if(player_status[i] == PLAYERSTATUS_LIVE)
         {
             flag_end = 0;
             break;
         }
    }
    
    return flag_end;
}

void checkDie(void)
{
         int i;
         
         for(i=0;i<N_PLAYER;i++)
         {
            if(player_position[i] == PLAYERSTATUS_DIE);
               printf("PLAYERSTATUS_DIE");                       
         }
}
        
int rolldie(void)
{
    return rand()%MAX_DIE +1;
}

int main(int argc, char *argv[])
{
    int dum;/////check하렴 
    int turn;
    int cnt;
    srand((unsigned)(time(NULL)) );
    
    //opening
    printf("=============================\n");
    printf("*****************************\n");
    printf("          BINGO GAME         \n");
    printf("*****************************\n");
    printf("=============================\n");
    
    //step1. initialization(player name, variables)
    board_initBoard();
    initPlayer();
    //player init
    
    //step2. turn play (do-while)
    
 
    do{
          int die_result;
          int dum;//////dum 여기인 듯 
    //2-1. status printing
    board_printBoardStatus();
    printPlayerStatus();
   // player status(각자)
   
    
    //2-2. roll die
    printf("%s turn!!", player_name[turn]);
    printf("Press any key to roll a die!\n");
    scanf("%d" ,&dum);
    fflush(stdin);
    die_result = rolldie();//player turn
    
    //****2-3. move(result)//player turn
    player_position[turn] += die_result;
    if(player_position[turn]>=N_BOARD)
    {
         player_position[turn] = N_BOARD-1;
         player_status[turn] = PLAYERSTATUS_END;
    }
    printf("Die result : %i, %s moved to %i\n", die_result, player_name, player_position);///player position 수정해야할수도 
    
    
    player_coin[turn] += board_getBoardCoin(player_position[turn]);
    printf("Lucky! %s got %i coins\n" , player_name[turn] );
    //2-4. change turn, shark move
    //change turn
    if(player_status[turn] != PLAYERSTATUS_LIVE)
    {
         turn = (turn + 1)%N_PLAYER;
         continue;
    }
    
    //shark move
    if(turn == 0)
    {
            int shark_pos = board_stepShark();
            printf("Shark moved to %i\n", shark_pos);
            //check die
            checkDie();
    }
    cnt++;
  }while(gameEnd == 0);
    //step3. game end(winner printing)
    
    //ending
    printf("\n\n\n\n\n\n\n\n\n");
    printf("=============================\n");
    printf("*****************************\n");
    printf("       CONGRATUATION!!!!!    \n");
    printf("*#&$*^@(BINGO!!!)*#&$*^@*#&$*\n");
    printf("        YOU WIN!!!!!!        \n");
    printf("*****************************\n");
    printf("=============================\n\n");
    
    system("PAUSE");	
    return 0;
}
}
