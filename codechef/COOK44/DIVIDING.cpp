#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=(long long)a;
    }
    sum=sum*2;
    sum=sum/n;
    sum=sum/(n+1);
    if(sum==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
