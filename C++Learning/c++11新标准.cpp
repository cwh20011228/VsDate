#include <iostream>
#include <initializer_list>
#include <string>

double sum(std::initializer_list<double> ii)
{
	double total = 0;
	for (auto it = ii.begin(); it != ii.end(); it++) {
		total = total + *it;
	}
	return total;
}


void func(const int len1)
{	// ���������βμ���const����ʾֻ�����������ú���ʱ��ʵ�ο����Ǳ�����Ҳ�����ǳ���
	// len1��ֻ�����������ǳ���
	//int array[len1] = { 0 };	// VS����Linuxƽ̨�����鳤��֧�ֱ��������ᱨ��
	// ��vs�У����������ʱ�򣬳��ȱ����ǳ������ʽ�������Ǳ���

	constexpr int len2 = 8;		// ���������ʱ�򣬼���const��len2���������ĳ���
	int array[len2] = { 0 };	// ��ȷ��len2�ǳ���
}

int main(void)
{
	//double total = sum( 3.14,5.20,8 );	// ����û�д����ţ���������������
	//double total = sum({ 3.14,5.20,8 });	// ��ȷ���д����ţ�����һ��������
	//std::cout << "total=" << total << std::endl;

	//std::string str = "123a45";
	//size_t pos;
	//int val = stoi(str, &pos, 10);
	//std::cout <<"val=" << val << std::endl;	// ���123
	//std::cout << "pos=" << pos << std::endl;	// ���3

	func(1);
}