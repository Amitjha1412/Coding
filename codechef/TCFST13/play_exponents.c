#include<stdio.h>
int main()
{
    int n,a[100001]={0},i,t;
    a[0]=-1;
    long long int ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t=a[i]-a[i-1];
        if(t==0)
        {
            a[i]=a[i-1]+1;
            ans++;
        }
        else if(t>0)
            ans=ans+a[i]-a[i-1]-1;
        else
            ans=ans+a[i]-a[i-1];
    }
    printf("%lld\n",ans);
}
