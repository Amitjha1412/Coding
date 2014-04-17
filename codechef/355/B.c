#include<stdio.h>
int main()
{
    int c1,c2,c3,c4;
    int t1,t2,s1=0,s2=0,s=0;
    int n,m,a[1001],b[1001],i;
    scanf("%d %d %d %d",&c1,&c2,&c3,&c4);
    scanf("%d %d ",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t1=(c1*a[i]);
        if(t1>c2)
            t1=c2;
            s1=s1+t1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        t2=(c1*b[i]);
        if(t2>c2)
            t2=c2;
        s2=s2+t2;
    }
    if(s1>c3)
        s1=c3;
    if(s2>c3)
        s2=c3;
    s=s1+s2;
    if(s>c4)
        s=c4;
    printf("%d\n",s);
        return 0;
}
