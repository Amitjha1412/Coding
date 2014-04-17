#include<stdio.h>
int parent[100010],size[100010];
int findparent(int x)
{
    while(parent[x]!=-1)
        x=parent[x];
    return x;
}
void makeset(int x,int y)
{
    int u=findparent(x);
    int v=findparent(y);
    if(u!=v)
    {
        if(size[v]>size[u])
        {
            parent[u]=v;
            size[u]+=size[v];
        }
        else
        {
            parent[v]=u;
            size[u]+=size[v];
        }
    }
}
int main()
{
    int n,i;
    int type[100010],path[100010];
    for(i=1;i<=n;i++)
    {
        parent[i]=-1;
        size[i]=1;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&type[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&path[i]);
    for(i=1;i<=n;i++)
    {
        if(path[i])
            makeset(path[i],i);
    }
    int max=0;
    int j;
    for(i=1;i<=n;i++)
    {
        if(size[i]>max)
        {
            max=size[i];
            j=i;
        }
    }
    printf("%d\n",size[j]);
    return 0;
}
