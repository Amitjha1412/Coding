#include<cstdio>
#include<iostream>
#include<cstdlib>
    int a[1110001];
int cmp(const void * a,const void *b)
{
    int *x=(int*)a;
    int *y=(int *)b;
    return (*x)-(*y);
}
using namespace std;
int main()
{
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=1110000;i++)
        a[i]=(a[i-1]+a[i-2])%100000;
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int m,n,f[1110001];
        scanf("%d %d",&m,&n);
        int j=0;
        for(int i=m;i<=m+n;i++,j++)
            f[j]=a[i];
        n=j;
        qsort(f,j,sizeof(int),cmp);
        printf("Case %d: ",test);
        for(int i=0;i<n && i<100;i++)
            printf("%d ",f[i]);
        printf("\n");
    }
    return 0;
}
