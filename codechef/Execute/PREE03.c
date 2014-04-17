#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
    int t,n,p;
    scanf("%d",&t);
    while(t--)
    {
        int max=-15000000,max_so_far=-15000000,max_ending_here=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&p);
            max_ending_here=max(0,max_ending_here+p);
            if(p<0)
            {
                max_ending_here=0;
                max=max(p,max);
            }
            max_so_far=max(max_so_far,max_ending_here);
        }
        if(max_so_far)
            printf("%d\n",max_so_far);
        else
            printf("%d\n",max);
    }
    return 0;
}
