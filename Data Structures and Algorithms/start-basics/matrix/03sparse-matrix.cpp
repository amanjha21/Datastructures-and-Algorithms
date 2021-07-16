#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};
class SparseMatrix
{
private:
    int m;
    int n;
    int num;
    Element *T;

public:
    SparseMatrix(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        T = new Element[this->num];
    }
    ~SparseMatrix() { delete[] T; }
    friend istream &operator>>(istream &input, SparseMatrix &s);
    friend ostream &operator<<(ostream &output, SparseMatrix &s);

    SparseMatrix operator+(SparseMatrix &s)
    {
        SparseMatrix *Res;
        Res = new SparseMatrix(m, n, num + s.num);
        int i = 0, j = 0, k = 0;
        while (i < num && j < s.num)
        {
            if (T[i].i < s.T[j].i)
                Res->T[k++] = T[i++];
            else if (T[i].i > s.T[j].i)
                Res->T[k++] = s.T[j++];
            else
            {
                if (T[i].j < s.T[j].j)
                    Res->T[k++] = T[i++];
                else if (T[i].j > s.T[j].j)
                    Res->T[k++] = s.T[j++];
                else
                {
                    Res->T[k].i = T[i].i;
                    Res->T[k].j = T[i].j;
                    Res->T[k].x = T[i].x + s.T[j].x;
                    k++;
                    i++;
                    j++;
                }
            }
        }
        for (; i < num; i++)
            Res->T[k++] = T[i];
        for (; j < num; j++)
            Res->T[k++] = s.T[j];
        Res->num = k;
        return *Res;
    }
};

istream &operator>>(istream &input, SparseMatrix &s)
{
    cout << "Enter " << s.num << " non-zero elements:" << endl;
    for (int i = 0; i < s.num; i++)
    {
        input >> s.T[i].i >> s.T[i].j >> s.T[i].x;
    }
    return input;
}

ostream &operator<<(ostream &output, SparseMatrix &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.T[k].i - 1 == i && s.T[k].j - 1 == j)
            {
                cout << s.T[k].x << " ";
                k++;
            }
            else
            {
                output << "0 ";
            }
        }
        output << endl;
    }
    return output;
}
int main()
{
    SparseMatrix A(3, 3, 2);
    SparseMatrix B(3, 3, 2);
    cin >> A >> B;
    SparseMatrix Sum = A + B;
    cout << Sum;
}