#include <iostream>
using namespace std;


int main(void)
{
	try
	{
		// �����׳����쳣
		int ii = 0;
		cout << "����һֻʲô��?(1-ɵɵ��  2-СС��)��";
		cin >> ii;

		if (ii == 1) {	// throw�׳�const char* ���͵��쳣
			throw "���ã�����˵����һֻɵɵ��";
		}

		if (ii == 2)	// throw�׳�int���͵��쳣
		{
			throw ii;
		}

		if (ii == 3)	// throw�׳�string���͵��쳣
		{
			throw string("���ã�����˵����һֻɵɵ��");
		}


		cout << "�Ҳ���һֻɵɵ��" << endl;
	}

	catch (int ii)
	{
		cout << "�쳣������Ϊint=" << ii << endl;
	}

	catch (const char* ss)
	{
		cout << "�쳣������Ϊconst char*=" << ss << endl;
	}

	catch (string str)
	{
		cout << "�쳣������Ϊstring=" << str << endl;
	}

	//catch (...)		// ����ʲô�쳣�������⴦��
	//{
	//	cout << "�����쳣������û����ʲô�쳣" << endl;
	//}

	cout << "�����������..." << endl;	// ִ����try ... catch...�󣬽�����ִ�г����������Ĵ���
	return 0;
}