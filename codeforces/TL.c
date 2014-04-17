#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
int main()
{
    int n,m,maxn=0,minn=10000,a,b=10000,i,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        maxn=max(a,maxn);
        minn=min(a,minn);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        b=min(a,b);
    }
    ans=max(maxn,2*minn);
    if(b>ans)
        printf("%d\n",ans);
    else
        printf("-1\n");
    return 0;
}
