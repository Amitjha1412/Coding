#include<stdio.h>

int main()
{
    int n;
    unsigned long long int x,i,z=1;
    scanf("%d",&n);
    int a[64]={0};
    while(n--)
    {
        scanf("%llu",&x);
        for(i=0;i<64;i++)
            if((x>>i)&1)
                a[i]=1;
    }
    unsigned long long int ans=0;
    for(i=0;i<64;i++)
        if(a[i])
            ans=ans+(unsigned long long int)(z<<i);
    printf("%llu\n",ans);
    return 0;
}

