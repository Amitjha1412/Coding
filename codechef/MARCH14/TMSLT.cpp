#include<cstdio>
#include<iostream>
using namespace std;
int f[1000000];
#define mod 1000000
#define max(a,b)a>b?a:b
#define getchar getchar_unlocked
#define putchar putchar_unlocked
int in()
{
    char c;
    while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
    bool flag=(c=='-');
    if(flag) c=getchar();
    int x=0;
    while(c>='0'&&c<='9') {
        x=x*10+c-48;
        c=getchar();
    }
    return flag?-x:x;
}
int main()
{
    int t,n,a0,b,c,d;
    t=in();
    while(t--)
    {
        long long int ans=0,s=0,prev;
        n=in();
        a0=in();
        b=in();
        c=in();
        d=in();
        prev=d;
        for(int i=0;i<1000000;i++)
            f[i]=0;
        f[d]++;
        int max=d;
        for(int i=1;i<n;i++)
        {
            s=(long long int)a0*prev*prev;
            s+=(long long int)b*prev;
            s+=(long long int)c;
            s=s%mod;
            if(s<0)
                s+=mod;
            f[s]++;
            prev=s;
            max=max(max,s);
        }
        int k=0;
        for(int i=max;i>=0 && k<n;i--)
        {
            if(f[i] & 1)
            {
                if(k & 1)
                    ans-=(long long int)i;
                else
                    ans+=(long long int)i;
                k+=f[i];
            }
        }
        if(ans>0)
            printf("%lld\n",ans);
        else
            printf("%lld\n",-1*ans);
    }
    return 0;
}
