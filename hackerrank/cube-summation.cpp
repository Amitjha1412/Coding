#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        int m[101][101][101]={0};
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    m[i][j][k]=0;
        int g=0;
        int u[1001][4];
        while(q--)
        {
            int i1,j1,k1,x,y,z,v;
            char s[100];
            scanf("%s",s);
            if(s[0]=='U')
            {
                int flag=-1;
                scanf("%d %d %d %d",&i1,&j1,&k1,&v);
                for(int i=0;i<g;i++)
                    if(i1==u[i][0]&& j1==u[i][1] && k1==u[i][2])
                    {
                        flag=i;
                        break;
                    }
                if(flag==-1)
                {
                    u[g][0]=i1;
                    u[g][1]=j1;
                    u[g][2]=k1;
                    u[g][3]=v;
                    m[i1][j1][k1]=v;
                    g++;
                }
                else
                {
                    u[flag][3]=v;
                    m[i1][j1][k1]=v;
                }
            }
            if(s[0]=='Q')
            {
                long long int ans=0;
                scanf("%d %d %d %d %d %d",&i1,&j1,&k1,&x,&y,&z);
                for(int i=0;i<g;i++)
                {
                    if(u[i][0]>=i1 && u[i][0]<=x && u[i][1]>=j1 && u[i][1]<=y && u[i][2]>=k1 && u[i][2]<=z)
                        ans=ans+(long long int)u[i][3];
                }
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
