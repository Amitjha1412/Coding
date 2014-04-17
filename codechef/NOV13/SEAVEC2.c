#include<stdio.h>
#include<stdlib.h>
#define gc() getchar_unlocked()
int isSpaceChar(char c) {
    return c == ' ' || c == '\n' || c == '\r' ;
}
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isSpaceChar(ch))
        ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x)-(*y);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j,s[100000],ans[100000],m=0;
        long long int sum=0;
        scanf("%d %d",&n,&k);
        if(k>1)
        {
            int a[n][k];
            for(i=0;i<n;i++)
                for(j=0;j<k;j++)
                    // scanf("%d",&a[i][j]);
                    a[i][j]=FAST_IO();
            for(j=0;j<k;j++)
                // scanf("%d",&s[j]);
                s[j]=FAST_IO();
            if(n>9)
            {
                int z;
                int l=0;
                    for(i=0;i<n;i++)
                    {
                        int flag=0;
                        for(j=0;j<k&&flag==0;j++)
                            if(s[j]<a[i][j])
                                flag=1;
                        if(flag==0)
                        {
                            for(sum=j=0;j<k;j++)
                                sum+=a[i][j];
                            if(sum>max)
                            {
                                max=sum;
                                z=i;
                            }
                        }
                    }
                    if(z==-1)
                        break;
                    else
                    {
                        ans[m++]=z;
                        for(j=0;j<k;j++)
                        {
                            s[j]-=a[z][j];
                            a[z][j]=-2;
                        }
                    }
                    l++;
                }
                printf("%d\n",m);
                for(i=0;i<n;i++)
                    if(a[i][0]==-2)
                        printf("%d ",i+1);
            }
            else
            {
                int v,x,min=1,an,bit=1;
                for(i=0;i<n;i++)
                    bit=bit<<1;
                for(i=0;i<10;i++)
                    min=min<<1;
                m=0;
                for(v=bit-1;v>0;v--)
                {
                    int su[100001]={0},flag=0;
                    for(x=1,i=0;v>=x&&flag==0;x=x<<1,i++)
                    {
                        if(v&x)
                        {
                            for(j=0;j<k;j++)
                            {
                                su[j]+=a[i][j];
                                if(s[j]<su[j])
                                {
                                    flag=1;
                                    break;
                                }
                            }
                        }
                    }
                    for(sum=j=0;j<k;j++)
                    {
                        sum+=s[j]-su[j];
                        if(s[j]<su[j])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        if(sum<min)
                        {
                            min=sum;
                            an=v;
                        }
                        // printf("%lld %lld\n",an,v);
                    }
                }
                for(i=0,x=1;an>=x;x=x<<1,i++)
                {
                    if(an&x)
                    {
                        ans[m++]=i;
                    }
                }
                printf("%d\n",m);
                for(i=0;i<m-1;i++)
                    printf("%d ",ans[i]+1);
                if(m)
                    printf("%d\n",ans[i]+1);
            }
        }
    }
    return 0;
}
