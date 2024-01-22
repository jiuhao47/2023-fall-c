#include <stdio.h>
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        j = i;
        k = 0;
        while (t[k] != '\0')
        {
            if (s[j] == t[k])
            {
                j++;
                k++;
            }
            else
            {
                break;
            }
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}