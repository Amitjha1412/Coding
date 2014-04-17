#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    char s[100],t[100];
    scanf("%s",s);
    scanf("%s",t);
    int x1;
    x1=s[0]-'0';
    x1=x1*10+s[1]-'0';
    int x2;
    x2=t[0]-'0';
    x2=x2*10+t[1]-'0';
    int x=x1-x2;
    x1=s[3]-'0';
    x1=x1*10+s[4]-'0';
    x2=t[3]-'0';
    x2=x2*10+t[4]-'0';
    int y=x1-x2;
    if(y<0)
    {
        y=60+y;
        x=x-1;
    }
    if(x<0)
        x=24+x;
    if(x<10)
        cout<<'0'<<x<<':';
    else
        cout<<x<<':';
    if(y<10)
        cout<<'0'<<y<<endl;
    else
        cout<<y<<endl;
}
