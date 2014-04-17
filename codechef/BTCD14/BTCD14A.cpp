#include<cstdio>
#include<iostream>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    while(b)
    {
        long long int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    int n;
    long long int a,ans=1;
    scanf("%d",&n);
    scanf("%lld",&a);
    n--;
    ans=a;
    while(n--)
    {
        scanf("%lld",&a);
        ans=gcd(ans,a);
    }
    while(ans%2==0)
        ans=ans/2;
    printf("%lld\n",ans);
    return 0;
}
