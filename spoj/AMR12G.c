#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x)-(*y);
}
int main()
{
    int t;
    int n,m,k;
    scanf("%d",&t);
    while(t--)
    {
        char c[100];
        int a[100],i,j;
        scanf("%d %d %d",&n,&m,&k);
        for(i=0;i<n;i++)
        {
            a[i]=0;
            scanf("%s",c);
            for(j=0;j<m;j++)
            {
                if(c[j]=='*')
                    a[i]++;
            }
        }
        int x;
        for(i=0,j=0;i<k;i++)
        {
            int min=100001;
            for(j=0;j<n;j++)
                if(a[j]<min)
                {
                    min=a[j];
                    x=j;
                }
            a[x]=m-a[x];
        }
        int ans=0;
        for(i=0;i<n;i++)
            ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}
