#include<stdio.h>

int main()
{
    int n,i,one,two,three,four,s;
    one = two = three = four =0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s);
        if(s==1) one++;
        else if(s==2) two++;
        else if(s==3) three++;
        else if(s==4) four++;
    }
    int ans = 0;
    if(one==0 && two==0)
    {
        printf("0\n");
        return 0;
    }
    while(one>1 || two>1)
    {
        if(one > 1)
        {
            ans += one/2;
            two += one/2;
            one -= 2*(one/2);
        }

        if(two > 1)
        {
            ans += two / 2;
            four += two/2;
            two -= 2*(two/2);
        }

        if ( one <= two )
        {
            ans += one;
            two -= one;
            one = 0;
        }
        else if( two <= one )
        {
            ans += two;
            one -= two;
            two = 0;
        }

    }

    if(one==0 && two==0)
    {
        printf("%d\n",ans);
        return 0;
    }

    if(one==1 && two==1)
    {
        one =0;
        two =0;
        ans++;
    }
    else
    {
        if(one==1 && four>1)
            ans += 2;
        else if(two==1 && four>0)
            ans += 1;
        else
            ans = -1;
    }
    printf("%d\n",ans);
    return 0;
}
