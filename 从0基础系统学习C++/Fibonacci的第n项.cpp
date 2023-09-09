#include <iostream>
using namespace std;

void ShowNum(int *num, int length);
int Fibonacci(int n);

int main(void)
{
    // Todo: 쳲��������еĵ�����
    int n = 0;
    cin >> n;
    int num[n + 1] = {0, 1};
    for (int i = 2; i <= n; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
    }
    ShowNum(num, n + 1);
    cout << endl;

    // Todo: 쳲��������еĵݹ鷨
    int number = Fibonacci(n);
    cout << "쳲��������еĵ�" << n + 1 << "����" << number << endl;

    return 0;
}

void ShowNum(int *num, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << num[i] << "\t";
    }
}

// Todo: 쳲��������еĵݹ鷨
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int temp1 = Fibonacci(n - 1);
    int temp2 = Fibonacci(n - 2);
    return temp1 + temp2;
}