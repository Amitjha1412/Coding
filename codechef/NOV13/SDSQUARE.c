#include<stdio.h>
#include<math.h>

typedef long long int ll;

int main()
{
    int t;
    scanf("%d",&t);
    int an[100001]={0};
    int ans=1;
    an[0]=1;
    ll i;
    for(i=1;i<=100000;i++)
    {
        int flag=0;
        ll j=i*i;
        while(j>0)
        {
            ll x=j%10;
            j=j/10;
            if(x!=0 && x!=1 && x!=4 && x!=9)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            ans++;
        an[i]=ans;
    }
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll a1=sqrt(a);
        ll b1=sqrt(b);
        if(a1*a1!=a)
            a1=a1+1;
        if(b1*b1!=b)
            b1=b1+1;
        if(a1>0)
            ans=an[b1]-an[a1-1];
        else
            ans=an[b1];
        printf("%d\n",ans);
    }
    return 0;
}
