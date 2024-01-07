#include "head.h"

// runningstate -2 -1 0 1 2 3 4 5
struct gamestate gamestates;

void init_state(void)
{
    // system("clear");
    gamestates.runningstate = 0;
    gamestates.playerstate = 0; //
    gamestates.round = 0;
    initRecordBoard();
    initplayer();
}

int stateprocess(char line[])
{
    int vaild = 0;
    if ((!gamestates.runningstate) && (!strcmp(line, MANUAL)))
    {
        gamestates.runningstate = 1;
        vaild = 1;
    }
    else if ((!gamestates.runningstate) && (!strcmp(line, HUMANVSAI)))
    {
        gamestates.runningstate = 2;
        vaild = 1;
    }
    else if ((!gamestates.runningstate) && (!strcmp(line, AIVSHUMAN)))
    {
        gamestates.runningstate = 3;
        vaild = 1;
    }
    else if ((!gamestates.runningstate) && (!strcmp(line, AIVSAI)))
    {
        gamestates.runningstate = 4;
        vaild = 1;
    }
    else if ((!gamestates.runningstate) && (!strcmp(line, AUTO)))
    {
        gamestates.runningstate = 5;
        vaild = 1;
    }
    else if (!strcmp(line, EXIT))
    {
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
    printf("Made by Junyan Jiang\n");
    printf("Runningstate=%d\n", gamestates.runningstate);
    if (gamestates.runningstate)
    {
        printf("Now Player:%s\n", (gamestates.playerstate == BLACK) ? BLACKNAME : WHITENAME);
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
        inputprocess_manual();
        gamestates.runningstate = 1;
    }
    if (arrayForInnerBoardLayout[SIZE - pos.x][pos.y] != 0)
    {
        printf(ERROR_ALREDY_HAVE);
        gamestates.runningstate = -1;
        inputprocess_manual();
        gamestates.runningstate = 1;
    }
}

void winHandle(int check)
{
    if (check == 1)
    {
        printf(WININFO, (!gamestates.playerstate == BLACK) ? BLACKNAME : WHITENAME);
        gamestates.runningstate = 0;
    }
    else if ((check >= 2) && (!gamestates.playerstate == BLACK))
    {
        switch (check)
        {
        case 2:
            printf("Long Chain Detected!\n");
            break;
        case 3:
            printf("Double Three Detected!\n");
            break;
        case 4:
            printf("Double Four Detected!\n");
            break;
        default:
            break;
        }
        gamestates.playerstate = !gamestates.playerstate;
        printf(WININFO, (!gamestates.playerstate == BLACK) ? BLACKNAME : WHITENAME);
        gamestates.runningstate = 0;
    }
    else
    {
        ; // Do nothing
    }
}
