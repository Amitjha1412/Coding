#include<stdio.h>

typedef unsigned long long int llu;

llu mod=1000000007;

llu PowMod(llu x, llu e)
{
    llu res;
    if (e == 0)
    {
        res = 1;
    }
    else if (e == 1)
    {
        res = x;
    }
    else
    {
        res = PowMod(x, e / 2);
        res = res * res % mod;
        if (e % 2)
            res = res * x % mod;
    }
    return res;
}

int main()
{
    int t,i;
    llu a[600001];
    a[0]=1;
    for(i=1;i<=600000;i++)
    {
        if(i&1)
        {
            a[i]=a[i-1]*4;
            a[i]=a[i]%mod;
        }
        else
            a[i]=PowMod(a[i/2],10);
    }
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
