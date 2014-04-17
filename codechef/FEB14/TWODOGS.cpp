#include<cstdio>
#include<iostream>
using namespace std;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define max(a,b)a>b?a:b
#define min(a,b)a>b?b:a
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
int a[500001],pos[1000001]={0};
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        a[i]=in();
        if(pos[a[i]])
        {
            int j=n-i;
            int v=min(i+1,j);
            pos[a[i]]=min(v,pos[a[i]]);
        }
        else
            pos[a[i]]=i+1;
    }
    int max=100000000;
    for(int i=1;i<k;i++)
    {
        if(pos[i]>0 && pos[k-i]>0 && i!=k-i)
        {
            int j=k-i;
            int u=n-pos[i]+1;
            int v=n-pos[j]+1;
            if(u>0)
                u=min(pos[i],u);
            else
                u=pos[i];
            if(v>0)
                v=min(pos[j],v);
            else
                v=pos[j];
            int m=max(u,v);
            max=min(max,m);
        }
    }
    if(max==100000000)
        printf("-1\n");
    else
        printf("%d\n",max);
    return 0;
}
