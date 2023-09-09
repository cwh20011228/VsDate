#include <iostream>
using namespace std;

int Facturial(int n);

int main(void)
{
    // Todo : 用迭代的方法，用已知推未知
    unsigned long long result = 1, n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        result = i * result;
    }
    cout << "result= " << result << endl;

    // Todo: 用递归方法
    unsigned long long  result2 = Facturial(n);
    cout << "result2=" << result2 << endl;
}

// Todo: 用递归方法
int Facturial(int n)
{
    if (n == 0)
        return 1;
    unsigned long long temp = Facturial(n - 1);
    return n * temp;
}