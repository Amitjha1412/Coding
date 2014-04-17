#include<stdio.h>
#define min(a,b) a>b?b:a
typedef struct rectangle
{
    int h;
    int w;
}rectangle;
rectangle rect[1001][1001];
int a[1001][1001]={0};
int main()
{
    int n,i,j,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
                rect[i][j].h=rect[i][j].w=1;
            else
                rect[i][j].h=rect[i][j].w=0;
        }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-2;j>=0;j--)
        {
            if(a[i][j]!=a[i+1][j] && a[i][j]!=a[i][j+1] && a[i][j])
            {
                rect[i][j].h=1;
                rect[i][j].w=1;
            }
            else if(a[i][j]!=a[i+1][j] && a[i][j]==a[i][j+1] && a[i][j])
            {
                rect[i][j].h=1;
                rect[i][j].w=rect[i][j+1].w+1;
            }
            else if(a[i][j]==a[i+1][j] && a[i][j]!=a[i][j+1] && a[i][j])
            {
                rect[i][j].h=rect[i+1][j].h+1;
                rect[i][j].w=1;
            }
            else if(a[i][j]==a[i+1][j] && a[i][j]==a[i][j+1] && a[i][j])
            {
                rect[i][j].h=min(rect[i+1][j].h+1,rect[i][j+1].h);
                rect[i][j].w=min(rect[i+1][j].w,rect[i][j+1].w+1);
            }
            else if(a[i][j]==0)
                rect[i][j].h=rect[i][j].w=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rect[i][j].h && rect[i][j].w)
            {
                int u=i,v=j,x=u+rect[i][j].h,y=v+rect[i][j].w;
                for(u=i;u<x;u++)
                    for(v=j;v<y;v++)
                        if(u!=i || v!=j)
                            rect[u][v].h=rect[u][v].w=0;
                count++;
            }
        }
    }
    printf("%d\n",count);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(rect[i][j].h && rect[i][j].w)
                printf("%d %d %d %d %d\n",a[i][j],i+1,i+rect[i][j].h,j+1,j+rect[i][j].w);
return 0;
}
