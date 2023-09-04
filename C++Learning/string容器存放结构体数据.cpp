#include <iostream>
using namespace std;

int main(void)
{
	struct st_girl {
		int bh;
		char name[30];
		bool yz;
		double weight;
		string memo;
	}girl;

	cout << "��Ů�ṹ��Ĵ�С��" << sizeof(st_girl) << endl;

	string buffer;	// ����һ������Ϊ0��string����buffer

	// ����10����Ů����Ϣ������buffer��
	for (int ii = 1; ii <= 10; ii++)
	{
		// �Գ�Ů������и�ֵ
		memset(&girl, 0, sizeof(girl));
		girl.bh = ii;
		sprintf(girl.name, "��ʩ%02d", ii);
		girl.yz = true;
		girl.weight = 48.5 + ii;
		girl.memo = "�й���ʷ��һ��Ů";

		// �ѳ�Ů�ṹ׷�ӵ�buffer
		buffer.append((char*)&girl, sizeof(st_girl));
	}

	cout << "buffer.capacity()=" << buffer.capacity() << endl;	// ��ʾ����
	cout << "buffer.size()=" << buffer.size() << endl;		// ��ʾʵ�ʴ�С

	// ��һ��ѭ������buffer�����е�ȫ������ȡ����
	for  (int ii = 0; ii < buffer.size()/sizeof(st_girl);  ii++)
	{
		memset(&girl, 0, sizeof(st_girl));

		// �������е����ݸ��Ƶ���Ů�ṹ��
		//memcpy(&girl, buffer.data()+ii*sizeof(st_girl), sizeof(st_girl));
		buffer.copy(reinterpret_cast<char*>(&girl), sizeof(st_girl), ii * sizeof(st_girl));
		//��ʾ��Ů�ṹ���Ա��ֵ
		cout << "bh=" << girl.bh << "   name=" << girl.name << "   yz=" << girl.yz 
			 << "   weight=" << girl.weight << "   memo=" << girl.memo << endl;
	}
}