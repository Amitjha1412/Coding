#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define N 10000000

int factors[N+1]={0},phi[N+1];
long long bigMod(long long  a, long long  b, long long  c)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == 1)
        return b%c;
    if (b == 1)
        return a%c;
    long long a2 = bigMod(a, b / 2, c);
    if ((b % 2) == 0)
        return (a2 + a2) % c;
    else
        return ((a % c) + (a2 + a2)) % c;
}
void calcphi()
{
    phi[1] = 1;
    for(int i=2;i<=N;i++)
    {
        if(factors[i]==0)
        {
            factors[i] = i;
            phi[i] = i-1;

           if(i<=sqrt(N))
               for(int j=i*i;j<=N;j+=i)
                    factors[j] = i;
        }
        else
        {
            int aux = i,exp = 0;
            while(aux%factors[i]==0)
            {
                aux /= factors[i];
                ++exp;
            }
            phi[i] = 1;
            for(int j=0;j<exp;++j)
                phi[i] *= factors[i];
            phi[i] -= phi[i]/factors[i];
            phi[i] *= phi[aux];
        }
    }
}
long long power(long long a,long long b,long long c)
{
    long long res=1;
    while(b)
    {
        if(b%2==1)
        {
            res=(res*a);
            res=res%c;
        }
        a=a*a;
        a=a%c;
        b=b/2;
    }
    return res;
}
int main()
{
    calcphi();
    for(int i=1;i<=100000;i++)
        printf("%d,",phi[i]);
    int t;
    long long int n1,k1,n2,k2,n,phin1,phin2,p1,p2,p;
 /*   scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&n1,&k1,&n2,&k2,&n);
        phin1=phi[n];
        phin2=phi[phin1];
        k2=k2%phin2;
        n2=n2%phin1;
        if(n2==0 && k2!=0)
            p2=0;
        else
            p2=power(n2,k2,phin1);
        k1=k1%phin1;
        n1=n1%n;
        if(n1==0 && k1!=0)
            p1=0;
        else
            p1=power(n1,k1,n);
        p1=p1%n;
        p2=p2%phin1;
        if(p1==0 && p2!=0)
            p=0;
        else
            p=power(p1,p2,n);
        p=p%n;
        printf("%lld\n",p);
    }*/
    return 0;
}
