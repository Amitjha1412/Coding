#include<stdio.h>
int main()
{
    int t,h,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&a);
        int ans=0;
        while(1)
        {
            ans++;
            a+=2;
            h+=3;
            int a1=h-5;
            int a2=h-20;
            int b1=a-10;
            int b2=a+5;
            int c1=a1-b1;
            int c2=a2-b2;
            if(c1<0)
                c1=-c1;
            if(c2<0)
                c2=-c2;
            if(c1>c2)
            {
           //     printf("1\n");
                h=a2;
                a=b2;
            }
            else
            {
           //     printf("2\n");
                h=a1;
                a=b1;
            }
            if(h<=0 ||a<=0)
                break;
            else
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
