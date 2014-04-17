#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double n;
        scanf("%lf",&n);
        double a=n-1;
        long long int ans=1;
        while(a*3>0)
        {
            a=(3*a-1)/3;
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
