#include<cstdio>
#include<iostream>
using namespace std;
#define mod 1000000007
long long bigMod(long long  a, long long b, long long c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }

    // Returns: (a * b/2) mod c
    long long a2 = bigMod(a, b / 2, c);

    // Even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2 + a2) % c;
    } else {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}
long long power(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b%2==1)
        {
            ret=ret*a;
            ret=ret%mod;
        }
        a=a*a;
        a=a%mod;
        b=b/2;
    }
    return ret;
}
int main()
{
    int n,a,e=0,o=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a%2==0)
            e++;
        else
            o++;
    }
    long long k=power(2,o-1);
    long long m=power(2,e);
    long long ans=bigMod(k,m,mod);
    ans=ans-1;
    if(ans<0)
        ans=ans+mod;
    printf("%lld\n",ans);
    return 0;
}
