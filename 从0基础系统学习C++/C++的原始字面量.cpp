#include <iostream>
using namespace std;

int main(void)
{   // TODO: ԭʼ������(���Ա�ʾ�ַ�����ʵ�����壬����Ҫת��)  R"(�ַ�������)"
    // TODO:  R"��ǩ(�ַ�������)��ǩ"  ��ǩ����ɶԳ��֣��������ʱ����ʾ����߿ɶ���
    string path = "C:\\Program Files\\Microsoft OneDrive\\tail\\nation";
    string path1 = R"abcd(C:\Program Files\Microsoft OneDrive\tail\nation)abcd";
    cout<<"path is "<<path<<endl; 
    cout<<"path is "<<path1<<endl; 

    // TODO: �ַ����Ķ�����д������б����Ϊ���ӷ�
    string str ="<no>0001</no>\
    <name>��ʩ</name>\
    <yz>����</yz>\
    <age>23</age>\
    <weight>48.5</weight>\
    <height>170<height>";
    cout<<"str is "<<str<<endl;
    
    string str1 =
    R"(
    <no>0001</no>
    <name>��ʩ</name>
    <yz>����</yz>
    <age>23</age>
    <weight>48.5</weight>
    <height>170<height>)";
    cout<<"str1 is "<<str1<<endl;
    return 0;
}