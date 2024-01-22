#include <stdio.h>
int shellsort(int s[], int len);
int main()
{
    return 0;
}
int shellsort(int s[], int len)
{
    int i, j, gap;
    int temp;
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < len; i += 1)
        {
            for (j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap)
            {
                temp = s[j + gap];
                s[j + gap] = s[j];
                s[j] = temp;
            }
        }
    }
}