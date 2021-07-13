#include <iostream>
using namespace std;

class LowerTriangleMatrix
{
private:
    int n;
    int *A;

public:
    LowerTriangleMatrix(int n)
    {
        this->n = n;
        // A = (int *)malloc((n * (n + 1) / 2) * sizeof(int));
        A = new int[(n * (n + 1) / 2)];
    }
    ~LowerTriangleMatrix()
    {
        free(&A);
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};
void LowerTriangleMatrix::set(int i, int j, int x)
{
    if (i >= j)
        A[(i * (i - 1) / 2) + (j - 1)] = x;
}
int LowerTriangleMatrix::get(int i, int j)
{
    if (i >= j)
        return A[(i * (i - 1) / 2) + (j - 1)];
    else
        return 0;
}
void LowerTriangleMatrix::display()
{
    int i = 0, j = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[(i * (i - 1) / 2) + (j - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    LowerTriangleMatrix M(5);
    M.set(1, 1, 1);
    M.set(2, 1, 2);
    M.set(2, 2, 2);
    M.set(3, 1, 3);
    M.set(3, 2, 3);
    M.set(3, 3, 3);
    M.set(4, 1, 4);
    M.set(4, 2, 4);
    M.set(4, 3, 4);
    M.set(4, 4, 4);
    M.set(5, 1, 5);
    M.set(5, 2, 5);
    M.set(5, 3, 5);
    M.set(5, 4, 5);
    M.set(5, 5, 5);
    M.display();
    return 0;
}