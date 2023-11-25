#include <stdio.h>
#define MAXLEN 1000
void shuffle(char *s, int m);
void swap(char *t);
int main()
{
    char input[1000];
    int m;
    printf("Enter a string:\n");
    scanf("%s", input);
    printf("Enter a number(m):\n");
    scanf("%d", &m);
    printf("%s\n", input);
    shuffle(input, m);
    printf("%s\n", input);
    return 0;
}
void shuffle(char *s, int m)
{
    for (int i = 0; i < m; i++)
    {
        int j = 0;
        while (*(s + j + 1) != '\0')
        {
            swap(s + j);
            j++;
        }
    }
}
void swap(char *t)
{
    char temp;
    temp = *t;
    *t = *(t + 1);
    *(t + 1) = temp;
}
