#include<stdio.h>

int main()
{
    int n,c[1000],x,y,i,s[1000];
    scanf("%d",&n);
    scanf("%d",&c[0]);
    s[0] = c[0];
    for(i=1;i<n;i++)
    {
        scanf("%d",&c[i]);
        s[i] = s[i-1] + c[i];
    }
    scanf("%d %d",&x,&y);
    int flag = 0;
    for(i=0;i<n;i++)
    {
        if(s[i] >= x && s[i]<=y && (s[n-1]-s[i])<=y && (s[n-1]-s[i])>=x)
        {
            printf("%d\n",i+2);
            flag = 1;
            break;
        }
    }
    if(!flag) printf("0\n");
    return 0;
}
