#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c,m;
        long long int ans=0;
        scanf("%d %d %d",&n,&c,&m);
        int d=n/c;
        ans=ans+d;
        n=n%c;
        while(d>=m)
        {
            int e=d/m;
            ans=ans+e;
            d=e+d%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
