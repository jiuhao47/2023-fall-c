#include "head.h"
void judge(void)
{
    ;
}

// Chainjudge
// mode 1,2,3,4
// 1:x
// 2:y
// 3:x-y
// 4:y-x
int chainjudge(int mode)
{

    return 0;
}
// 我疑似需要一个数据结构，用来存储已经落下的棋子坐标
// 然后使用周遭判断，来记录目前棋盘上的连珠情况
// 又一个新的数据结构

int linejudge(int x, int y, int mode, int player)
{
    int nowchess = arrayForInnerBoardLayout[SIZE - x][y];
    int count = 0;
    int dx, dy;
    switch (mode)
    {
    case 1:
        dx = 1, dy = 0; // 竖直
        break;
    case 2:
        dx = 0, dy = 1; // 水平
        break;
    case 3:
        dx = 1, dy = 1; //
        break;
    case 4:
        dx = 1, dy = -1;
        break;
    default:
        printf("Wrong Judge Mode!\n");
        return -1;
    }
    for (int i = -4; i <= 4; i++)
    {
        // 边缘检测没写
        if ((arrayForInnerBoardLayout[SIZE - (pos.x + i * dx)][pos.y + i * dy] == ((player == BLACK) ? BLACKCHESS : WHITECHESS)) || (arrayForInnerBoardLayout[SIZE - (pos.x + i * dx)][pos.y + i * dy] == ((player == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT)))
        {
            count = count + 1;
        }
    }
    printf("(%d,%c) %d:Count=%d\n", pos.x, pos.y + 'A', mode, count);
    return (count == 5) ? 1 : 0;
}

void winjudge(void)
{
    int win = 0;
    for (int i = 1; i < 5; i++)
    {
        win = win + linejudge(pos.x, pos.y, i, gamestates.playerstate);
    }
    if (win > 0)
    {
        gamestates.runningstate = -2;
    }
}