#include "ex2_myhead.h"

int getword(char *word, int lim)
{
    static char *p = filebuf;
    char *w = word;
    while (p < (filebuf + size) && isspace(*p))
    {
        p++;
    }
    if (p == (filebuf + size) || *p == '\0')
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