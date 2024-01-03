#include "head.h"

int main()
{
    init_state();
    input();
    update();
    while (gamestates.runningstate)
    {
        if (gamestates.runningstate == 1)
        {
            update();
            gamejudger();
        }
        else if (gamestates.runningstate == 2)
        {
            update();
            getchar();
        }
        else if (gamestates.runningstate == -2)
        {
            printf(WININFO, (!gamestates.playerstate == BLACK) ? BLACKNAME : WHITENAME);
            gamestates.runningstate = 0;
        }
        //++gamestates.round;
    }
    return 0;
}