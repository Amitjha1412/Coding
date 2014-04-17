#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n=n<<1;
    double sum=0.0,a;
    while(n--)
    {
        scanf("%lf",&a);
        sum=sum+a;
    }
    long long int b=sum;
    double diff1=sum-b;
    double diff2=b+1-sum;
    if(diff1>diff2)
    printf("%0.3lf\n",diff2);
    else
        printf("%0.3lf\n",diff1);
    return 0;
}
