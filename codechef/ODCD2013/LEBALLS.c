#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%d",&n);
        char c=getchar();
        int pre=0,j,i,max=-1;
        for(i=0;i<n;i++)
        {
            c=getchar();
            int a=c-'0';
            if(!(a>max||a==pre+1))
                flag=1;
            max=max(max,a);
            pre=a;
        }
        if(flag==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
