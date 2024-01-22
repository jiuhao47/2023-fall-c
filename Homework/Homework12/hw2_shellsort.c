#include <string.h>
void shellsort(char *s[])
{
    int mystrlen(char *s[]);
    void swap(char *v[], int i, int j);
    int i, j, gap;
    int temp;
    int len = mystrlen(s);
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < len; i += 1)
        {
            for (j = i - gap; j >= 0 && strcmp(s[j], s[j + gap]) > 0; j -= gap)
            {
                swap(s, j, j + gap);
            }
        }
    }
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int mystrlen(char *s[])
{
    int i = 0;
    while (s[i])
    {
        i = i + 1;
    }
    return i;
}
