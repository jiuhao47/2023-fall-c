#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 3
void initRecordBorard(void);
void innerLayoutToDisplayArray(void);
void displayBoard(void);
int put1(void);
int put2(void);
int mygetline(char s[], int lim);
int checkwin(int i, int j);

// 棋盘使用的是UTF8编码，每一个中文字符占用3个字节。

// 空棋盘模板
char arrayForEmptyBoard[SIZE][SIZE * CHARSIZE + 1] =
    {
        "┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"};
// 此数组存储用于显示的棋盘
char arrayForDisplayBoard[SIZE][SIZE * CHARSIZE + 1];

char play1Pic[] = "●"; // 黑棋子;
char play1CurrentPic[] = "▲";

char play2Pic[] = "◎"; // 白棋子;
char play2CurrentPic[] = "△";

// 此数组用于记录当前的棋盘的格局
int arrayForInnerBoardLayout[SIZE][SIZE];

int main()
{
    initRecordBorard(); // 初始化一个空棋盘
    innerLayoutToDisplayArray();
    displayBoard();
    int i = 1;
    while (1)
    {
        printf("Player1,please!\n");
        innerLayoutToDisplayArray();
        i = put1();
        displayBoard();
        if (i == 2)
        {
            printf("玩家一胜利！\n");
            break;
        }
        if (i == 0)
            break;
        innerLayoutToDisplayArray();
        printf("Player2,please!\n");
        i = put2();
        displayBoard();
        if (i == 2)
        {
            printf("玩家二胜利！\n");
            break;
        }
        if (i == 0)
            break;
    }
    return 0;
}

// 初始化一个空棋盘格局
void initRecordBorard(void)
{
    // 通过双重循环，将arrayForInnerBoardLayout清0
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            arrayForInnerBoardLayout[i][j] = 0;
}

// 将arrayForInnerBoardLayout中记录的棋子位置，转化到arrayForDisplayBoard中
void innerLayoutToDisplayArray(void)
{
    // 第一步：将arrayForEmptyBoard中记录的空棋盘，复制到arrayForDisplayBoard中
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j <= SIZE * CHARSIZE + 1; j++)
            arrayForDisplayBoard[i][j] = arrayForEmptyBoard[i][j];
    }

    // 第二步：扫描arrayForInnerBoardLayout，当遇到非0的元素，将●或者◎复制到arrayForDisplayBoard的相应位置上
    // 注意：arrayForDisplayBoard所记录的字符是中文字符，每个字符占2个字节。●和◎也是中文字符，每个也占2个字节。
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                arrayForDisplayBoard[i][CHARSIZE * j] = play1Pic[0];
                arrayForDisplayBoard[i][CHARSIZE * j + 1] = play1Pic[1];
                if (CHARSIZE == 3)
                    arrayForDisplayBoard[i][CHARSIZE * j + 2] = play1Pic[2];
            }
            else if (arrayForInnerBoardLayout[i][j] == 2)
            {
                arrayForDisplayBoard[i][CHARSIZE * j] = play2Pic[0];
                arrayForDisplayBoard[i][CHARSIZE * j + 1] = play2Pic[1];
                if (CHARSIZE == 3)
                    arrayForDisplayBoard[i][CHARSIZE * j + 2] = play2Pic[2];
            }
    }
}

// 显示棋盘格局
void displayBoard(void)
{
    int i;
    // 第一步：清屏
    // system("clear"); // 清屏
    // 第二步：将arrayForDisplay0Board输出到屏幕上
    for (i = 0; i < SIZE; i++)
    {
        printf("%3d %s\n", SIZE - i, arrayForDisplayBoard[i]);
    }

    // 第三步：输出最下面的一行字母A B ....
    printf("  ");
    for (i = 0; i < SIZE; i++)
        printf("%2c", 'A' + i);
    printf("\n");
}

