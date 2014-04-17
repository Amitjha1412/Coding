#include<stdio.h>
int main()
{
    int n;
    int count_5=0,count_0=0,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a==5)
            count_5++;
        else if(a==0)
            count_0++;
    }
    if(count_0==0)
    {
        printf("-1\n");
        return 0;
    }
    n=count_5/9;
    if(n==0)
        count_0=1;
    while(n--)
        printf("555555555");
    while(count_0--)
        printf("0");
    printf("\n");
    return 0;
}
