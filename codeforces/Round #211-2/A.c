#include<stdio.h>
void fun(int n)
{
    if(n==0)
        printf("O-|-OOOO\n");
    else if(n==1)
        printf("O-|O-OOO\n");
    else if(n==2)
        printf("O-|OO-OO\n");
    else if(n==3)
        printf("O-|OOO-O\n");
    else if(n==4)
        printf("O-|OOOO-\n");
    else if(n==5)
        printf("-O|-OOOO\n");
    else if(n==6)
        printf("-O|O-OOO\n");
    else if(n==7)
        printf("-O|OO-OO\n");
    else if(n==8)
        printf("-O|OOO-O\n");
    else if(n==9)
        printf("-O|OOOO-\n");
}
int main()
{
    int n,m;
    scanf("%d",&n);
    if(n==0)
        fun(m);
    while(n>0)
    {
        m=n%10;
        n=n/10;
        fun(m);
    }
    return 0;
}
