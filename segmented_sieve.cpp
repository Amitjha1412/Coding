#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int casen;
    scanf("%d", &casen);
    while(casen--)
    {
        long long int  n,m;
        scanf("%lld %lld", &n, &m);
        long long int  * primes = new long long int [m-n+1];
        for(long long int  i=0;i<m-n+1;++i)
            primes[i] = 0;
        for(long long int  p=2;p*p<=m;++p)
        {
            long long int  less = n / p;
            less *= p;
            for(long long int  j=less;j<=m;j+=p)
                if(j != p && j >= n)
                    primes[j - n] = 1;
        }
        for(long long int  i=0;i<m-n+1;++i)
        {
            if(primes[i] == 0 && n+i != 1)
                printf("%lld\n",n+i);
        }
       // if(casen) printf("\n");
        delete [] primes;
    }
    return 0;
}
