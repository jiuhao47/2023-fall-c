#ifndef _HEAD_H
#define _HEAD_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 15      // ChessBoardSize
#define CHARSIZE 2   // Single char size
#define LINEMAXLEN 6 // Input max length
#define BLACKCHESS 1
#define WHITECHESS 2
#define BLACKCHESSCURRENT 3
#define WHITECHESSCURRENT 4          // Chess code
#define INPUT_EXAMPLE " MOVE(%d,%d)" // Input example
#define MANUAL "START"
#define AUTO "READY"
#define EXIT "quit\n" // State string

void input(void);
void initRecordBoard(void);
void innerLayoutToDisplayArray(void);
void displayBoard(void);
void updatechesscurrent(void);
// chessboard.c

// functions.c

int mygetline(char s[], int lim);
int stateprocess(char line[]);
struct point inputprocess_manual(void);
struct point inputprocess_auto(void);
struct point
{
    int x;
    int y;
};
// inputprocess.c

void init_state(void);
void updateBoard(void);
void input(void);
// main.c

struct player
{
    int chess;
    int chesscurrent;
};
// player.c
struct gamestate
{
    int runningstate;
    int playerstate;
    int round;
};
extern struct gamestate gamestates;
extern int arrayForInnerBoardLayout[SIZE][SIZE];
// state.c
#endif