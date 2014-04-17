#include<stdio.h>
#include<stdlib.h>
int a[400000],p[400000];
int getp(int x)
{
    int i=x,j;
    while(x!=p[x])
        x=p[x];
    while(i!=p[i])
    {
        j=p[i];
        p[i]=x;
        i=j;
    }
    return x;
}

int main()
{
    int i,n,m,l,r,x;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n+1;i++)
        p[i]=i;
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        l=getp(l);
        while(l<=r)
        {
            if(l!=x)
            {
                p[l]=l+1;
                a[l]=x;
            }
            l=l+1;
            l=getp(l);
        }
    }
    for(i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
    return 0;
}
