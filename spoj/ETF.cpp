#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define N 10000000

int factors[N+1]={0},phi[N+1];

int main()
{
    phi[1] = 1;

    for(int i=2;i<=N;i++)
    {
        if(factors[i]==0)
        {
            factors[i] = i;
            phi[i] = i-1;

           if(i<=sqrt(N))
          // else
          //     printf("%d\n",i);
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
   /* int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }*/
    for(int i=0;i<=1000000;i++)
        printf("%d,",phi[i]);
    return 0;
}
