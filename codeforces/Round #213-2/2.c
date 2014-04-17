#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
    int n;
    scanf("%d",&n);
    int a[100001];
    int i;
    int ans=2;
    int max=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i>1)
        {
            if(a[i]==(a[i-1]+a[i-2]))
                ans++;
            else
                ans=2;
        }
        max=max(ans,max);
    }
    if(max==2 && n==1)
        max=1;
    printf("%d\n",max);
    return 0;
}
