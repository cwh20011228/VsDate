#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char str[13] ;
    memset(str,0,sizeof(str));
    // str[0]=0;
    // strcpy(str,"hello");
    strncpy(str,"hello",5);
    cout<<"strlen(str)="<<strlen(str)<<endl;
    char str1[7];
    memset(str1,0,sizeof(str1));
    strcpy(str1," world");
    // strcat(str,str1);
    strncat(str,str1,2);
    cout<<"str="<<str<<endl;
    int comp=strcmp(str,str1);
    cout<<"comp="<<comp<<endl;
    cout<<(void *)strchr(str,'e')<<endl;
    cout<<(void *)strstr(str,"el")<<endl;
    cout<<(int)str[0]<<endl;
    cout<<(int)str[1]<<endl;
    cout<<(int)str[2]<<endl;
    cout<<(int)str[3]<<endl;
    cout<<(int)str[4]<<endl;
    cout<<(int)str[5]<<endl;
    cout<<(int)str[6]<<endl;
    cout<<(int)str[7]<<endl;
    cout<<(int)str[8]<<endl;
    cout<<(int)str[9]<<endl;
    cout<<(int)str[10]<<endl;

    return 0;
}