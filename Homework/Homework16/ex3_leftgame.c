#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int number;
    struct lnode *next;
};

void left(int n, int k);
struct lnode *lalloc();
struct lnode *buildliist(int n);
int main(int argc, char *argv[])
{
    int n, k;
    if (argc != 3 || (n = atoi(argv[1])) <= 0 || (k = atoi(argv[2])) <= 0)
    {
        printf("Usage: ./ex3_leftgame n k\n");
        return 1;
    }
    left(n, k);
    return 0;
}

void left(int n, int k)
{
    int count = 1;
    struct lnode *plist, *pre, *p;
    plist = buildliist(n);
    pre = plist;
    while (pre->next != plist)
    {
        pre = pre->next;
    }
    while (n > 0)
    {
        if (count % k == 0)
        {
            p = pre->next;
            pre->next = p->next;
            printf("%3d", p->number);
            free(p);
            n--;
        }
        else
        {
            pre = pre->next;
        }
        count;
    }
    printf("\n");
    return;
}

struct lnode *buildliist(int n)
{
    struct lnode *plist, *plast, *p;
    plist = lalloc();
    plist->number = n;
    plist->next = plist;
    plast = plist;
    while (--n > 0)
    {
        p = lalloc();
        p->number = n;
        p->next = plist;
        plist = p;
    }
    plast->next = plist;
    return plist;
}

struct lnode *lalloc()
{
    return (struct lnode *)malloc(sizeof(struct lnode));
}