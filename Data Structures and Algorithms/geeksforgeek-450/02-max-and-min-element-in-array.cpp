#include <iostream>
#include <conio.h>

using namespace std;
struct minmax
{
    int max;
    int min;
};

struct minmax findMinAndMax(int a[])
{
    struct minmax m;
    int i;
    m.max = a[1];
    m.min = a[1];
    for (i = 0; i < 10; i++)
    {
        if (a[i] > m.max)
        {
            m.max = a[i];
        }
        if (a[i] < m.min)
        {
            m.min = a[i];
        }
    }
    return m;
}
struct minmax findMinAndMax2(int a[], int l, int h)
{
    struct minmax m, mm1, mm2;
    int mid;
    if (l == h)
    {
        m.max = m.min = a[l];
        return m;
    }
    else if (h == l + 1)
    {
        if (a[l] > a[h])
        {
            m.max = a[l];
            m.min = a[h];
        }
        else
        {
            m.max = a[h];
            m.min = a[l];
        }
        return m;
    }
    else
    {
        mid = (l + h) / 2;
        mm1 = findMinAndMax2(a, l, mid);
        mm2 = findMinAndMax2(a, mid + 1, h);
        if (mm1.max > mm2.max)
            m.max = mm1.max;
        else
            m.max = mm2.max;
        if (mm1.min < mm2.min)
            m.min = mm1.min;
        else
            m.min = mm2.min;
    }
    return m;
}

int main()
{
    int a[10] = {1, 0, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "max: " << findMinAndMax2(a, 0, 9).max << endl;
    cout << "min: " << findMinAndMax2(a, 0, 9).min << endl;
}