#include<stdio.h>
int main()
{
    int n,k,l,r,sa,sk,i;
    scanf("%d %d %d %d %d %d",&n,&k,&l,&r,&sa,&sk);
    int x=sk/k,xm,y,ym;
    xm=sk%k;
    sa=sa-sk;
 //   if(n!=k)
   // {
    y=sa/(n-k);
    ym=sa%(n-k);
   // }
    for(i=0;i<n;i++)
    {
        if(i<k)
        {
            if(i<xm)
                printf("%d ",x+1);
            else
                printf("%d ",x);
        }
        else
        {
            if(i<k+ym)
                printf("%d ",y+1);
            else
                printf("%d ",y);
        }
    }
    printf("\n");
    return 0;
}
