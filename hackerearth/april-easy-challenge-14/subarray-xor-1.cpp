#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t,n,a[110000],c,d,q;
    long long s[110000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        s[0]=a[0];
        for(int i=1;i<n;i++)
            s[i]=s[i-1]^((long long)a[i]);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&c,&d);
            if(c==0)
                printf("%lld\n",s[d]);
            else
            {
                long long ans=s[d]^s[c-1];
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
