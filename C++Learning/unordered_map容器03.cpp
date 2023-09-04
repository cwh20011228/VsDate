#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, string> m;
	cout << "Ͱ�ĸ�����"<<m.bucket_count() << endl;

	auto itmp = m.bucket_count();

	// ����������Ԫ�������ɼ�¼
	for (int ii = 0; ii < 200000; ii++) {
		char name[50];
		sprintf_s(name, "��ʩ%d", ii);
		m.emplace(ii, name);

		if (itmp != m.bucket_count()) {
			cout << m.bucket_count() << endl;
			itmp = m.bucket_count();
		}
	}

	cout << m.load_factor() << endl;
	cout << m.max_load_factor() << endl;
	


}