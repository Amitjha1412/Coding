#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int *x=(int*)a;
    int *y=(int*)b;
    return (*x)-(*y);
}
int fun(int a,int b,int c,int d,int e,int f,int g,int p)
{
    int q[7]={a,b,c,d,e,f,g},i;
    qsort(q,7,sizeof(int),cmp);
    return q[0];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p;
        scanf("%d %d",&n,&p);
        char s1[65000],s2[65000];
        scanf("%s %s",s1,s2);
        if(p==0)
        {
            printf("%d\n",n);
            continue;
        }
        int l[41]={0},i;
        for(i=1;i<=n;i++)
        {
            l[i]=(i*i*i*p)/100;
            if((i*i*i*p)%100)
                l[i]=l[i]+1;
        }
        int a[41][41][41]={0},j,k,count=0,max=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if(s1[i*n*n + j*n + k]==s2[i*n*n + j*n +k])
                        a[i][j][k]=1;
                    else
                        a[i][j][k]=0;
        int S[41][41][41]={0};
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    S[i][j][k]=a[i][j][k];
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                for(k=1;k<n;k++)
                {
                   if(a[i][j][k]==1)
                        S[i][j][k]=fun(S[i][j][k-1],S[i][j-1][k],S[i][j-1][k-1],S[i-1][j][k],S[i-1][j-1][k],S[i-1][j][k-1],S[i-1][j-1][k-1],p)+1;
                   else
                        S[i][j][k]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(max<S[i][j][k])
                    {
            printf("%d %d\n",max,count);
                        count=1;
                        max=S[i][j][k];
                    }
                    else if(max==S[i][j][k])
                        count++;
                }
            }
        }
        if(max==0)
            printf("-1\n");
        else
            printf("%d %d\n",max,count);
    }
    return 0;
}
