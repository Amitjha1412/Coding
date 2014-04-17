#include<cstdio>
#include<iostream>

using namespace std;

#define mod 10000007

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

long long int modpow(long long int a,long long int b)
{
    long long int res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}

int main()
{
    long long int n,k;
    int na,ka;
    while(1)
    {
        scanint(na);
        scanint(ka);
        n=(long long int)na;
        k=(long long int)ka;
        if(!(n &&k))
            break;
        long long int a=modpow(n,n);
        long long int b=modpow(n-1,n-1);
        long long int c=modpow(n,k);
        long long int d=modpow(n-1,k);
        long long int ans=a+2*b+c+2*d;
        ans=ans%mod;
        printf("%lld\n",ans);
    }
}
