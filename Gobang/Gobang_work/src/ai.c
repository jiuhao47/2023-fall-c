#include "head.h"
struct Treenode *scoreRoot[SIZE][SIZE];
struct Treenode *scoreRoot_oppo_temp[SIZE][SIZE];
struct Treenode *scoreRoot_depth_temp[SIZE][SIZE];
struct Treenode *root = NULL;
struct Treenode *root_temp = NULL;
int arrayForInnerBoardForScore[SIZE][SIZE];

void updateInnerBoardForScore(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arrayForInnerBoardForScore[i][j] = arrayForInnerBoardLayout[i][j];
        }
    }
}
void init_scoreRoot(struct Treenode **scoreRoot)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scoreRoot[i * SIZE + j] = NULL;
        }
    }
}

// 先生成0层兄弟下的二叉树，然后统计每棵树的权，然后按照权排序添加兄弟

// 必须有一个节点后才能添加兄弟
void addBrother(int score, int x, int y, struct Treenode *root)
{
    struct Treenode *new;
    new = talloc();
    new->brother = new->son = NULL;
    new->x = x;
    new->y = y;
    new->alpha = INVINF;
    new->beta = POSINF;
    treeBrotherSort(root, new);
}
/*
struct Treenode *treeBrotherSort(struct Treenode *root, struct Treenode *new)
{
    struct Treenode *temp_pre;
    struct Treenode *temp_root;
    temp_root = root;
    if (root == NULL)
    {
        root = new;
        new->brother = NULL;
        return root;
    }
    while ((new->score <= temp_root->score) && (temp_root->brother != NULL))
    {
        temp_pre = temp_root;
        temp_root = temp_pre->brother;
    }

    if (new->score > temp_root->score)
    {
        if (temp_root == root)
        {
            root = new;
            new->brother = temp_root;
        }
        else
        {
            temp_pre->brother = new;
            new->brother = temp_root;
        }
    }
    else
    {
        temp_root->brother = new;
        new->brother = NULL;
    }
    return root;
}
*/
struct Treenode *addSon(int alpha, int beta, int x, int y, struct Treenode *root)
{
    if (root == NULL)
    {
        root = talloc();
        root->depth = 0;
        root->x = x;
        root->y = y;
        root->score = score;
        root->son = root->brother = NULL;
    }
    else
    {
        struct Treenode *temp = root;
        while (temp->son != NULL)
        {
            temp = temp->son;
        }
        struct Treenode *new;
        new = talloc();
        new->brother = new->son = NULL;
        new->score = score;
        new->depth = temp->depth + 1;
        new->x = x;
        new->y = y;
        temp->son = new;
    }
    return root;
}
struct Treenode *freeTree_a(struct Treenode *root)
{
    if (root == NULL)
    {
        return root;
    }
    freeTree_a(root->brother);
    freeTree_a(root->son);
    free(root);
}
struct Treenode *treeupdate(struct Treenode *root)
{
    if (root != NULL)
    {
        struct Treenode *temp = root;
        free(root);
        depthupdate(temp->son);
        freeTree(temp->brother);
        return temp->son;
    }
    else
    {
        return NULL;
    }
}
void getbrotherScore(struct Treenode *root)
{
    // if (root != NULL)
    //  判断条件为避免空指针调用临时添加，可以删除寻找原因
    root->score = root->score + sontreeScoreSum(root->son);
}
struct Treenode *talloc(void)
{
    return (struct Treenode *)malloc(sizeof(struct Treenode));
}
/*
void evolve(struct Treenode **scoreRoot)
{
    int kill_mine = 0;
    int kill_oppo = 0;
    int score = 0;
    int score_mine = 0;
    int score_oppo = 0;
    updateInnerBoardForScore();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (arrayForInnerBoardForScore[i][j] == EMPTY)
            {
                arrayForInnerBoardForScore[i][j] = (!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS;
                score_mine = judge_score(SIZE - i, j, arrayForInnerBoardForScore[0]);
                kill_mine = (score_mine >= P_DIRECTFOUR) ? 5 : 1;
                arrayForInnerBoardForScore[i][j] = EMPTY;
                gamestates.playerstate = !gamestates.playerstate;
                arrayForInnerBoardForScore[i][j] = (!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS;
                score_oppo = judge_score(SIZE - i, j, arrayForInnerBoardForScore[0]);
                kill_oppo = (score_oppo >= P_DIRECTFOUR) ? 5 : 1;
                gamestates.playerstate = !gamestates.playerstate;
                score = score_mine * kill_mine + score_oppo * kill_oppo;
                scoreRoot[i * SIZE + j] = addSon(score, i, j, scoreRoot[i * SIZE + j]);
                arrayForInnerBoardForScore[i][j] = EMPTY;
            }
            else
            {
                score = OCCUPIED;
                if ((scoreRoot[i * SIZE + j] == NULL) || (scoreRoot[i * SIZE + j]->score > 0))
                    scoreRoot[i * SIZE + j] = addSon(score, i, j, scoreRoot[i * SIZE + j]);
            }
        }
    }
}
*/
/*
struct Treenode *collect(struct Treenode *root, struct Treenode **scoreRoot)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            getbrotherScore(scoreRoot[i * SIZE + j]);
            scoreRoot[i * SIZE + j]->score = scoreRoot[i * SIZE + j]->score + weight(i, j);

            root = treeBrotherSort(root, scoreRoot[i * SIZE + j]);
        }
    }
    return root;
}
*/
int ai_tree(void)
{
    gamestates.playerstate = !gamestates.playerstate;
    printf("Playerstates=%d\n", gamestates.playerstate);

    init_scoreRoot(scoreRoot[0]);
    evolve(scoreRoot[0]);
    root = collect(root, scoreRoot[0]);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%10d ", scoreRoot[i][j]->score);
        }
        printf("\n");
    }
    // SIZE-这里优化会出bug，回头修一下
    pos.x = SIZE - root->x;
    pos.y = root->y;
    freeTree_a(root);
    ai_input(SIZE - pos.x, pos.y);
}

int ai_random(void)
{
    pos.x = rand() % SIZE + 1;
    pos.y = rand() % SIZE;
    ai_input(pos.x, pos.y);
    return 0;
}

void ai_input(int x, int y)
{
    arrayForInnerBoardLayout[x][y] = (!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
}
void ai_input_clear(int x, int y)
{
    arrayForInnerBoardLayout[x][y] = EMPTY;
}