#include<cstdio>
#include<iostream>
using namespace std;
#define mod 1000000007
long long a[1000001];
int main()
{
    a[2]=2;
    for(int i=3;i<=1000000;i++)
    {
        a[i]=a[i-1]*(a[i-1]+1);
        a[i]=a[i]%mod;
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
