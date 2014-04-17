#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return (*y)-(*x);
}
int main()
{
    int t,n,a[100000];
    scanf("%d",&t);
    while(t--)
    {
        long long int sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int ans=-1;
        qsort(a,n,sizeof(int),cmp);
        for(int i=0;i<n;i++)
        {
            sum-=(long long int)a[i];
            if((long long int)a[i]<sum)
            {
                ans=n-i;
                break;
            }
        }
        if(ans>2)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
