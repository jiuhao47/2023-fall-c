#include <stdio.h>
#define MAXLINE 100
char pattern[] = "ould";
int mygetline(char s[], int lim);
int strindex(char s[], char t[]);
int main()
{
    char line[MAXLINE];
    int found = 0;
    while (mygetline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }
    return found;
}
#include <stdio.h>
#define MAXLINE 100
char pattern[] = "ould";
int mygetline(char s[], int lim);
int strindex(char s[], char t[]);
int main()
{
    char line[MAXLINE];
    int found = 0;
    while (mygetline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }
    return found;
}