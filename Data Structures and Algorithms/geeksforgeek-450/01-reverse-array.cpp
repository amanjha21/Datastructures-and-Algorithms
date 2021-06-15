#include <iostream>
#include <conio.h>

using namespace std;

struct Array
{
    int Arr[10];
    int size;
    int length;
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(struct Array *arr)
{
    int i = 0, j;
    j = arr->length - 1;
    while (i < j)
    {
        swap(&arr->Arr[i++], &arr->Arr[j--]);
    };
}

int main()
{
    struct Array a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.length = a.size = 9;
    reverse(&a);
    int i;
    for (i = 0; i < a.length; i++)
    {
        cout << a.Arr[i] << endl;
    }
}