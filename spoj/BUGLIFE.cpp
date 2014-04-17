#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector <int> a[2100];
int g[2100];
bool DFS(int r)
{
    bool res = true;
    for(int i = 0; i < a[r].size(); i++)
    {
        int v = a[r][i];
        if(g[v] == g[r])
            return false;
        if(g[v] == 0)
        {
            g[v] = -g[r];
            res = res and DFS(v);
        }
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            g[i] = 0;
            a[i].clear();
        }
        while(m--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            a[i].push_back(j);
            a[j].push_back(i);
        }
        cout<<"Scenario #";
        printf("%d:\n",test);
        bool result = true;
        for(int i = 1; i <= n; i++)
        {
            if(g[i] == 0)
            {
                g[i] = 1;
                result = result and DFS(i);
            }
        }
        if(result)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }
    return 0;
}
