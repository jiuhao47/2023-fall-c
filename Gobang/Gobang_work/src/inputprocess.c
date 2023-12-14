#include "head.h"
struct point pos;

// Change input into point
// Manual test mode
struct point inputprocess_manual(void)
{
    pos.x = pos.y = 0;
    char line[LINEMAXLEN];
    for (int j = 0; j < LINEMAXLEN; j++)
    {
        line[j] = '\0';
    }
    int i = 0;

    mygetline(line, LINEMAXLEN);
    // printf("%s\n", line);
    if (!(stateprocess(line)))
    {
        while (line[i] != '\0')
        {
            if (isalpha(line[i]))
            {
                pos.y = toupper(line[i]) - 'A';
            }
            else if (isdigit(line[i]))
            {
                pos.x = (line[i] - '0') + pos.x * 10;
            }
            ++i;
        }
        ErrorHandle();
    }
    return pos;
}

// Change input into point
// Auto test mode
struct point inputprocess_auto(void)
{
    gamestates.playerstate = !gamestates.playerstate;
    pos.x = pos.y = 0;
    scanf(INPUT_EXAMPLE, &pos.x, &pos.y);
    return pos;
}

void input(void)
{
    struct point temppos;
    InfoDisplay();
    switch (gamestates.runningstate)
    {
    case 0:
        inputprocess_manual();
        break;
    case 1:
        temppos = inputprocess_manual();

        if (gamestates.runningstate)
        {
            arrayForInnerBoardLayout[SIZE - temppos.x][temppos.y] = (gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
        }
        break;
    case 2:
        temppos = inputprocess_auto();
        arrayForInnerBoardLayout[SIZE - temppos.x][temppos.y - 1] = (gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
        break;
    }
}
