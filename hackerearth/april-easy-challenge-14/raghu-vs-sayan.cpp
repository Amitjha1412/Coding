#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
    int *x=(int*)a;
    int *y=(int*)b;
    return (*x)-(*y);
}
int main()
{
    int t,n,c[11000];
    long long int s[11000],a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %d",&a,&b,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        qsort(c,n,sizeof(int),cmp);
        s[0]=(long long )c[0];
        int  flag=0;
        for(int i=0;i<n;i++)
            s[i]=s[i-1]+(long long)c[i];
        int i,r,sa;
        for(i=0;i<n && a>=s[i];i++);
        r=i-1;
        for(i=0;i<n && b>=s[i];i++);
        sa=i-1;
        if(r>sa)
            printf("Raghu Won\n");
        else if(sa>r)
            printf("Sayan Won\n");
        else
            printf("Tie\n");
    }
    return 0;
}
