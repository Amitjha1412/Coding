#include<stdio.h>

int main()
{
    int t,a[101000],n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long int k=0,i=0,x[n+1]={0},j,ans=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=n;i>0;i--)
        {
            ans=ans+a[i];
            x[k]=a[i];
            for(j=0;j<k;j++)
            {
                x[j]=(x[j])^(a[i]);
                ans=ans+x[j];
            }
            k+=1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
