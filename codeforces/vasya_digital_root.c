#include<stdio.h>
int main()
{
    int d,k;
    scanf("%d %d",&k,&d);
    if(d)
    {
    printf("%d",d);
    k=k-1;
    while(k--)
        printf("0");
    printf("\n");
    }
    else
    {
        if(k==1)
            printf("0\n");
        else
            printf("No solution\n");
    }
    return 0;
}
