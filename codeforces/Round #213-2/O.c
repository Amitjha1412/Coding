#include<stdio.h>
int main()
{
    int n,k,a;
    int ans=0;
    scanf("%d %d",&n,&k);
    while(n--)
    {
        int i,dig[10]={0};
        int flag=0;
        scanf("%d",&a);
        while(a>0)
        {
            int temp=a%10;
            a=a/10;
            dig[temp]++;
        }
        for(i=0;i<=k;i++)
            if(dig[i]==0)
                flag=1;
        if(flag==0)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
