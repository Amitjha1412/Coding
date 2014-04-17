#include<cstdio>
#include<iostream>
#include<vector>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*y)-(*x);
}
using namespace std;
vector < pair<int,int> > a[100100];
vector<int> b;
int dfs(int val,int v[])
{
    int pr=0,i,x=0;
    v[1]=1;
    for(i=0;i<a[val].size();i++)
    {
        if(v[a[val][i].first]!=1)
        {
            v[a[val][i].first]=1;
            x=dfs(a[val][i].first,v);
            pr=pr|x;
            if(a[val][i].second==2 && x==0)
            {
                b.push_back(a[val][i].first);
                pr=1;
            }
        }
    }
    return pr;
}
int main()
{
    int n;
    scanf("%d",&n);
    int t,i,k,j;
    for(k=0;k<n-1;k++)
    {
        scanf("%d %d %d",&i,&j,&t);
        a[i].push_back(make_pair(j,t));
        a[j].push_back(make_pair(i,t));
    }
    int v[100100]={0};
    dfs(1,v);
    cout<<b.size();
    cout<<endl;
    qsort(&b[0],b.size(),sizeof(int),cmp);
    for(k=0;k<b.size();k++)
    {
        printf("%d ",b[k]);
        cout<<endl;
    }
    return 0;
}
