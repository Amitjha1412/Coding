#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,n,c;
        scanf("%d %d %d",&s,&n,&c);
        s=s-n;
        if(s<0)
            s=0;
        if(s&1)
            s=s/2+1;
        else
            s=s/2;
        if(s<0)
            s=0;
        if(s<=c)
            printf("YES %d\n",s);
        else
            printf("NO\n");
    }
    return 0;
}
