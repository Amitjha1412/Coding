#include<stdio.h>
#define min(a,b) a>b?b:a
int main()
{
    int t,i;
    int n[100001]={0},p[100001]={0},a,zeroes=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&a);
        if(a<0)
            n[i]=n[i-1]+1;
        else
            n[i]=n[i-1];
        if(a>0)
            p[i]=p[i-1]+1;
        else
            p[i]=p[i-1];
        if(a==0)
            zeroes++;
    }
    int ans=1000000,steps;
    for(i=0;i<=t;i++)
    {
        steps=t-p[t]+p[i]-n[i];
      //  printf("%d %d\n",n[i],steps);
        ans=min(ans,steps);
    }
    printf("%d\n",ans);
    return 0;
}
