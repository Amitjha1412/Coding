#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x)-(*y);
}

int main()
{
    int t,n,a[1000];
    scanf("%d",&t);
    while(t--)
    {
        int i,x,k;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&k);
        x=a[k-1];
        qsort(a,n,sizeof(int),compare);
        for(i=0;i<n;i++)
            if(x==a[i])
            {
                printf("%d\n",i+1);
                break;
            }
    }
    return 0;
}
