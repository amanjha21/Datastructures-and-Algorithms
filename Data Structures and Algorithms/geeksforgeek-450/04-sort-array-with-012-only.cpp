#include <iostream>

using namespace std;

int *sort(int a[], int l)
{
    int i, noOf0, noOf1;
    noOf0 = noOf1 = 0;
    for (i = 0; i < l; i++)
    {
        if (a[i] == 0)
            noOf0++;
        if (a[i] == 1)
            noOf1++;
    }
    for (i = 0; i < l; i++)
    {
        if (noOf0 != 0)
        {
            a[i] = 0;
            noOf0--;
        }
        else if (noOf1 != 0)
        {
            a[i] = 1;
            noOf1--;
        }
        else
        {
            a[i] = 2;
        }
    }
    return a;
}

int main()
{
    int a[10] = {0, 2, 1, 0, 0, 1, 1, 0, 2, 2};
    int length = 10;
    int i;
    int *result;
    result = sort(a, length);
    for (i = 0; i < length; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}