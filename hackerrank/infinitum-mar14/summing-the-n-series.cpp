#include<cstdio>
#include<iostream>
using namespace std;
#define mod 1000000007
long long bigMod(long  a, long  b, long c) {
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
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        n=n%mod;
        printf("%lld\n",bigMod(n,n,mod));
    }
    return 0;
}
