#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 100
int atoihex(char s[]);
int atoidec(char s[]);
int atoioct(char s[]);
int atoibin(char s[]);
int ishex(char s[]);
int isoct(char s[]);
int isbin(char s[]);
int isdec(char s[]);

int main()
{
    char input[MAXLENGTH];
    int output;
    scanf("%100s", &input);
    if (ishex(input))
    {
        output = atoihex(input);
        printf("Output=%d", output);
    }
    else if (isbin(input))
    {
        output = atoibin(input);
        printf("Output=%d", output);
    }
    else if (isoct(input))
    {
        output = atoioct(input);
        printf("Output=%d", output);
    }
    else if (isdec(input))
    {
        output = atoidec(input);
        printf("Output=%d", output);
    }
    else
    {
        printf("Error: inlegal input");
    }
}

int ishex(char s[])
{
    int i = 2;
    if (s[0] == '0' && s[1] == 'x' && s[2] != '\0')
    {
        while (s[i] != '\0')
        {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
            {
                if (s[i] >= 'A' && s[i] <= 'F')
                {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
            else
            {
                return 0;
            }
            i++;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}
int isoct(char s[])
{
    int i = 1;
    if (s[0] == '0' && s[1] != '\0')
    {
        while (s[i] != '\0')
        {
            if (s[i] >= '0' && s[i] <= '7')
            {
                ;
            }
            else
            {
                return 0;
            }
            i++;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}
int isbin(char s[])
{
    int i = 2;
    if (s[0] == '0' && s[1] == 'b' && s[2] != '\0')
    {
        while (s[i] != '\0')
        {
            if (s[i] >= '0' && s[i] <= '1')
            {
                ;
            }
            else
            {
                return 0;
            }
            i++;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}
int isdec(char s[])
{
    int i = 0;
    if (isdigit(s[0]))
    {
        while (s[i] != '\0')
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ;
            }
            else
            {
                return 0;
            }
            i++;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int atoihex(char s[])
{
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            sum = sum * 16 + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            sum = sum * 16 + (s[i] - 'a') + 10;
        }
        i++;
    }
    return sum;
}
int atoidec(char s[])
{
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            sum = sum * 10 + (s[i] - '0');
        }
        i++;
    }
    return sum;
}
int atoioct(char s[])
{
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= '7' && s[i] >= '0')
        {
            sum = sum * 8 + (s[i] - '0');
        }
        i++;
    }
    return sum;
}
int atoibin(char s[])
{
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= '1' && s[i] >= '0')
        {
            sum = sum * 2 + (s[i] - '0');
        }
        i++;
    }
    return sum;
}