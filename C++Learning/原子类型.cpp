#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

int aa = 0;
atomic<int*> p = &aa;

void func()
{
	for (int ii = 1; ii <= 1000000; ii++) {
		(*p)++;
	}
}

int main(void)
{
	thread t1(func);	
	thread t2(func);

	
	t1.join();
	t2.join();
	cout << "aa=" << aa << endl;

}