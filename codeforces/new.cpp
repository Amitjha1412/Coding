#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int cmpfunc(const void *a,const void *b)
{
    return (*(int *)b-*(int*)a);
}
int main()
{
    int n,a[100050],i;
    long long int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmpfunc);
    int b[3];
    b[0]=a[n-3];b[1]=a[n-2];b[2]=a[n-1];
    int count=0;
    int steps=b[2];
    int x=a[0];
    while(count==0)
    {
        int temp=b[1]-b[2]+1;
        ans+=temp;
        printf("A %lld\n",ans);
        for(i=0;i<2;i++)
        {
            b[i]-=(temp);
            if(!b[i])
                count++;
        }
        if((x-temp)<b[2])
            x=b[2];
        else
            x=x-temp;
        qsort(b,3,sizeof(int),cmpfunc);
    }
    printf("%lld\n",ans);
    cout << x+ans <<"\n";
    return 0;
}
