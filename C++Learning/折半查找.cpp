#include <iostream>
using namespace std;

int Search(int* num, int Len, int Key)
{
	int low = 0, high = Len - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num[mid] == Key) return mid;
		else if (num[mid] > Key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int main(void)
{
	int num[8]={2, 6, 7, 9, 14, 20, 26, 29};
	if (Search(num, sizeof(num) / sizeof(int), 9) >= 0)
	{
		cout << "找到了" << endl;
	}
	else cout << "没找到" << endl;

}