#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
long long int count=0,ans1=0;
int ans2=0,a[50001],fin=0,tmp=0,flag1=0;
vector <int> node[50001];
#define getchar getchar_unlocked
#define putchar putchar_unlocked
int in()
{
    char c;
    while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
    bool flag=(c=='-');
    if(flag) c=getchar();
    int x=0;
    while(c>='0'&&c<='9') {
        x=x*10+c-48;
        c=getchar();
    }
    return flag?-x:x;
}
bool visited[50001];
void DFS(int v)
{
    visited[v]=1;
    if(a[v])
    {
        count++;
        fin+=tmp;
        tmp=0;
        flag1=1;
    }
    else if(node[v].size()==1)
        flag1=0;
    for(int i=0;i< (int)node[v].size();i++)
    {
        if(!visited[node[v][i]])
        {
            tmp++;
            DFS(node[v][i]);
            if(!flag1 && tmp>0)
                tmp--;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        a[i]=in();
    while(m--)
    {
        int i,j;
        i=in();
        j=in();
        node[i].push_back(j);
        node[j].push_back(i);
    }
    for(int i = 1; i <=n; i++)
        visited[i] = false;
    for(int i=1;i<=n;i++)
    {
        fin=0;
        tmp=1;
        flag1=1;
        if(!visited[i] && a[i])
        {
            count=0;
            DFS(i);
            ans1+=(count*(count-1))/2;
            if(fin>1)
                ans2+=fin;
        }
    }
    printf("%lld %d\n",ans1,ans2);
    return 0;
}
