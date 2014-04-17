#include<iostream>
#include<cstdio>

int parent[100100];
int size[100100];
int count[100100];
int hash[100100];

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
        if(size[u]>=size[v])
        {
            parent[v]=u;
            size[u]=size[u]+size[v];
        }
        else
        {
            parent[u]=v;
            size[v]+=size[u];
        }
    }
}


int main()
{
    int i;
    int test,n,m,a,b,max,odd,ans,temp,min;
    scanf("%d",&test);
    while(test--)
    {
        max=0;odd=0;ans=0;min=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            parent[i]=-1;
            size[i]=1;
            count[i]=1;
            hash[i]=0;
        }
        while(m--)
        {
            scanf("%d %d",&a,&b);
            if(max<a) max=a;
            if(max<b) max=b;
            if(!hash[a])
            {
                hash[a]=1;
                min++;
            }
            if(!hash[b])
            {
                hash[b]=1;
                min++;
            }
            makeset(a,b);
        }
        if(max<n) max=n;
        if(min==max) odd=0;
        else odd=1;
        for(i=1;i<=max;i++)
        {
            if(parent[i]!=-1)
            {
                int temp=findparent(i);
                if(size[temp]%2==1 && size[temp]>odd) odd=size[temp];
                count[temp]++;
            }
        }
        for(i=1;i<=max;i++)
            if(count[i]>1 && count[i]%2==0) ans+=count[i];
        if(odd) odd++;
        ans+=odd;
        printf("%d\n",ans);
    }
    return 0;
}