int put1(void)
{
    while (1)
    {
        char line[5];
        mygetline(line, 5);
        int m = -1, n = -1;
        int i = 0;
        if (line[0] == 'q' && line[1] == 'u' && line[2] == 'i' && line[3] == 't')
            return 0;
        if (strlen(line) == 2)
        {
            if (line[0] - '0' > 0 && line[0] - '0' < 10)
            {
                if (line[1] - 'a' >= 0 && line[1] - 'a' < 15)
                {
                    m = 15 - (line[0] - '0');
                    n = line[1] - 'a';
                    i = 1;
                }
            }
            else if (line[1] - '0' > 0 && line[1] - '0' < 10)
            {
                if (line[0] - 'a' >= 0 && line[0] - 'a' < 15)
                {
                    m = 15 - (line[1] - '0');
                    n = line[0] - 'a';
                    i = 1;
                }
            }
        }
        else if (strlen(line) == 3)
        {
            if (line[0] - '0' > 0 && line[0] - '0' < 10)
            {
                if (line[2] - 'a' >= 0 && line[2] - 'a' < 15)
                {
                    m = 15 - (10 + (line[1] - '0'));
                    n = line[2] - 'a';
                    i = 1;
                }
            }
            else if (line[2] - '0' > 0 && line[2] - '0' < 10)
            {
                if (line[0] - 'a' >= 0 && line[0] - 'a' < 15)
                {
                    m = 15 - (10 + (line[2] - '0'));
                    n = line[0] - 'a';
                    i = 1;
                }
            }
        }

        if (m >= 0 && m < 15 && n >= 0 && n < 15)
        {
            if (arrayForInnerBoardLayout[m][n] == 0)
            {
                arrayForInnerBoardLayout[m][n] = 1;
            }
            else
            {
                printf("此处不可落子\n");
                i = 0;
            }
        }
        else
        {
            printf("请输入正确的坐标\n");
            i = 0;
        }
        if (i == 0)
        {
            printf("请输入正确的坐标。\n");
            i = 0;
        }
        if (i == 1)
        {
            strncpy(arrayForDisplayBoard[m] + n * CHARSIZE, play1CurrentPic, CHARSIZE);
            int w;
            w = checkwin(m, n);
            if (w == 1)
            {
                return 2;
            }
            if (w == 2)
            {
                return 2;
            }
            return 1;
        }
    }
}

int put2(void)
{
    while (1)
    {
        char line[5];
        mygetline(line, 5);
        int m = -1, n = -1;
        int i = 0;
        if (line[0] == 'q' && line[1] == 'u' && line[2] == 'i' && line[3] == 't')
            return 0;
        if (strlen(line) == 2)
        {
            if (line[0] - '0' > 0 && line[0] - '0' < 10)
            {
                if (line[1] - 'a' >= 0 && line[1] - 'a' < 15)
                {
                    m = 15 - (line[0] - '0');
                    n = line[1] - 'a';
                    i = 1;
                }
            }
            else if (line[1] - '0' > 0 && line[1] - '0' < 10)
            {
                if (line[0] - 'a' >= 0 && line[0] - 'a' < 15)
                {
                    m = 15 - (line[1] - '0');
                    n = line[0] - 'a';
                    i = 1;
                }
            }
        }
        else if (strlen(line) == 3)
        {
            if (line[0] - '0' > 0 && line[0] - '0' < 10)
            {
                if (line[2] - 'a' >= 0 && line[2] - 'a' < 15)
                {
                    m = 15 - (10 + (line[1] - '0'));
                    n = line[2] - 'a';
                    i = 1;
                }
            }
            else if (line[2] - '0' > 0 && line[2] - '0' < 10)
            {
                if (line[0] - 'a' >= 0 && line[0] - 'a' < 15)
                {
                    m = 15 - (10 + (line[2] - '0'));
                    n = line[0] - 'a';
                    i = 1;
                }
            }
        }

        if (m >= 0 && m < 15 && n >= 0 && n < 15)
        {
            if (arrayForInnerBoardLayout[m][n] == 0)
            {
                arrayForInnerBoardLayout[m][n] = 2;
            }
            else
            {
                printf("此处不可落子\n");
                i = 0;
            }
        }
        else
        {
            printf("请输入正确的坐标\n");
            i = 0;
        }
        if (i == 0)
        {
            printf("请输入正确的坐标。\n");
            i = 0;
        }
        if (i == 1)
        {
            strncpy(arrayForDisplayBoard[m] + n * CHARSIZE, play2CurrentPic, CHARSIZE);
            int w;
            w = checkwin(m, n);
            if (w == 1)
            {
                return 2;
            }
            if (w == 2)
            {
                return 2;
            }
            return 1;
        }
    }
}

