#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include<cstdio>
using namespace std;

long long int mul_t(long long int x,long long int y,long long int mod)
{
    long long int res=0;
    while(y)
    {
        if(y%2==1)
        {
            res+=x;
            res=res%mod;
        }
        x=x*2;
        x=x%mod;
        y=y/2;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        char s[1100];
        long long int arr[1100];
        long long int add[1100],mul[1100];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long long int A,B,C;
        cin>>A>>B>>C;
        A=A%C;
        B=B%C;
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]%C;
            add[i]=0;
            mul[i]=1;
        }
        scanf("%s",s);
        int r=1;
        for(int i=0,k=0,j=n-1,ad=0;ad<n;ad++)
        {
            if(i)
            {
                add[ad]=add[ad-1];
                mul[ad]=mul[ad-1];
            }
            if(s[ad]=='A')
            {
                add[ad]+=A;
                add[ad]=add[ad]%C;
            }
            else if(s[ad]=='M')
            {
                mul[ad]=mul_t(mul[ad],B,C);
                mul[ad]=mul[ad]%C;
                add[ad]=mul_t(add[ad],B,C);
                add[ad]=add[ad]%C;
            }
            else if(s[ad]=='R')
            {
                r=-1*r;
                if(r==-1)
                {
                    k=i;
                    i=j;
                }
                else
                {
                    j=i;
                    i=k;
                }
            }
            arr[i]=mul_t(arr[i],mul[ad],C);
            arr[i]=arr[i]%C;
            arr[i]=arr[i]+add[ad];
            arr[i]=arr[i]%C;
            cout<<arr[i]<<" ";
            i=i+r;
        }
        printf("\n");
    }
    return 0;
}
