#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


#define getchar getchar_unlocked
#define putchar putchar_unlocked
int in()
{
    char c;
    while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
    bool flag=(c=='-');
    if(flag) c=getchar();
    int x=0;
    while(c>='0'&&c<='9') {
        x=x*10+c-48;
        c=getchar();
    }
    return flag?-x:x;
}

void out(int x)
{
    if(x<0) {
        putchar('-');
        x=-x;
    }
    int len=0,data[10];
    while(x) {
        data[len++]=x%10;
        x/=10;
    }
    if(!len)
        data[len++]=0;
    while(len--) putchar(data[len]+48);
    putchar('\n');
}
int bitcount(int num) {
    int count = 0;
    for(long long int i=1;i<=num;i=i*2,count++);
    return count;
}
int a[100011],b[100011],bit[100011][33];
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x)-(*y);
}
int bsearch(int AR[], int N, int VAL)
{
    int Mid,Lbound=1,Ubound=N;

    while(Lbound<=Ubound)
    {
        Mid=(Lbound+Ubound)/2;
        if(VAL>AR[Mid])
            Lbound=Mid+1;
        else if(VAL<AR[Mid])
            Ubound=Mid-1;
        else
            return Mid;
    }
    return 0;
}
int main()
{
    int n;
    n=in();
    a[0]=0,b[0]=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=in();
        b[i]=a[i];
    }
    qsort(a,n+1,sizeof(int),cmp);
    for(int j=0;j<33;j++)
        bit[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<33;j++)
            bit[i][j]=bit[i-1][j];
        bit[i][bitcount(b[i])-1]+=b[i];
    }
    int q,m;
    q=in();
    while(q--)
    {
        m=in();
        n=in();
        int max=0;
        long long int s[35],c[35];
        for(int i=0;i<=35;i++)
            s[i]=0;
        for(int i=m,j=n,k=0;k<33;k++)
            s[k]=bit[j][k]-bit[i-1][k];
        c[0]=s[0];
        for(int i=0;i<=32;i++)
            c[i]=0;
        for(int i=1;i<=32;i++)
            c[i]=c[i-1]+s[i];
        for(int k=0;k<=32;k++)
        {
            int i=bsearch(a,n+1,1<<k),j=bsearch(a,n+1,c[k]+1);
            if(j>=i && j!=0 && i!=0)
                continue;
            else
            {
                max=c[k];
                break;
            }
        }
        out(max+1);
    }
    return 0;
}
