#include "head.h"

int main()
{
    init_state();
    input();
    updateBoard();
    while (gamestates.runningstate)
    {
        if (gamestates.runningstate == 1)
        {
            updateBoard();
        }
        else if (gamestates.runningstate == 2)
        {
            updateBoard();
            getchar();
        }
        ++gamestates.round;
    }
    return 0;
}