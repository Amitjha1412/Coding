nclude<stdio.h>
long long int s[1000000]={0},a[1000000];
int main()
{
    int n,q,i;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i)
            s[i]=s[i-1]+a[i];
        else
            s[i]=a[i];
    }
    while(q--)
    {
        char Q[10];
        long long int x,y;
        scanf("%s %lld %lld",Q,&x,&y);
        if(Q[0]=='G')
        {
            a[x]+=y;
            for(i=x;i<n;i++)
            {
                if(i)
                    s[i]=s[i-1]+a[i];
                else
                    s[i]=a[i];
            }
        }
        else if(Q[0]=='T')
        {
            a[x]-=y;
            for(i=x;i<n;i++)
                s[i]=s[i-1]+a[x];
        }
        else
        {
            if(x)
                printf("%lld\n",s[y]-s[x-1]);
            else
                printf("%lld\n",s[y]);
        }
    }
    return 0;
}
