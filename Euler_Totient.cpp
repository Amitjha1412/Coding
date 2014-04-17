#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int primes[1001000];
bool isprime[1001000]={0};
int phi(const int n)
{
  // Base case
  if ( n < 2 )
    return 0;

  // Lehmer's conjecture
  if ( isprime[n] )
    return n-1;

  // Even number?
  if ( n & 1 == 0 ) {
    int m = n >> 1;
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }

  // For all primes ...
  for ( std::vector<int>::iterator p = primes.begin();
        p != primes.end() && *p <= n;
        ++p )
  {
    int m = *p;
    if ( n % m  ) continue;

    // phi is multiplicative
    int o = n/m;
    int d = binary_gcd(m, o);
    return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
  }
}
int main()
{
    b[0]=b[1]=1;
    for(int m=2;m*m<=1001000;m++)
    {
        if(b[m]==0)
            for(int k=m*m;k<=1001000;k=k+m)
                b[k]=1;
    }
    int t=0;
    for(int k=2;k<=1001000;k++)
        if(b[k]==0)
            primes[t++]=k;
    return 0;
}
