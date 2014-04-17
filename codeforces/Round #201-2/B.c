#include<stdio.h>
int a[100000];
int main()
{
    int n,b,i,temp=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b);
        a[b]=i;
    //    c[i]=b;
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==i)
            ans++;
        else
        {
            if(a[a[i]]==i)
                temp=1;
        }
    }
    ans=ans+temp+1;
    if(ans>=n)
        ans=n;
    printf("%d\n",ans);
    return 0;
}
