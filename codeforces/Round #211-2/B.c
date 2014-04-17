#include<stdio.h>
int main()
{
    int n,k;
    int a[150001],i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int sum=0,min=0,ans=0;
    for(i=1;i<=k;i++)
        sum+=a[i];
    min=sum;
    ans=1;
    for(i=2;i<=(n-k+1);i++)
    {
        sum=sum-a[i-1];
        sum=sum+a[i+k-1];
        if(min>sum)
        {
            min=sum;
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
