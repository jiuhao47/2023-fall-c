#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100
struct lnode
{
    int data;
    struct lnode *next;
};

struct lnode *lalloc(void);
struct lnode *lalloc(void)
{
    return (struct lnode *)malloc(sizeof(struct lnode));
}
void printlist(struct lnode *plist);
void printlist(struct lnode *plist)
{
    struct lnode *pnode;
    pnode = plist;
    while (pnode != NULL)
    {
        printf("%3d ", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}
struct lnode *addnode(struct lnode *plist, char *word);
struct lnode *addnode(struct lnode *plist, char *word)
{
    struct lnode *p;
    p = lalloc();
    p->data = atoi(word);
    p->next = plist;
    plist = p;
    return plist;
}
int getword(char *word, int lim);
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
    {
        ;
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isdigit(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c);
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch:too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
void selectsort(struct lnode *plist);
void selectsort(struct lnode *plist)
{
    struct lnode *p, *q, *temp;
    p = plist;
    q = plist;

    int tempmax;
    while (p->next != NULL)
    {

        while (q != NULL)
        {
            if (tempmax < q->data)
            {
                tempmax = q->data;
                temp = q;
            }
            q = q->next;
        }
        temp->data = p->data;
        p->data = tempmax;
        p = p->next;
        q = p;
        tempmax = 0;
    }
}

void main(int argc, char *argv[])
{
    int n;
    if (argc != 2 || (n = atoi(argv[1])) <= 0)
    {
        printf("Usage: ./chainsort n\n");
        return;
    }
    struct lnode *plist;
    plist = NULL;
    char word[n];
    while (getword(word, n) != EOF)
    {
        // printf("%s\n", word);
        if (isdigit(word[0]))
        {
            plist = addnode(plist, word);
        }
    }
    selectsort(plist);
    printf("the results are:\n");
    printlist(plist);
    return;
}