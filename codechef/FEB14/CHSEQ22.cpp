#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int mod=1000000007;
typedef struct interval
{
    int a;
    int b;
    interval (int r,int g)
    {
        this->a = r;
        this->b = g;
    }
}interval;
bool cmp(interval x,interval y)
{
    if(x.a==y.a)
        return x.b<y.b;
    else
        return x.a<y.a;
}
long long int power(int x)
{
    long long int a=2,ret=1;
    while(x)
    {
        if(x%2==1)
        {
            ret=ret*a;
            ret=ret%mod;
        }
        a=a*a;
        a=a%mod;
        x=x/2;
    }
    return ret;
}
vector <interval> seg;
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
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        a=in();
        b=in();
        seg.push_back(interval(a,b));
    }
    sort(seg.begin(),seg.end(),cmp);
    int x,y,j;
    for(size_t i=0;i<seg.size()-1;)
    {
        if(seg[i].a==seg[i+1].a)
        {
            if(seg[i].b!=seg[i+1].b)
            {
                x=seg[i].b+1;
                y=seg[i+1].b;
                seg.erase(seg.begin()+(i+1));
                int beg=i+1;
                int end=seg.size();
                int mid=(beg+end)/2;
                while(beg<=end && seg[mid].a!=x)
                {
                    if(seg[mid].a<x)
                        beg=mid+1;
                    else
                        end=mid-1;
                    mid=(beg+end)/2;
                }
                j=mid;
                //if(seq[j].a==x)
               // {
                //    if(seq[j].b>y)
                //}
                //cout<<mid<<endl;*/
                //    j=binary_search(x,y,i+1,seg.size());
                //for(j=i+1;j<seg.size() && seg[j].a<x;j++);
                //for(;j<seg.size() && seg[j].b<y;j++);
                if(seg[j].a!=x || seg[j].b!=y)
                    seg.insert(seg.begin()+j,interval(x,y));
            }
            else
                seg.erase(seg.begin()+(i+1));
        }
        else
            i++;
        cout<<i<<endl;
    }
    printf("%lld\n",power(seg.size()));
    return 0;
}
