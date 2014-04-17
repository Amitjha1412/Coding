#include<stdio.h>
#include<limits.h>
#define max(a,b) a>b?a:b
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,a[100000];
        long long int start[100000]={0},end[100000]={0},ans;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        end[0]=a[0];
        for(i=1;i<n;i++)
            end[i]=max(end[i-1]+(long long int)a[i],(long long int)a[i]);

        start[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)
            start[i]=max(start[i+1]+(long long int)a[i],(long long int)a[i]);

        for(i=n-2;i>=0;i--)
            start[i]=max(start[i],start[i+1]);

        //        for(i=0;i<n;i++)
        //          printf("%lld\t%lld\t%lld\n",a[i],end[i],start[i]);
        ans=LLONG_MIN;
        for(i=0;i<(n-k-1);i++)
            ans=max(ans,start[i+k+1]+end[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
