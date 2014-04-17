#include<stdio.h>
#define mod 1000000007
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int l,r;
        scanf("%lld %lld",&l,&r);
        int i=1;
        long long ans=0,temp=10,value=0;
        while(r>=l)
        {
            if(temp>=l)
            {
                if(temp>r)
                    temp=r+1;
              //  printf("%lld %lld %lld %d\n",ans,value,temp,l);
                value=temp*(temp-1);
                long long val= l*(l-1);
                value-=val;
                value/=2;
                value=value*i;
                value=value%mod;
                //printf("%lld %lld %lld %lld\n",ans,value,val,temp);
                ans=ans+value;
                ans=ans%mod;
                l=temp;
               // printf("%lld %lld %lld\n",ans,value,temp);
            }
            temp=temp*10;
            i++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
