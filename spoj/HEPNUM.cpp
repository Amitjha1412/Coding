#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    char c;
    c='a';
    int flag=0;
    while(flag==0)
    {
        vector <char> a,b;
        int flag1=0,flag2=0,flags=0,f=-1,c='a';
        while(c!='\n')
        {
            c=getchar();
            if(c!='0' && flags==0 && flag1==0)
                flag1=1;
            if(c!='0' && flags==1 && flag2==0)
                flag2=1;
            if(c==' ')
                flag1=0,flag2=0,flags=1;
            if(c=='*')
                flag=1,flag1=0,flag2=0;
            if(c=='\n')
                flag1=0,flag2=0;
            if(flag1)
                a.push_back(c);
            if(flag2)
                b.push_back(c);
        }
        if(flag==1)
            return 0;
        if(a.size()>b.size())
            cout<<'>'<<endl;
        else if(a.size()<b.size())
            cout<<'<'<<endl;
        else
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]!=b[i])
                {
                    f=i;
                    break;
                }
            }
            if(f!=-1)
            {
                int m,n;
                if(a[f]>='0' && a[f]<='9')
                    m=a[f]-'0';
                else
                    m=a[f]-'A'+10;
                if(b[f]>='0' && b[f]<='9')
                    n=b[f]-'0';
                else
                    n=b[f]-'A'+10;
                if(m>n)
                    cout<<'>'<<endl;
                else if(m<n)
                    cout<<'<'<<endl;
            }
            else
                cout<<'='<<endl;
        }
    }
    return 0;
}
