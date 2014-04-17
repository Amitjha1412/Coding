#include<stdio.h>
#define gc() getchar_unlocked()
int isSpaceChar(char c) {
    return c == ' ' || c == '\n' || c == '\r' ;
}
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isSpaceChar(ch))
        ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
int main()
{
    int n,q,k,x;
    scanf("%d",&n);
    int i,j,a[301][301][11]={0};
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            for(k=0;k<=10;k++)
                a[i][j][k]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==1)
                for(k=1;k<=10;k++)
                    a[i][j][k]=a[i-1][n][k];
            else
                for(k=1;k<=10;k++)
                    a[i][j][k]=a[i][j-1][k];
            x=FAST_IO();
            a[i][j][0]=x;
            a[i][j][x]++;
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        int ans=0,x1,x2,y1,y2,f[11]={0};
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=x1;i<=x2;i++)
        {
            for(k=1;k<=10;k++)
                if(a[i][y2][k]>a[i][y1][k])
                    f[k]++;
            f[a[i][y1][0]]++;
        }
        for(k=1;k<=10;k++)
            if(f[k]>0)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
