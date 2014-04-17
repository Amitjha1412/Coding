#include<stdio.h>
#define min(a,b) a>b?b:a
int main()
{
    int n,i,j,c,d;
    scanf("%d",&n);
    int a[4][2];
    for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d %d",&c,&d);
            a[i][j]=min(c,d);
        }
    }
    for(i=0;i<4;i++)
    {
        if(a[i][1]+a[i][0]<=n)
        {
            printf("%d %d %d\n",i+1,a[i][0],(n-a[i][0]));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
