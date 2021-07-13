#include <conio.h>
#include <iostream>
using namespace std;

struct diagonalMatrix
{
    int A[5];
    int n = 5;
};

void Set(struct diagonalMatrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i - 1] = x;
    }
}

int Get(struct diagonalMatrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct diagonalMatrix m)
{
    int i = 0, j = 0;
    for (i = 0; i < m.n - 1; i++)
    {
        for (j = 0; j < m.n - 1; j++)
        {
            if (i == j)
                cout << m.A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    struct diagonalMatrix m;
    Set(&m, 1, 1, 1);
    Set(&m, 2, 2, 2);
    Set(&m, 3, 3, 3);
    Set(&m, 4, 4, 4);
    cout << Get(m, 3, 3);
    cout << endl;
    Display(m);

    return 0;
}
