#include<cstdio>
#include<iostream>
using namespace std;
long long int gcd(long long int x,long long int y)
{
    while(x)
    {
        int temp=x;
        x=y%x;
        y=temp;
    }
    return y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int x=x2-x1;
        int y=y2-y1;
        if(x<0)
            x=-1*x;
        if(y<0)
            y=-1*y;
        if(y>x)
            x=x+y-(y=x);
        //if(x &&y)
            printf("%lld\n",gcd(x,y)-1);
        //else if(x)
          //  printf("%d\n",x);
    }
    return 0;
}
