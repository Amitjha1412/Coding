#include<cstdio>
#include<iostream>
#include<utility>
using namespace std;
char in[1100][1100];
bool visited[1100][1100]={0};
int p[1100][1100];
int s[1100][1100]={0};
int find(int i,int j)
{
    if(p[i][j]==1001*i+j)
        return 1001*i+j;
    return find(p[i][j]/1001,p[i][j]%1001);
}
void Union(int i1,int j1,int i2,int j2)
{
    int x=find(i1,j1);
    int y=find(i2,j2);
    if(s[x/1001][x%1001]>s[y/1001][y%1001])
    {
        p[y/1001][y%1001]=x;
        s[x/1001][x%1001]+=s[y/1001][y%1001];
    }
    else
    {
        p[x/1001][x%1001]=y;
        s[y/1001][y%1001]+=s[x/1001][x%1001];
    }
}
void dfs(int i,int j)
{
//    printf("dfs%d %d\n",i,j);
    visited[i][j]=1;
    if(in[i][j]=='S')
    {
        Union(i+1,j,i,j);
        if(visited[i+1][j]==0)
            dfs(i+1,j);
    }
    else if(in[i][j]=='N')
    {
        Union(i-1,j,i,j);
        if(visited[i-1][j]==0)
            dfs(i-1,j);
    }
    else if(in[i][j]=='E')
    {
        Union(i,j+1,i,j);
        if(visited[i][j+1]==0)
            dfs(i,j+1);
    }
    else if(in[i][j]=='W')
    {
        Union(i,j-1,i,j);
        if(visited[i][j-1]==0)
            dfs(i,j-1);
    }
    return ;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",in[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            p[i][j]=1001*i+j;
            s[i][j]=1;
        }
    for(int i=0;i<n;i++)
    {
        //printf("%s",in[i]);
        for(int j=0;j<m;j++)
        {
        //    printf("%d %d\n",i,j);
            if(visited[i][j]==0)
            {
                dfs(i,j);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(p[i][j]==1001*i+j)
                ans++;
    }
    printf("%d\n",ans);
    return 0;
}
