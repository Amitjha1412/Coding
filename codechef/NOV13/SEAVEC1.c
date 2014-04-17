#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j,s[100000],ans[100000],m=0;
        long long int sum=0;
        scanf("%d %d",&n,&k);
        int a[n][k];
        for(i=0;i<n;i++)
            for(j=0;j<k;j++)
                scanf("%d",&a[i][j]);
        for(j=0;j<k;j++)
            scanf("%d",&s[j]);
        for(i=0;i<n;i++)
        {
            int flag=0;
            for(j=0;j<k;j++)
                if((s[j])<a[i][j])
                    flag=1;
            if(flag==0)
            {
                int sd = 1;
                long long sum=0,var=0;
                for(j=0;j<k;j++)
                    sum += a[i][j];
                sum /= k;
                for(j=0;j<k;j++)
                    var += abs(a[i][j]-sum);
                var /= k;
                if( var < sd)
                {
                    ans[m++]=i;
                    for(j=0;j<k;j++)
                        s[j]-=a[i][j];
                }
            }
        }
        printf("%d\n",m);
        for(i=0;i<m-1;i++)
            printf("%d ",ans[i]+1);
        if(m)
        printf("%d\n\n",ans[i]+1);
    }
    return 0;
}
