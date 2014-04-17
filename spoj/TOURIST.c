#include<stdio.h>
int a[105][105],x[105][105],y[105][105];
void dp(int h,int w)
{
    int i,j,delta;
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            if(a[i][j]!=-1)
            {
                if(a[i][j]==1)
                    delta=1;
                else
                    delta=0;
                int x1[4]={x[i-1][j],x[i][j-1],y[i-1][j],y[i][j-1]};
           //     int y1[2]={y[i-1][j],y[i][j-1]};
                int r,c,max=0,l,k;
                for(l=0;l<4;l++)
                    for(k=l+1;k<4;k++)
                    {
                        if(x1[l]+x1[k]>=max)
                        {
                            max=x1[l]+x1[k];
                            r=x1[l];
                            c=x1[k];
                        }
                    }
                x[i][j]=r+delta;
                y[i][j]=c;
        //        x[i][j]=x[i-1][j]+x[i][j-1]+delta;
            }
        }
        int l,k;
        for(l=1;l<=h;l++)
        {
            for(k=1;k<=w;k++)
                printf("%d ",x[l][k]);
            printf("\n");
        }
        printf("\n");
        for(l=1;l<=h;l++)
        {
            for(k=1;k<=w;k++)
                printf("%d ",y[l][k]);
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }
}
int main()
{
    int t,h,w,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&w,&h);
        for(i=0;i<=h;i++)
            for(j=0;j<=w;j++)
                a[i][j]=x[i][j]=y[i][j]=0;
        char temp[100];
        for(i=1;i<=h;i++)
        {
            scanf("%s",temp);
            for(j=0;j<w;j++)
            {
                if(temp[j]=='*')
                    a[i][j+1]=1;
                else if(temp[j]=='.')
                    a[i][j+1]=0;
                else
                    a[i][j+1]=-1;
            }
        }
        if(a[1][1]==1)
            x[1][1]=1;
        dp(h,w);
        printf("%d\n",x[h][w]+y[h][w]);
    }
    return 0;
}
