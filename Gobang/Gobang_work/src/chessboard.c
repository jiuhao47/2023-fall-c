#include "head.h"
// Empty ChessBoard
char arrayForEmptyBoard[SIZE][SIZE * CHARSIZE + 1] =
    {
        "���өөөөөөөөөөөөө�",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "�ĩ��������������",
        "���۩۩۩۩۩۩۩۩۩۩۩۩۩�"};
// ChessBoard_display

char play1Pic[] = "��"; // ������;
char play1CurrentPic[] = "��";
char play2Pic[] = "��"; // ������;
char play2CurrentPic[] = "��";
char arrayForDisplayBoard[SIZE][SIZE * CHARSIZE + 1];

// Current ChessBoard
int arrayForInnerBoardLayout[SIZE][SIZE];

// ChessBoard_inner_initialize
void initRecordBoard(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arrayForInnerBoardLayout[i][j] = 0;
        }
    }
}

// Copy ChessBoard_inner to ChessBoard_display
void innerLayoutToDisplayArray(void)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE * CHARSIZE + 1; j++)
        {
            arrayForDisplayBoard[i][j] = arrayForEmptyBoard[i][j];
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((arrayForInnerBoardLayout[i][j] == BLACKCHESS) || (arrayForInnerBoardLayout[i][j] == BLACKCHESSCURRENT))
            {
                arrayForDisplayBoard[i][j * CHARSIZE] = play1Pic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play1Pic[1];
                if (CHARSIZE == 3)
                {
                    arrayForDisplayBoard[i][j * CHARSIZE + 2] = play1Pic[2];
                }
                arrayForInnerBoardLayout[i][j] = BLACKCHESS;
            }

            if ((arrayForInnerBoardLayout[i][j] == WHITECHESS) || (arrayForInnerBoardLayout[i][j] == WHITECHESSCURRENT))
            {
                arrayForDisplayBoard[i][j * CHARSIZE] = play2Pic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play2Pic[1];
                if (CHARSIZE == 3)
                {
                    arrayForDisplayBoard[i][j * CHARSIZE + 2] = play2Pic[2];
                }
                arrayForInnerBoardLayout[i][j] = WHITECHESS;
            }
        }
    }
}

void updatechesscurrent(void)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (arrayForInnerBoardLayout[i][j] == BLACKCHESSCURRENT)
            {

                arrayForDisplayBoard[i][j * CHARSIZE] = play1CurrentPic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play1CurrentPic[1];
                if (CHARSIZE == 3)
                {
                    arrayForDisplayBoard[i][j * CHARSIZE + 2] = play1CurrentPic[2];
                }
            }
            if (arrayForInnerBoardLayout[i][j] == WHITECHESSCURRENT)
            {
                arrayForDisplayBoard[i][j * CHARSIZE] = play2CurrentPic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play2CurrentPic[1];
                if (CHARSIZE == 3)
                {
                    arrayForDisplayBoard[i][j * CHARSIZE + 2] = play2CurrentPic[2];
                }
            }
        }
    }
}

// Display ChessBoard
void displayBoard(void)
{
    int i;
    // system("clear");
    for (int i = 0; i < 15; i++)
    {
        // printf("%s\n", arrayForEmptyBoard[i]);
        printf("%3d %s\n", SIZE - i, arrayForDisplayBoard[i]);
    }
    printf("    ");
    for (int i = 0; i < 15; i++)
    {
        printf("%2c", 'A' + i);
    }
    printf("\n");
}

void updateBoard(void)
{
    innerLayoutToDisplayArray();
    input();
    updatechesscurrent();
    displayBoard();
}