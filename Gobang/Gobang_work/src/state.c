#include "head.h"

void initplayer(void);
struct gamestate gamestates;

void init_state(void)
{
    gamestates.runningstate = 0;
    gamestates.playerstate = 0; //
    gamestates.round = 0;
    initRecordBoard();
    initplayer();
}

int stateprocess(char line[])
{
    // printf("cmp=%d\n", strcmp(line, EXIT));
    int vaild = 0;
    if ((!gamestates.runningstate) && (!strcmp(line, MANUAL)))
    {
        // printf("ENTER_1\n");
        gamestates.runningstate = 1;
        vaild = 1;
    }
    else if ((!gamestates.runningstate) && (!strcmp(line, AUTO)))
    {
        // printf("ENTER_2\n");
        gamestates.runningstate = 2;
        vaild = 1;
    }
    else if (!strcmp(line, EXIT))
    {
        // printf("ENTER\n");
        gamestates.runningstate = 0;
        vaild = 1;
    }
    else
    {
        if (gamestates.runningstate != -1)
        {
            gamestates.playerstate = !gamestates.playerstate;
        }
        vaild = 0;
    }
    return vaild;
}

void InfoDisplay(void)
{
    printf("Runningstate=%d\n", gamestates.runningstate);
    if (gamestates.runningstate)
    {
        printf(INPUTCHESS_S);
    }
    else
    {
        printf(INPUTMODE_S);
    }
}

void ErrorHandle(void)
{
    // inputprocess()
    if ((pos.x < 1) || (pos.x > SIZE) || (pos.y < 0) || (pos.y > SIZE - 1))
    {
        printf(ERROR_OUT_OF_RANGE);
        gamestates.runningstate = -1;
        pos = inputprocess_manual();
        gamestates.runningstate = 1;
    }
    if (arrayForInnerBoardLayout[SIZE - pos.x][pos.y] != 0)
    {
        printf(ERROR_ALREDY_HAVE);
        gamestates.runningstate = -1;
        pos = inputprocess_manual();
        gamestates.runningstate = 1;
    }
}
