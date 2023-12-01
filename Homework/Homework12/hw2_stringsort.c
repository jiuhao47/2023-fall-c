#include <stdio.h>
#define MAXLINES 5000
int readlines(char *linept[], int lim);
void writelines(char *lineptr[], int nlines);
void shellsort(char *s[]);

char *lineptr[MAXLINES];
int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        shellsort(lineptr);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}
