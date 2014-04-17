#include<cstdio>
#include<iostream>
using namespace std;
bool isPowerOf2(long long int num)
{
       return ((num>0) && (num & (num-1))==0);
}
long long int gcd(long long int a, long long int b)
{
    int c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int main()
{
    int t;
    long long int p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&p,&q);
        if(p>2*q)
        {
            printf("NO\n");
            continue;
        }
        long long int g=gcd(p,q);
        p=p/g;
        q=q/g;
        long long int a=1;
        while(q%2==0)
        {
            a=a*2;
            q=q/2;
        }
        //a=(q+1)/p;
        if(isPowerOf2(p) && isPowerOf2(q+1))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
