#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define max(a,b)a>b?a:b
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef struct node
{
    int b[1001];
    int c[1001];
    int color;
    int an;
}node;
node a[1001];
bool cmp(const node &a,const node &b)
{
    return a.an>b.an;
}
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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<n;i++)
            a[i].color=in();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i].b[j]=in();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i].c[j]=in();
        for(int i=0;i<n;i++)
        {
            a[i].an=0;
            for(int j=0;j<m;j++)
            {
                if(a[i].an)
                    a[i].an=max(a[i].an,a[i].b[j]-a[i].c[j]);
                else
                    a[i].an=a[i].b[j]-a[i].c[j];
            }
            a[i].an-=a[i].b[a[i].color-1];
        }
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(k && a[i].an>0)
            {
                ans+=a[i].an;
                k--;
            }
        }
        for(int i=0;i<n;i++)
            ans+=a[i].b[a[i].color-1];
        printf("%d\n",ans);
    }
    return 0;
}
