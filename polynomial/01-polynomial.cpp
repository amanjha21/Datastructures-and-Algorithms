#include <iostream>
#include <math.h>
using namespace std;
class Term
{
public:
    int c;
    int p;
};
class Polynomial
{
private:
    int n;
    Term *T;

public:
    Polynomial(int n)
    {
        this->n = n;
        T = new Term[this->n];
    }
    friend ostream &operator<<(ostream &output, Polynomial &p);
    friend istream &operator>>(istream &input, Polynomial &p);
    int calc(int x);
    Polynomial operator+(Polynomial &b);
    ~Polynomial() { delete[] T; }
};

istream &operator>>(istream &input, Polynomial &p)
{
    cout << "Enter " << p.n << " terms of the polynomial:" << endl;
    for (int i = 0; i < p.n; i++)
    {
        input >> p.T[i].c >> p.T[i].p;
    }
    return input;
}
ostream &operator<<(ostream &output, Polynomial &p)
{
    for (int i = 0; i < p.n; i++)
    {
        if (p.T[i].c > 0)
            output << "+";
        if (p.T[i].c != 1)
            output << p.T[i].c;
        output << "X^" << p.T[i].p;
    }
    output << endl;
    return output;
}
int Polynomial::calc(int x)
{
    int Res = 0;
    for (int i = 0; i < this->n; i++)
    {
        Res += this->T[i].c * pow(x, this->T[i].p);
    }
    cout << Res;
    return Res;
}
Polynomial Polynomial::operator+(Polynomial &b)
{
    int i, j, k;
    Polynomial sum(n + b.n);
    i = j = k = 0;
    while (i < n && j < b.n)
    {
        if (T[i].p < b.T[j].p)
            sum.T[k++] = T[i++];
        else if (T[i].p > b.T[j].p)
            sum.T[k++] = b.T[j++];
        else
        {
            sum.T[k].c = T[i].c + b.T[j].c;
            sum.T[k].p = T[i].p;
            ;
            i++;
            j++;
            k++;
        }
    }
    for (; i > n; i++)
        sum.T[k++] = T[i];
    for (; j > b.n; j++)
        sum.T[k++] = b.T[j];
    sum.n = k;
    return sum;
}

int main()
{
    Polynomial A(2);
    Polynomial B(2);
    cin >> A >> B;
    cout << A << B;
    Polynomial C = A + B;
    cout << C;
    C.calc(3);
}