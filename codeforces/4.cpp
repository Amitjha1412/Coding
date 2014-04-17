#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
unsigned long long m ,n, gcd, lcm,ans;
char x[1000010],y[1000010],ch;

unsigned long long euclid(int n, int m)
{
    if( m == 0 )
        return n;
    return euclid(m, n%m);
}

int main()
{
    int i;
    cin >> n >> m;
    scanf("%s",x);
    scanf("%c",&ch);
    scanf("%s",y);
    if(n>m) gcd = euclid(n,m);
    else gcd = euclid(m,n);
    lcm = (m/gcd)*n;
    ans = 0;

    return 0;
}
