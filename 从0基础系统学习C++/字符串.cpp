#include <iostream>
using namespace std;

int main(void)
{
    string str = "西施";
    str = "美女西施";
    cout<<"str ="<< str<<endl;
    cout<<"请输入超女名字：";
    cin>>str;
    if(str=="冰冰") cout<<"我喜欢\n";
    if(str != "冰冰") cout<<"我不玩了\n";
    str = "姓名："+str+",这是我的现女友";
    cout<<str<<endl;
    //TODO: 如果几个字符串都是常量 ，则不能用 + 
    string str1 = "超女姓名：" "米米" "，这是我的前女友";
    cout<<str1<<endl;
    return 0;
}