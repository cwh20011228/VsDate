#include <iostream>
using namespace std;

void func(int **ptr);

int main(void)
{
    // int ii = 8;
    // cout << "ii=" << ii << "��ii�ĵ�ַ�ǣ�" << &ii << endl;
    // int *pii = &ii;
    // cout << "pii=" << pii << "��pii�ĵ�ַ�ǣ�" << &pii << ",*pii=" << *pii << endl;
    // int **ppii = &pii;
    // cout << "ppii=" << ppii << "��ppii�ĵ�ַ�ǣ�" << &ppii << ",*ppii=" << *ppii << endl;
    // cout<<"**ppii="<<**ppii<<endl;

    int *p = 0;
    // {
    //     int **pp = &p;
    //     *pp = new int{3};
    //     cout << "pp=" << pp << ", *pp=" << *pp << endl;
    // }
    func(&p);
    cout << "p=" << p << ", *p=" << *p << endl;

    return 0;
}

void func(int **ptr)
{
    // int **pp = ptr;
    *ptr = new int{3};
    cout << "pp=" << ptr << ", *pp=" << *ptr << endl;
}