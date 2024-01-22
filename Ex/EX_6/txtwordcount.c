
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXWORD 100
#define BUFLEN 10000

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
char *mystrdup(char *s);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *ptree, char *word);
void treeprint(struct tnode *ptree);
int getword(char *word, int lim);
extern char filebuf[BUFLEN];
extern int size;

char filebuf[BUFLEN];
int size;
int main(int argc, char *argv[])
{
    struct tnode *ptree;
    char word[MAXWORD];
    int fd;
    if (argc != 2)
    {
        printf("Error. Please enter: ./countwords filename\n");
        return 1;
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Error. Cannot find file \'%s\'\n", argv[1]);
    }
    size = read(fd, filebuf, BUFLEN);
    close(fd);

    ptree = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            ptree = addtree(ptree, word);
        }
    }
    printf("the results are:\n");
    treeprint(ptree);
}

struct tnode *addtree(struct tnode *ptree, char *word)
{
    /*
    struct tnode *p, *q;
    int cmpresult;
    if (ptree == NULL)
    {
        p = talloc();
        p->word = mystrdup(word);
        p->count = 1;
        p->left = p->right = NULL;
        return p;
    }
    q = ptree;
    while (q != NULL)
    {
        if (cmpresult = strcmp(word, ptree->word) == 0)
        {
            q->count++;
        }
        else if (cmpresult < 0)
        {
            if (ptree->left == NULL)
            {
                p = talloc();
                p->word = mystrdup(word);
                p->count = 1;
                p->left = p->right = NULL;
                q->left = p;

                return ptree;
            }
            else
            {
                q = q->left;
            }
        }
        else if (cmpresult > 0)
        {
            if (ptree->right == NULL)
            {
                p = talloc();
                p->word = mystrdup(word);
                p->count = 1;
                p->left = p->right = NULL;
                q->right = p;

                return ptree;
            }
            else
            {
                q = q->right;
            }
        }
    }
    */
    struct tnode *p;
    int cmpresult;
    if (ptree == NULL)
    {
        p = talloc();
        p->word = mystrdup(word);
        p->count = 1;
        p->left = p->right = NULL;
        return p;
    }
    if ((cmpresult = strcmp(word, ptree->word)) == 0)
    {
        ptree->count++;
    }
    else if (cmpresult < 0)
    {
        ptree->left = addtree(ptree->left, word);
    }
    else
    {
        ptree->right = addtree(ptree->right, word);
    }
    return ptree;
}

void treeprint(struct tnode *ptree)
{
    if (ptree)
    {
        treeprint(ptree->left);
        printf("%4d %s\n", ptree->count, ptree->word);
        treeprint(ptree->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *mystrdup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

int getword(char *word, int lim)
{
    static char *p = filebuf;
    char *w = word;
    while (p < (filebuf + size) && isspace(*p))
    {
        p++;
    }
    if (p == (filebuf + size) || (*p = '\0'))
    {
        return EOF;
    }
    *w++ = *p;
    if (!isalpha(*p))
    {
        *w = '\0';
        return *p++;
    }
    for (; ++p < (filebuf + size) && --lim > 0; w++)
    {
        if (!isalnum(*w = *p))
        {
            break;
        }
    }
    *w = '\0';
    return word[0];
}