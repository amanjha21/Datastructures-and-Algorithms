#include <conio.h>
#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int *A;
    int n;

public:
    DiagonalMatrix()
    {
        n = 2;
        A = new int[2];
    }
    DiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~DiagonalMatrix() { delete[] A; }
};

void DiagonalMatrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int DiagonalMatrix::get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void DiagonalMatrix::display()
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    DiagonalMatrix m(5);

    m.set(1, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 3, 3);
    m.set(4, 4, 4);
    cout << m.get(3, 3);
    cout << endl;
    m.display();

    return 0;
}
