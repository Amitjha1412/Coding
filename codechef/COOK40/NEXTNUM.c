#include<stdio.h>
typedef long long int ll;
int main()
{
    ll f[20];
    int t;
    scanf("%d",&t);
    f[0]=1;
    ll i;
    for(i=1;i<=18;i++)
        f[i]=f[i-1]*i;
    while(t--)
    {
        ll n,ans=0,j,k;
        char c[100];
        scanf("%s",c);
        int dig[10]={0};
        for(i=0;c[i]!='\0';i++)
        {
            c[i]-='0';
            dig[c[i]]++;
        }
        ll len=i;
        for(k=0;k<len;k++)
        {
            for(i=0;i<c[i];i++)
                if(dig[i]!=0)
                {
                    ll n=1;
                    for(j=0;j<10;j++)
                        if(i==j)
                            n=n*f[dig[j]-1];
                        else
                            n=n*f[dig[j]];
                    ans=ans+f[len-i-1]/n;
                }
            dig[c[k]]--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
