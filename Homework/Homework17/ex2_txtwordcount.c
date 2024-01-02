#include "ex2_myhead.h"

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
            printf("Enter");
            ptree = addtree(ptree, word);
        }
    }
    /*
    for (int i = 0; i < MAXWORD; i++)
    {
        printf("%d", word[i]);
    }
    */
    printf("the results are:\n");
    treeprint(ptree);
}

struct tnode *addtree(struct tnode *ptree, char *word)
{
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