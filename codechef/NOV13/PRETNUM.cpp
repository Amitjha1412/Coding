//segment sieve and power of prime
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
long long int pr[1001000];
bool b[1001000]={0};
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
            pr[t++]=k;
    int casen;
    scanf("%d", &casen);
    while(casen--)
    {
        long long int  n,m,ans=0;
        scanf("%lld %lld", &n, &m);
        bool  * primes = new bool [m-n+1];
        for(long long int  i=0;i<m-n+1;++i)
            primes[i] = 0;
        for(long long int p=0;(pr[p]*pr[p])<=m;++p)
        {
            long long int  less = n / pr[p];
            less *= pr[p];
            for(long long int  j=less;j<=m;j+=pr[p])
                if(j != pr[p] && j >= n)
                    primes[j - n] = 1;
            long long int pow=1;
            int count=0;
            while(pow<n)
            {
                pow*=pr[p];
                count++;
            }
            for(long long int j=pow;j<=m;j=j*pr[p],count++)
                if(b[count+1]==0 )
                    primes[j-n]=0;
        }
        for(long long int  i=0;i<m-n+1;++i)
        {
            if(primes[i] == 0 && n+i != 1)
                ans++;
        }
        printf("%lld\n",ans);
        delete [] primes;
    }
    return 0;
}
