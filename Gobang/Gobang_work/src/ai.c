#include "head.h"
struct Treenode *scoreRoot;

// 先生成0层兄弟下的二叉树，然后统计每棵树的权，然后按照权排序添加兄弟

// 必须有一个节点后才能添加兄弟
void addBrother(int score, int x, int y, struct Treenode *root)
{
    struct Treenode *new;
    new = talloc();
    new->brother = new->son = NULL;
    new->depth = root->depth;
    new->x = x;
    new->y = y;
    // new->score=?
    treeBrotherSort(root, new);
}

void treeBrotherSort(struct Treenode *root, struct Treenode *new)
{
    if (root == NULL)
    {
        root->brother = new;
    }
    else if (root->score < new->score)
    {
        new->brother = root;
    }
    else
    {
        treeBrotherSort(root->brother, new);
    }
}
void addSon(int x, int y, struct Treenode *root)
{

    if (root == NULL)
    {
        root->depth = 0;
        root->x = x;
        root->y = y;
        // root->score=?
        root->son = root->brother = NULL;
    }
    else
    {
        struct Treenode *new;
        new = talloc();
        new->brother = new->son = NULL;
        // new->score=?
        new->depth = root->depth + 1;
        new->x = x;
        new->y = y;
        root->son = new;
    }
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
void depthupdate(struct Treenode *root)
{

    if (root != NULL)
    {
        root->depth = root->depth - 1;
        depthupdate(root->brother);
        depthupdate(root->son);
    }
    else
    {
        return;
    }
}
void freeTree(struct Treenode *brother)
{
    if (brother != NULL)
    {
        freeTree(brother->son);
        freeTree(brother->brother);
        free(brother);
    }
    else
    {
        return;
    }
}
void getbrotherScore(struct Treenode *root)
{
    root->score = sontreeScoreSum(root->son);
}
int sontreeScoreSum(struct Treenode *son)
{
    int temp = 0;
    if (son != NULL)
    {
        temp = son->score + sontreeScoreSum(son->son) + sontreeScoreSum(son->brother);
    }
    return temp;
}
struct Treenode *talloc(void)
{
    return (struct Treenode *)malloc(sizeof(struct Treenode));
}

int evolveLayers;
int ai(void)
{
    pos.x = rand() % SIZE + 1;
    pos.y = rand() % SIZE;
    ai_input(pos.x, pos.y);
    return 0;
}

void ai_input(int x, int y)
{
    gamestates.playerstate = !gamestates.playerstate;
    arrayForInnerBoardLayout[SIZE - x][y] = (!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
}

void socre(void)
{
    evolveLayers = 0;
    if (evolveLayers < MAXEVOLVELAYERS)
    {
        evolveLayers = evolveLayers + 1;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (arrayForInnerBoardLayout[i][j] == EMPTY)
                {
                }
            }
        }
    }
}