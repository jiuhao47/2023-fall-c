#include "head.h"
void judge(void)
{
    ;
}

// Chainjudge
// mode 0,1,2,3
// 0:x
// 1:y
// 2:x-y
// 3:y-x
int chainjudge(int mode)
{

    return 0;
}
// 我疑似需要一个数据结构，用来存储已经落下的棋子坐标
// 然后使用周遭判断，来记录目前棋盘上的连珠情况
// 又一个新的数据结构

int winjudge(int x, int y, int mode)
{
    int nowchess = arrayForInnerBoardLayout[SIZE - x][y];
    int cnt;
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
    for (int i = 0; i < 9; i++)
    {
        if ()
    }
}

// 坐标系需要重整