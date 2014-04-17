#include<stdio.h>

int main()
{
    //char a[];
    int t,n,k,limit,cnt,pro,size[100];
    size[1]=1;
    size[2]=189;
    size[3]=2889;
    size[4]=38889;
    size[5]=488889;
    size[6]=5888889;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        cnt=0;
        pro=10;
        while(n>=pro)
        {
            cnt++;
            pro*=10;
        }pro/=10;
        limit=size[cnt]+cnt*(n-pro);
        printf("%d\n",limit);
    }
}
