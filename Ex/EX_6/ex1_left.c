#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int number;
    struct lnode *next;
};

void left(int n, int k, int t);
struct lnode *lalloc();
struct lnode *buildliist(int n);
int main(int argc, char *argv[])
{
    int n, k, t;
    if (argc != 4 || (n = atoi(argv[1])) <= 0 || (k = atoi(argv[2])) <= 0 || (t = atoi(argv[3])) <= 0)
    {
        printf("Usage: ./ex3_leftgame n k t\n");
        return 1;
    }
    left(n, k, t);
    return 0;
}

void left(int n, int k, int t)
{
    int count = 1;
    int num = n;
    struct lnode *plist, *pre, *p;
    plist = buildliist(n);
    pre = plist;
    while (pre->next != plist)
    {
        pre = pre->next;
    }
    while (n > 0)
    {
        if (count % k == k - 1)
        {

            p = pre->next;
            pre->next = p->next;
            if (num-- <= t)
            {
                printf("%3d", p->number);
            }
            free(p);
            n--;
        }
        else
        {
            pre = pre->next;
        }
        count++;
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