#include<cstdio>
#include<iostream>
using namespace std;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
int in()
{
    char c;
    while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
    bool flag=(c=='-');
    if(flag) c=getchar();
    int x=0;
    while(c>='0'&&c<='9') {
        x=x*10+c-48;
        c=getchar();
    }
    return flag?-x:x;
}
int main()
{
    int t,i,pos,max,n,k;
    scanf("%d",&t);
    while(t--)
    {
        max=-1;
        n=in();
        k=0;
        while(n--)
        {
            i=in();
            if((i+k)>=max)
                max=i+k;
            k++;
        }
        printf("%d\n",max);
    }
    return 0;
}
