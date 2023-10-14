#include <stdio.h>
#define MAXLEN 10
void insertion_sort(int arr[], int len);
int main()
{
    int i;
    int data_array[MAXLEN] = {6, 5, 4, 3, 2, 1};
    insertion_sort(data_array, MAXLEN);
    for (i = 0; i < MAXLEN; i++)
    {

        printf("%d ", data_array[i]);
    }
    printf("\n");
    return 0;
}
void insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}