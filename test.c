#include <stdio.h>
int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p;
    p = array;
    printf("*p=%d\t *++p=%d\t *p=%d\t \n", *p, *++p, *p);
    printf("*p=%d\t p[3]=%d\t *p=%d\t \n", *p, p[3], *p);
    printf("*p=%d\t p++[2]=%d\t *p=%d\t \n", *p, p++[2], *p);
    printf("*p=%d\t *(p+=3)=%d\t *p=%d\t \n", *p, *(p += 3), *p);
    printf("*p=%d\t *p+=2=%d\t *p=%d\t \n", *p, *p += 2, *p);
    printf("*p=%d\n", *p);
    printf("*p=%d\t *p++=%d\t *p=%d\t \n", *p, *p++, *p);
    printf("*p=%d\n", *p);
    printf("*p=%d\t p[1]=%d\t *p=%d\t \n", *p, p[1], *p);
    printf("*p=%d\t p[3]=%d\t *p=%d\t \n", *p, p[3], *p);
    return 0;
}