#include<stdio.h>
#include<stdlib.h>
int k;
int cmpf ( const void *pa, const void *pb )
{
    const long long int (*a)[k+2] = pa;
    const long long int (*b)[k+2] = pb;
    if ( (*a)[k+1] < (*b)[k+1] )
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,m=0;
        long long int sum=0;
        scanf("%d %d",&n,&k);
        long long int a[n][k+2],s[k+2],ans[n+1];
        for(i=0;i<n;i++)
        {
            a[i][0]=i+1;
            a[i][k+1]=0;
            for(j=1;j<=k;j++)
            {
                scanf("%lld",&a[i][j]);
                a[i][k+1]+=a[i][j];
            }
        }
        qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),cmpf);
        for(j=1;j<=k;j++)
            scanf("%lld",&s[j]);
        for(i=0;i<n;i++)
        {
            int flag=0;
            for(j=1;j<=k;j++)
                if(s[j]<a[i][j] || s[j]==0)
                    flag=1;
            if(flag==0)
            {
                ans[m++]=a[i][0];
                for(j=1;j<=k;j++)
                    s[j]-=a[i][j];
            }
        }
        printf("%d\n",m);
        for(i=0;i<m-1;i++)
            printf("%lld ",ans[i]);
        if(m)
            printf("%lld\n",ans[i]);
    }
    return 0;
}
