#include<stdio.h>
#define mod 1000000007
long long int power(long long int x,long long int y)
{
    long long int a;
    if(y==0)
        return 1;
    else if(y%2==0)
    {
        a=power(x,y/2);
        a=a%mod;
        if(a<0)
        a=a+mod;
        a=(a*a)%mod;
        if(a<0)
        a=a+mod;
        return a;
    }
    else
    {
        a=power(x,y/2);
        a=a%mod;
        if(a<0)
        a=a+mod;
        a=(x*a*a)%mod;
        if(a<0)
        a=a+mod;
        return a;

    }
}
int main()
{
    int t;
        long long int ans=0,amit=0;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        ans=0,amit=0;
        scanf("%d",&n);
        ans=power(n,n+1);
        if(ans<n)
            ans=ans+mod;
        ans=ans-n+1;
       if(n>2)
       {
           amit=power(n-1,n);
           if(amit<1)
               amit=amit+mod;
           amit=amit-1;
           amit=amit%mod;
       }
       else
           amit=0;
        printf("%lld %lld\n",ans,amit);
    }
}
