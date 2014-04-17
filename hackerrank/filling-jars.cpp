#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int a,b,x,s=0;
    while(m--)
    {
        scanf("%lld %lld %lld",&a,&b,&x);
        s=s+(b-a+1)*x;
    }
    double ans=s/n;
    ans=ans+0.5;
    long long int ns=(long long int)ans;
    printf("%lld\n",ns);
    return 0;
}
