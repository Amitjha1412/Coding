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

    int count=0;
    while(count==0)
    {
        int temp=a[n-2]-a[n-1];
        ans+=temp+1;
        for(i=0;i<n-1;i++)
        {
            a[i]-=(temp+1);
            if(!a[i])
                count++;
        }
 // if(temp==1)
        qsort(a,n,sizeof(int),cmpfunc);
   //     else
     //       a[n-1]=a[n-2]+a[n-1]-(a[n-2]=a[n-1]);
    }
    cout << ans+a[0]<<"\n";
    return 0;
}
