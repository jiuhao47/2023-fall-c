#ifndef _HEAD_H
#define _HEAD_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
typedef char int8;
typedef unsigned char uint8;
typedef int8 Player;
typedef int8 Piece;
*/
#define DIRECTION 4
#define SIZE 15      // ChessBoardSize
#define CHARSIZE 2   // Single char size
#define LINEMAXLEN 7 // Input max length
#define EMPTY 0      // Empty place
#define OCCUPIED 1   // Place occupied
#define BLACK 0      // Black player
#define WHITE 1      // White player
#define BLACKCHESS 1
#define WHITECHESS 2
#define BLACKCHESSCURRENT 3
#define WHITECHESSCURRENT 4 // Chess code
#define BLACKNAME "Black"
#define WHITENAME "White"
#define WININFO "%s Win!\n"
#define INPUT_EXAMPLE " MOVE(%d,%d)" // Input example
#define INPUTCHESS_S "Input Chess Point:"
#define INPUTMODE_S "Input Game Mode:"
#define ERROR_OUT_OF_RANGE "Input out of range, Please enter again!\n"
#define ERROR_ALREDY_HAVE "This place already has chess, Please enter again!\n"
#define MANUAL "\n"
#define AUTO "READY"
#define EXIT "quit\n" // State string

void input(void);
void initRecordBoard(void);
void innerLayoutToDisplayArray(void);
void displayBoard(void);
void updatechesscurrent(void);
extern int arrayForInnerBoardLayout[SIZE][SIZE];
// chessboard.c

int displayPosToInnerPos(int tempx, int tempy);
int mygetline(char s[], int lim);
int pointInBoard(int tempx, int tempy);
// functions.c

int stateprocess(char line[]);
void inputprocess_manual(void);
void inputprocess_auto(void);
struct point
{
    int x;
    int y;
};
extern struct point pos;
// inputprocess.c

void init_state(void);
void update(void);
void input(void);
// main.c

void initplayer(void);
// void arrayTransform(int player);
struct player
{
    int arrayForInnerMind[SIZE][SIZE];
};
extern struct player black, white;
// player.c
void ErrorHandle(void);
void InfoDisplay(void);
struct gamestate
{
    int runningstate;
    int playerstate;
    int round;
};
extern struct gamestate gamestates;

// state.c
int chainjudge(int *chessshape);
int chainjudge_mode(int mode, int *chessshape);
int judge(int x, int y);
void gamejudger(void);
int doublefourjudge(int x, int y, int *chessshape);
int fourjudge(int x, int y, int mode, int *chessshape);
int doublethreejudge(int x, int y, int *chessshape);
int threejudge(int x, int y, int mode, int *chessshape);
// int checkempty(int x, int y, int mode, int i);

// judge.c

void chessShapeToken(int x, int y, int *Board, int *chessshape);
void statedisplay(int *chessshape);
void displaychessshape(int *Board, int L, int M);

// extern int check_507745524;
#endif