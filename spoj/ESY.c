#include<stdio.h>
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
    int a,n=0,i;
    long long int ans=0;
        for(i=0;i<t;i++)
        {
            scanf("%d",&a);
            if(a<0)
                a=-1*a;
            if(a==1)
                n++;
            else if(a!=0)
            {
                if(ans==0)
                    ans=1;
                ans=ans*a;
            }
        }
        ans=ans+n;
        ans=ans*-1;
        if(t)
            printf("%lld\n",ans);
    }
    return 0;
}
