#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        if(s.find("010")!=string::npos || s.find("101")!=string::npos)
            cout<<"Good"<<endl;
        else
            cout<<"Bad"<<endl;
    }
    return 0;
}
