#include<stdio.h>
inline void Scan_f(long long int a)
{
    char c = 0;
    while(c<33)
        c = fgetc_unlocked(stdin);
    //c = getc(stdin);
    a = 0;
    while(c>33)
    {
        a = a*10 + c - '0';
        c = fgetc_unlocked(stdin);
        //c = getc(stdin);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int ans,a,n;
        scanf("%lld",&n);
        ans=(n)*(n-1);
        ans=ans/2;
        while(n--)
            Scan_f(a);
        printf("%lld\n",ans);
    }
    return 0;
}
