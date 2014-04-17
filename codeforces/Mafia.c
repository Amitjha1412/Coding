#include<stdio.h>
#include<algorithm>
#include<iostream>
int cmpfunc(const void *a,const void *b)
{
    return (*(int *)a-*(int*)b);
}
int main()
{
    int n,a[100050],i;
    long long int ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        qsort(a,n,sizeof(int),cmpfunc);
    for(i=0;i<n;i++)
    {
        if(a[i]-i>0)
            ans=ans+(a[i]-i);
        else break;
    }
    printf("%I64d\n",ans);
    return 0;
}
