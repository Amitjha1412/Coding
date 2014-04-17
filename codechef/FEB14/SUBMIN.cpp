#include<cstdio>
#include<iostream>
using namespace std;
#define min(a,b) a>b?b:a
int main()
{
    int n,a[100],q,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    while(q--)
    {
        int ans=0,i;
        scanf("%d",&k);
        for(i=0;i<n;i++)
        {
            int m=100000000;
            for(int j=i;j<n;j++)
            {
                m=min(m,a[j]);
                if(m==k)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
