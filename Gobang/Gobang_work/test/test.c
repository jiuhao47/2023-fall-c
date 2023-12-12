#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANUAL "START"
#define AUTO "READY"
#define EXIT "EXIT"

int runningstate;
int playerstate;

int main()
{
    printf("%d", strcmp("EXIT\n", EXIT));
}
