#include <stdio.h>
#define MAXLINES 5000
int readlines(char *linept[], int lim);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

char *lineptr[MAXLINES];
int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        qsort(lineptr, 0, nlines - 1);
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
