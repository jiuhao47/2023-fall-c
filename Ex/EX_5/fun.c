#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1000
int mygetline(char *line, int max);
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0, arg_num = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            arg_num = (isdigit(c) && c != '0') ? c - '0' : 0;
            if (arg_num)
            {
                ;
            }
            else
            {
                switch (c)
                {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option%c\n", c);
                    argc = 0;
                    found = -1;
                    break;
                }
            }
        }
    }
    if (argc != 1)
    {
        printf("Usage: find -x -n pattern\n");
    }
    else
    {
        while (mygetline(line, MAXLINE) > 0)
        {
            int temp = 0;
            lineno++;
            char *p;
            p = line;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (except)
                {
                    temp = 0;
                }
                else
                {
                    //++temp;
                    while ((p != NULL) != except)
                    {
                        p = strstr((p + strlen(*argv)), *argv);
                        ++temp;
                    }
                }
            }

            if ((except && (temp < arg_num)) || (!except && (temp >= arg_num)))
            {
                printf("%d\n%d\n", arg_num, temp);
                if (number)
                {
                    printf("%ld", lineno);
                }
                printf("%s", line);
                found++;
            }
            //
        }
    }
    return found;
}

int mygetline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}
