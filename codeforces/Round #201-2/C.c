#include<stdio.h>
int max=-1,a[1000],n;
int gcd(int a,int b)
{
    if(b>a)
        a=b+a-(b=a);
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void arraygcd(int a[],int n)
{
    int i,g;
    g=a[0];
    for(i=1;i<n;i++)
    {
        g=gcd(a[i],g);
    }
    max=max/g;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(max<a[i])
            max=a[i];
    }
    arraygcd(a,n);
    int ans=max-n;
    if(ans&1)
        printf("Alice\n");
    else
        printf("Bob\n");
    return 0;
}
