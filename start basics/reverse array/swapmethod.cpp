#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main()
{
    int arr[11] = {0,
                   1,
                   2,
                   3,
                   4,
                   5,
                   6,
                   7,
                   8,
                   9,
                   10};

    int i = 0, j = 10;
    while (i < j)
    {
        swap(&arr[i], &arr[j]);
        cout << arr[i] << "--" << arr[j] << endl;
        i++;
        j--;
    }

    for (i = 0; i < 11; i++)
    {
        cout << arr[i] << endl;
    }
}
