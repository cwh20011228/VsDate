#include <iostream>
using namespace std;

int main(void)
{   // TODO: 原始字面量(可以表示字符串的实际意义，不需要转义)  R"(字符串内容)"
    // TODO:  R"标签(字符串内容)标签"  标签必须成对出现，在输出的时候不显示，提高可读性
    string path = "C:\\Program Files\\Microsoft OneDrive\\tail\\nation";
    string path1 = R"abcd(C:\Program Files\Microsoft OneDrive\tail\nation)abcd";
    cout<<"path is "<<path<<endl; 
    cout<<"path is "<<path1<<endl; 

    // TODO: 字符串的多行书写可以用斜线作为连接符
    string str ="<no>0001</no>\
    <name>西施</name>\
    <yz>沉鱼</yz>\
    <age>23</age>\
    <weight>48.5</weight>\
    <height>170<height>";
    cout<<"str is "<<str<<endl;
    
    string str1 =
    R"(
    <no>0001</no>
    <name>西施</name>
    <yz>沉鱼</yz>
    <age>23</age>
    <weight>48.5</weight>
    <height>170<height>)";
    cout<<"str1 is "<<str1<<endl;
    return 0;
}