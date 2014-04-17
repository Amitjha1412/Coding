#include<cstdio>
#include<iostream>
using namespace std;
long long bigMod(long long  a, long long  b, long long  c)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == 1)
        return b%c;
    if (b == 1)
        return a%c;
    long long a2 = bigMod(a, b / 2, c);
    if ((b % 2) == 0)
        return (a2 + a2) % c;
    else
        return ((a % c) + (a2 + a2)) % c;
}
long long power(long long a,long long b,long long c)
{
    long long res=1;
    while(b)
    {
        if(b%2==1)
        {
            res=bigMod(res,a,c);
            res=res%c;
        }
        a=bigMod(a,a,c);
        a=a%c;
        b=b/2;
    }
    return res;
}
long long int mul_inv(long long int a, long long int b)
{
    long long int b0 = b, t, q;
    long long int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long  int n,p,ans,m;
        scanf("%lld %lld",&n,&p);
        ans=1;
        for(long long int i=1;i<=3*n;i++)
        {
            ans=ans*i;
            ans=ans%p;
        }
        m=mul_inv(6,p);
        ans=ans*power(m,n,p);
        ans=ans%p;
        printf("%lld\n",ans);
    }
    return 0;
}
