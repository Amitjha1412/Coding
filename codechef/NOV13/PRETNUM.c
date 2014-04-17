#include<stdio.h>
int p[10010001]={0};
int divisorCount(long long int n)
{
    int count = 1;
    long long int i;
    for (i = 2; i*i<= n; i = (i == 2 ? 3 : i + 2))
    {
        int pow = 0;
        while (n % i == 0) {
            pow++;  // increment the power count
            n /= i; // remove one i from the prime factorization of n
        }
        if (pow != 0) {
            count *= pow + 1;
        }
    }
    if (n != 1)
        count *= 1 + 1;
    return count;
}
int main()
{
    int i,j;
    p[0]=p[1]=1;
    for(i=2;i*i<=1001000;i=(i==2 ? 3:i+2))
        if(p[i]==0)
            for(j=i*i;j<=1001000;j=j+i)
                p[j]=1;
    int t;
    long long int l,r,m,n;
    scanf("%d",&t);
    int ans=0;
    while(t--)
    {
        scanf("%lld %lld",&l,&r);
        for(;l<=r;l++)
        {
            if(l==1)
                continue;
            int count=divisorCount(l);
            if(p[count]==0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
