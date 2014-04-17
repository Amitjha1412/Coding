#include<stdio.h>
int main()
{
    int n,k,a[100001],i;
    scanf("%d %d",&n,&k);
    int x=k;
    for(i=1;i<=n;i++)
        a[i]=i;
    for(i=1;i<=(n-k);i++)
    {
        a[i]=i-1;
        if(i==1)
            a[i]=n-k;
    }
   // if(x==n-1)
   // {
     //   a[1]=1;
       // a[n]=n;
       // }
    if((n-x))
    {
        for(i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    else
        printf("-1\n");
    return 0;
}
