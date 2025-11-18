#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

//~~~~~~`
#define MAX_die
int rolldie(void)
//~~~~~~
{
    return rand()%MAX;
}

//////////


int main(int argc, char *argv[])
{
    srand((unsigned)(time(NULL)) );
    
    //opening
    printf("=============================\n");
    printf("*****************************\n");
    printf("          BINGO GAME         \n");
    printf("*****************************\n");
    printf("=============================\n");
    
    //step1. initialization(player name, variables)
    board_initBoard();
    
    
    //step2. turn play(do-while)
    cnt = 0;
    pos = 0;
    do {
        int die_result;
        int coinResult;
        
    //2-1. status printing
    board_printBoardStatus();
    
    //2-2. roll dice
    //2-3. move(result)
    pos += die_result;
    
    printf("pos : %i(die:%i)")
    coinResult = board_getBoardCoin(pos);
    //2-4. change turn, shark move
    cnt++;
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
