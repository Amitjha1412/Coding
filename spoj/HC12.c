#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
typedef long long int ll;
int compare (const void *a, const void *b)
{
    const ll *ia = (const ll *)a;
    const ll *ib = (const ll *)b;
    if(*ia>*ib)
        return 1;
    return 0;
}
/*ll modPow(ll a, ll x, ll p) {
    // return a^x mod p
    ll res = 1;
    while(x>0) {
        if(x & 1) res = (res*a) % p;
        a=(a*a)%p;
        x >>= 1;
    }
    return res;
}*/
ll mul_inv(ll a, ll b)
{
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
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
    ll n;
    ll t;
    ll amit;
    scanf("%lld",&t);
    for(amit=1;amit<=t;amit++)
    {
        ll k,i,a[10010];
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        qsort(a,n,sizeof(ll),compare);
        ll ans=0;
        ll B=1;
        for(i=k-1;i<n;)
        {
            ll b=a[i],v;
            b=(b*B)%mod;
            ans=ans+b;
            i=i+1;
            if(k!=1)
            {
              B=(B*i)%mod;
                v=i-(k-1);
                v=mul_inv(v,mod);
                B=(B*v)%mod;
            }
            ans=ans%mod;
        }
        printf("Case #%lld: %lld\n",amit,ans);
    }
    return 0;
}


