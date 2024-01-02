#include "ex1_myhead.h"

int main()
{
    struct tnode *ptree;
    char word[MAXWORD];
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
    return 0;
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