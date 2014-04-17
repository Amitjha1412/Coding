//game theory:BLUE RED HACKENBUSH

#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x)-(*y);
}

int main()
{
    int t,i,x,j;
    int a[110][100];
    scanf("%d",&t);
    while(t--)
    {
        long long int g=0,prev,max;
        int k;
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%d",&x);
            for(j=0;j<x;j++)
                scanf("%d",&a[i][j]);
            qsort(a[i],x,sizeof(int),cmp);
            prev=1;

            for(j=0;j<45;j++)
                prev=prev<<1;
            if(a[i][0]%2==0)
                prev=(long long int)(-1)*prev;
            max=prev;
            for(j=0;j<x;j++)
            {
                if(a[i][j]&1==1)
                {
                    if(prev<0)
                        prev=-1*prev>>1;
                    else if(prev!=max)
                        prev=prev>>1;
                }
                else
                {
                    if(prev>0)
                        prev=-1*(prev>>1);
                    else if(prev!=max)
                        prev=prev>>1;
                }
                g=g+prev;
            }
        }
        if(g>0)
            printf("ODD\n");
        else if(g<0)
            printf("EVEN\n");
        else
            printf("DON'T PLAY\n");
    }
    return 0;
}
