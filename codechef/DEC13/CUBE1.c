#include<stdio.h>
#include<stdlib.h>
int min(int a,int b,int c)
{
    int m=a;
    if(m>b)
        m=b;
    if(m>c)
        m=c;
    return m;
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
            printf("%d 1\n",n);
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
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    if(s1[(i-1)*n*n + (j-1)*n + (k-1)]==s2[(i-1)*n*n + (j-1)*n +(k-1)])
                        a[i][j][k]=1;
                    else
                        a[i][j][k]=0;
        int S[41][41][41]={0},ans[41][41][41]={0},v;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                for(k=0;k<=n;k++)
                {
                    S[i][j][k]=a[i][j][k];
                    ans[i][j][k]=a[i][j][k];
                }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    S[i][j][k]+=S[i][j][k-1]+S[i][j-1][k]+S[i-1][j][k]+S[i-1][j-1][k-1]-S[i][j-1][k-1]-S[i-1][j][k-1]-S[i-1][j-1][k];
                    int m=min(i,j,k);
                    for(v=m;v>0;v--)
                        if(((S[i][j][k]+S[i-v][j-v][k]+S[i-v][j][k-v]+S[i][j-v][k-v])-(S[i-v][j][k]+S[i][j][k-v]+S[i][j-v][k]+S[i-v][j-v][k-v]))>=l[v])
                        {
                            ans[i][j][k]=v;
                            break;
                        }
                    if(max<ans[i][j][k])
                    {
                        count=1;
                        max=ans[i][j][k];
                    }
                    else if(max==ans[i][j][k])
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
