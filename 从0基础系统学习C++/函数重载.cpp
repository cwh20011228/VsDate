#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

void swap(string &a, string &b)
{
    string tmp = b;
    b = a;
    a = tmp;
}

int main(void)
{
    int x = 2, y = 6;
    swap(x, y);
    cout << "x=" << x << "  y=" << y << endl;
    string x1 = "Smith", x2 = "Jenny";
    swap(x1, x2);
    cout << "x1=" << x1 << "  x2=" << x2 << endl;

    return 0;
}