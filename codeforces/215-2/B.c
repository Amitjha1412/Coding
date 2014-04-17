#include<stdio.h>
int main()
{
    int n,m;
    int a[100100],c[100100]={0},ans[100100]={0},i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int z=0;
    for(i=n;i>0;i--)
    {
        if(c[a[i-1]]==0)
        {
            z+=1;
            c[a[i-1]]=1;
        }
        ans[i]=z;
    }
    int q;
    while(m--)
    {
        scanf("%d",&q);
        printf("%d\n",ans[q]);
    }
    return 0;
}
