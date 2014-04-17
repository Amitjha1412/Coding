#include<cstdio>
#include<iostream>
using namespace std;

char road[100][100];
int main()
{
    int n,a,b;
    int ans[3000][4];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a,&b);
    for(int i=0;i<n;i++)
        scanf("%s",road[i]);
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(road[i][j]=='Y')
            {
                int flag=0;
                for(int k=j+1;k<n&&flag==0;k++)
                {
                    if(road[j][k]=='Y')
                    {
                        ans[count][0]=2;
                        ans[count][1]=i;
                        ans[count][2]=j;
                        ans[count++][3]=k;
                        road[i][j]='N';
                        road[j][k]='N';
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[count][0]=1;
                    ans[count][1]=i;
                    ans[count][2]=j;
                    ans[count++][3]=-1;
                    road[i][j]='N';
                }
            }
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        if(ans[i][3]==-1)
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
        else
        printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    }
    return 0;
}
