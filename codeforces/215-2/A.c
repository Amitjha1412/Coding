#include<stdio.h>
int cmp(const void *a,const void *b)
{
    int *x=(int*)a;
    int *y=(int*)b;
    return (*x)-(*y);
}
int main()
{
    int n,d,ans=0,i,m,a[10000];
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    qsort(a,n,sizeof(int),cmp);
    for(i=0;i<n && m>0;i++,m--)
        ans+=a[i];
    if(m>0)
    ans=ans-m*(d);
    printf("%d\n",ans);
    return 0;
}
