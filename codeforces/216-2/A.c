#include<stdio.h>
int main()
{
    int n,m,k,i,a,c1=0,c2=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a==1)
            c1++;
        else if(a==2)
        {
            c2++;
        }
    }
    int ans=0;
    int x=c1-m;
    if(x<0)
        x=0;
    ans=ans+x;
    m=m-c1;
    if(m<0)
        m=0;
    x=c2-m-k;
    if(x<0)
        x=0;
    ans=ans+x;
    printf("%d\n",ans);
    return 0;
}
