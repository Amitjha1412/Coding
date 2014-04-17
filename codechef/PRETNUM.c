#include<stdio.h>
int p[1000001],b[1000001]={0};
#define max(a,b)a>b?a:b
int main()
{
    int k,m;
    for(m=2;m*m<=1001000;m++)
    {
        if(b[m]==0)
            for(k=m*m;k<=1001000;k=k+m)
                b[k]=1;
    }
    m=0;
    for(k=2;k<=1001000;k++)
        if(b[k]==0)
            p[m++]=k;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[1000100]={0};
        long long int l,r,i,j;
        scanf("%lld %lld",&l,&r);
        for(j=0;((p[j]*p[j])<=r) && j<=1001000;j++)
        {
            i=max(l,p[j]*p[j]);
            for(;i<=r;i=i+p[j])
            {
                printf("%d %lld\n",p[j],i);
                a[i-l]=1;
                if(i==p[j]*p[j])
                    a[i-l]=0;
            }
        }
        int count=0;
        for(i=0;i<r;i++)
            if(a[i]==0 && (i+l-1)!=0)
                count++;
        printf("%d\n",count);
    }
    return 0;
}
