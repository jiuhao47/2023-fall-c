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
#define BLACK 0      // Black player
#define WHITE 1      // White player
#define BLACKCHESS 1
#define WHITECHESS 2
#define BLACKCHESSCURRENT 3
#define WHITECHESSCURRENT 4 // Chess code
#define MAXDEPTH 10
#define MAXWIDTH 10
#define BLACKNAME "Black"
#define WHITENAME "White"
#define WININFO "%s Win!\n"
#define INPUT_EXAMPLE " MOVE(%d,%d)" // Input example
#define INPUTCHESS_S "Input Chess Point:"
#define INPUTMODE_S "\n(1)Human Vs Human\n(2)Human(Black) Vs AI(White)\n(3)Human(White) Vs AI(BLACK)\n(4)AI Vs AI\n(5)AUTO CHECK\n\nInput Game Mode:"
#define ERROR_OUT_OF_RANGE "Input out of range, Please enter again!\n"
#define ERROR_ALREDY_HAVE "This place already has chess, Please enter again!\n"
#define MANUAL "1\n"
#define HUMANVSAI "2\n"
#define AIVSHUMAN "3\n"
#define AIVSAI "4\n"
#define AUTO "READY\n"
#define EXIT "quit\n" // State string
#define POSINF 100000000
#define INVINF -100000000
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
void displaychessshape(int *Board, int L, int M);
int mypow(int x, int n);
int weight(int x, int y);
int mymax(int x, int y);
int myabs(int x);
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
void updateHumanInput(void);
void updateAiInput(void);
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
void winHandle(int check);
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
void chessShapeToken(int x, int y, int *Board, int *chessshape);
// int checkempty(int x, int y, int mode, int i);
// judge.c
int ai_random(void);
int ai_tree(void);
void ai_input(int x, int y);
void ai_input_clear(int x, int y);
// extern struct Treenode *scoreRoot;
struct Treenode
{
    int alpha;
    int beta;
    int x;
    int y;
    struct Treenode *son;
    struct Treenode *brother;
};
void evolve(struct Treenode **scoreRoot);
struct Treenode *collect(struct Treenode *root, struct Treenode **scoreRoot);
struct Treenode *talloc(void);
void init_scoreRoot(struct Treenode **scoreRoot);
struct Treenode *freeTree_a(struct Treenode *root);
void getbrotherScore(struct Treenode *root);
struct Treenode *treeupdate(struct Treenode *root);
void addBrother(int score, int x, int y, struct Treenode *root);
struct Treenode *treeBrotherSort(struct Treenode *root, struct Treenode *new);
struct Treenode *addSon(int score, int x, int y, struct Treenode *root);
struct Treenode *treeupdate(struct Treenode *root);
void updateInnerBoardForScore(void);
// ai.c
int fourjudge_score(int x, int y, int mode, int *chessshape);
int judge_score(int x, int y, int *Board);
int threejudge_score(int x, int y, int mode, int *chessshape);
int twojudge_score(int x, int y, int mode, int *chessshape);

#define P_FIVEINROW 15000
#define P_FLEXFOUR 14000
#define P_FLEXTHREE 11000
#define P_DIRECTFOUR 10000
#define P_FLEXTWO 150
#define P_DIRECTTHREE 100
#define P_DIRECTTWO 1

#define P_DEADFOUR -100
#define P_DEADTHREE -10
#define P_DEADTWO -1
// 死棋的判断
#define FORBIDDEN -3000
#define OCCUPIED -2000
#define P_ONE 1

#endif