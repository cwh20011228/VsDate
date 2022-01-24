#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void)
{
    const int MIN_VALUE = 10;
    const int MAX_VALUE = 18;
    unsigned seed; //  保存种子的变量
    cout << "Enter a seed value:  ";
    seed = time(0); // 必须给它传递一个0
    // cin>>seed;
    srand(seed);                                                //  srand() 提供一个种子
    int num = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE; // num 范围是(MIN_VALUE ~ MAX_VALUE)
    for (int i = 0; i < 6; i++)
    {
        cout << num << "  ";
        num = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    return 0;
}
