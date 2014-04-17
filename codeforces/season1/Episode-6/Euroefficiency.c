#include<stdio.h>

#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b
int a[101],d[6];

void eff(int i)
{
    int j;
 //   if(a[i]==1000000)
  //  {
        for(j=1;j<=100;j++)
        {
            int t1;
           if(j>i)
          {
             if(a[j-i]==1000000)
                eff(j-i);
                t1=a[j]+a[j-i];
           }
         else
            {
                if(a[i-j]==1000000)
                    eff(i-j);
                t1=a[j]+a[i-j];
           }
            a[i]=min(a[i],t1);
        }
   // }
}

    int main()
    {
        int t,i,j;
        scanf("%d",&t);
        while(t--)
        {
            int smax=-1,sum=0;
            for(i=1;i<=100;i++)
                a[i]=1000000;
            for(i=1;i<=6;i++)
            {
                scanf("%d",&d[i]);
                a[d[i]]=1;
                sum++;
            }
            for(i=1;i<=100;i++)
              //  if(a[i]==1000000)
              //  {
                  //  printf("%d\n",i);
                    eff(i);
                //    smax=max(smax,a[i]);
                //    sum=sum+a[i];
                 //   printf("%d:%d\n",i,a[i]);
               // }
            for(i=1;i<=100;i++)
            {
                smax=max(smax,a[i]);
                sum=sum+a[i];
          //      printf("%d:%d\n",i,a[i]);
            }
            float ans=(float)(sum-6)/(float)100;
            printf("%0.2f %d\n",ans,smax);
        }
        return 0;
    }
