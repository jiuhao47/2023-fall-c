#include "head.h"
struct point pos;

// Change input into point
// Manual test mode
void inputprocess_manual(void)
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
}

// Change input into point
// Auto test mode
void inputprocess_auto(void)
{
    gamestates.playerstate = !gamestates.playerstate;
    pos.x = pos.y = 0;
    scanf(INPUT_EXAMPLE, &pos.x, &pos.y);
}

void input(void)
{
    InfoDisplay();
    switch (gamestates.runningstate)
    { /*
     case -2:
         printf(WININFO, (gamestates.playerstate == BLACK) ? BLACKNAME : WHITENAME);
         gamestates.runningstate = 0;
         break;
     */
    case 0:
        inputprocess_manual();
        break;
    case 1:
        inputprocess_manual();

        if (gamestates.runningstate)
        {
            arrayForInnerBoardLayout[SIZE - pos.x][pos.y] = (gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
        }
        break;
    case 2:
        inputprocess_auto();
        arrayForInnerBoardLayout[SIZE - pos.x][pos.y - 1] = (gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
        break;
    }
}
