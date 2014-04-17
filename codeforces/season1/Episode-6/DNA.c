#include<stdio.h>
char s[1000005];

char c;
int main()
{
    int f[1000005], g[1000005];
    int n,i;
    scanf("%d",&n);
    scanf("%s",s);
    f[0]=g[0]=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            f[i+1]=f[i];
            if(f[i]>g[i])
                g[i+1]=1+g[i];
            else
                g[i+1]=1+f[i];
        }
        else
        {
            g[i+1]=g[i];
            if(f[i]>g[i])
                f[i+1]=1+g[i];
            else
                f[i+1]=1+f[i];
        }
    }
    printf("%d\n",f[n]);
    return 0;
}

