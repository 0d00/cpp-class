#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    cout << "Input the row and col: ";
    int r, c;
    cin >> r >> c;
    cout << "Input the data: ";
    float *d1 = new float[r * c];
    for (int i = 0; i < r * c; i++)
    {
        cin >> d1[i];
    }

    matrix m(r, c, d1);
    cout << "Creat a matrix: " << endl
         << m << endl
         << endl;
    matrix n;
    n = m;
    cout << "copy the matrix: " << endl
         << n << endl;

    cout << "Input the method: (+,-,*,c): " << endl;
    char op;
    cin >> op;
    matrix q;
    if (op == '+')
    {
        q = m + n;
        cout << "add the matrix: " << endl
             << q << endl;
        exit(0);
    }
    if (op == '*')
    {
        q = m * n;
        cout << "mutiply of matrix: " << endl
             << q << endl;
        exit(0);
    }
    if (op == '-')
    {
        q = m - n;
        cout << "Substract of matrix: " << endl
             << q << endl;
        exit(0);
    }
    if (op == 'c')
    {
        float f;
        cin >> f;
        q=f*m;
        cout << q << endl;
        exit(0);
    }

    delete[] d1;
    return 0;
}
