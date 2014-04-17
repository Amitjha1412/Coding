#include<stdio.h>
#define min(a,b) a?b b:a
int main()
{
    int n,i=1,k,a[1000000],min;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        min=min(min,a[i]);
    }
    for(i=1;i<=n;i++)
    {
    }
    return 0;
}
