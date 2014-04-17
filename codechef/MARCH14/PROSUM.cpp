#include<cstdio>
#include<iostream>
using namespace std;
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
    int t,n,a[100010],k=0,l;
    long long int ans=0;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        k=0;
        l=0;
        n=in();
        for(int i=0;i<n;i++)
            a[i]=in();
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>2)
                ans+=(long long int)(n-1-i-k);
            else if(a[i]==2)
                ans+=(long long int)(n-1-i-k-l);
            if(a[i]==1 || a[i]==0)
                k++;
            if(a[i]==2)
                l++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

