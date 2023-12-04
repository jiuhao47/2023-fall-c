#include <stdio.h>

struct Point
{
    int row;
    int col;
};
int ReadytoGetPlayer()
{
    puts("Ready to get player");
    char str[64];
    scanf("%s", str); // black or white
    if (str[0] == 'b' || str[0] == 'B')
        return 1;
    else
        return 0;
}
Point Makemove(int row, int col, int printChessboard = 0)
{
    static int step = 0;
    static char chessboard[16][16] = {0};
    step++;
    if (row != 0 || col != 0)
    {
        if (row > 0 && row < 16 && col > 0 && col < 16)
        {
            if (printChessboard)
            {
                // TODO:打印棋盘
            }
            printf("Step %d: row=%d,col=%d\n", step, row, col); // TODO:打印规范
        }
        else
        { // TODO:错误的输入，进入报错流程
            printf("Invalid move: row=%d,col=%d\n", row, col);
            return {0, 0};
        }
    }
    int r, c;
    scanf("%d%d", &r, &c); // 确定输入格式
    return {r, c};
}