int mygetline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int checkwin(int m, int n)
{
    int num1 = -1, num2 = -1;
    int i;
    int j = n;
    if (arrayForInnerBoardLayout[m][n] == 1)
    {
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
                ++num1;
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        for (i = m; i < SIZE; --i)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
                ++num1;
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num1 == 5)
            return 1;
        if (num1 != 5)
        {
            num1 = -1;
            i = m;
        }
        for (j = n; j < SIZE; ++j)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
                ++num1;
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        for (j = n; j < SIZE; --j)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
                ++num1;
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num1 == 5)
            return 1;
        if (num1 != 5)
        {
            num1 = -1;
            i = m;
            j = n;
        }
        printf("beforenum1=%d\n", num1);
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                ++num1;
                ++j;
            }
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        printf("nextnum1=%d\n", num1);
        i = m;
        j = n;

        for (i = m; i < SIZE; --i)
        {

            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    printf("%2d", arrayForInnerBoardLayout[i][j]);
                }
                printf("\n");
            }

            printf("arrayfor=%d\n", arrayForInnerBoardLayout[i][j]);
            printf("--arrayfor=%d\n", arrayForInnerBoardLayout[i - 1][j - 1]);
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                printf("Enter\n");
                ++num1;
                j = j - 1;
            }
            if (arrayForInnerBoardLayout[i][j] == 2)
            {

                printf("Enter2\n");
                break;
            }
            if (arrayForInnerBoardLayout[i][j] == 0)
            {
                printf("Enter0\n");
                break;
            }
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
            {
                printf("Enter out of range\n");
                break;
            }
        }
        printf("num1=%d\n", num1);
        if (num1 == 5)
            return 1;
        if (num1 != 5)
        {
            num1 = -1;
            i = m;
            j = n;
        }
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                ++num1;
                --j;
            }
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        i = m;
        j = n;
        for (i = m; i < SIZE; --i)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                ++num1;
                ++j;
            }
            if (arrayForInnerBoardLayout[i][j] == 2)
                break;
            if (arrayForDisplayBoard[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num1 == 5)
            return 1;
        if (num1 != 5)
        {
            num1 = -1;
            i = m;
            j = n;
        }
    }

    if (arrayForDisplayBoard[m][n] == 2)
    {
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
                ++num2;
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        i = m;
        j = n;
        for (i = m; i < SIZE; --i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
                ++num2;
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num2 == 5)
            return 2;
        if (num2 != 5)
        {
            num2 = -1;
            i = m;
            j = n;
        }
        for (j = n; j < SIZE; ++j)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
                ++num2;
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        i = m;
        j = n;
        for (j = n; j < SIZE; --j)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
                ++num2;
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num2 == 5)
            return 2;
        if (num2 != 5)
        {
            num2 = -1;
            i = m;
            j = n;
        }
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
            {
                ++num2;
                ++j;
            }
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        i = m;
        j = n;
        for (i = m; i < SIZE; --i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
            {
                ++num2;
                --j;
            }
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num2 == 5)
            return 2;
        if (num2 != 5)
        {
            num2 = -1;
            i = m;
            j = n;
        }
        for (i = m; i < SIZE; ++i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
            {
                ++num2;
                --j;
            }
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        i = m;
        j = n;
        for (i = m; i < SIZE; --i)
        {
            if (arrayForInnerBoardLayout[i][j] == 2)
            {
                ++num2;
                ++j;
            }
            if (arrayForInnerBoardLayout[i][j] == 1)
                break;
            if (arrayForInnerBoardLayout[i][j] == 0)
                break;
            if (i < 0 || i >= 15 || j < 0 || j >= 15)
                break;
        }
        if (num2 == 5)
            return 2;
        if (num2 != 5)
        {
            num2 = -1;
            i = m;
            j = n;
        }

        return 0;
    }
}
