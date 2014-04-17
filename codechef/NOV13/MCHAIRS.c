#include<stdio.h>

typedef unsigned long long uint64;

uint64 PowMod(uint64 x, uint64 e, uint64 mod)
{
    uint64 res;
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
        res = PowMod(x, e / 2, mod);
        res = res * res % mod;
        if (e % 2)
            res = res * x % mod;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        uint64 n,x=2,mod=1000000007,ans;
        scanf("%llu",&n);
        ans=PowMod(x,n,mod);
        ans=ans-1;
        if(ans<0)
            ans=ans+mod;
        printf("%llu\n",ans);
    }
    return 0;
}
