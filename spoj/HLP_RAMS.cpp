#include<cstdio>
#include<iostream>
using namespace std;
long long pascal(long long a)
{
    if(a==0||a==1)
        return 0;
    if(a%2==0)
        return pascal(a/2)+a/2;
    else
        return 2*pascal((a-1)/2);
}
int main()
{
    int t;
    long long a,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        n=pascal(a);
        printf("%lld ",n);
        printf("%lld\n",(a+1)-n);
    }
    return 0;
}
