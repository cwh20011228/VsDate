#include <iostream>
using namespace std;

int search(int arr[], int len, int key)
{
    int low = 0, high{len - 1}, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(void)
{
    int a[10] = {7, 9, 12, 16, 21, 25, 30, 35, 41, 48};
    if (search(a, 10, 16) >= 0)
        cout << "������a�в���16�ɹ���\n";
    else
        cout << "������a�в���16ʧ�ܡ�\n";
    return 0;
}