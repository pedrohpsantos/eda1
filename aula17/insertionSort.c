#include <stdio.h>

void insertionSort(int list[], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
}
