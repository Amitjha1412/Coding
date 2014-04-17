#include<stdio.h>

int min(int a ,int b)
{
    return a>b?b:a ;
}
int max(int a ,int b)
{
    return a>b?a:b ;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[10000];
    scanf("%d",&a[0]);
    int flag=0;
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        for(j=0;j<i;j++)
        {
            int a1=max(a[j],a[j+1]);
            int b=min(a[j],a[j+1]);
            int c=max(a[i],a[i-1]);
            int d=min(a[i],a[i-1]);
            if(a1>d && b<d && a1<c)
                flag=1;
            if(a1>c && b< c && b>d)
                flag=1;
        }
    }
    if(flag)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
