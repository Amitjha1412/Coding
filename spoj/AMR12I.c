#include<stdio.h>
#include<string.h>
int main()
{
    int t,k,n;
    char c[20001];
    scanf("%d",&t);
    while(t--)
    {
        int i,ans;
        scanf("%d %d",&n,&k);
        scanf("%s",c);
        char pre=c[0];
        ans=1;
        int l=1,count=0;
        for(i=1;c[i]!='\0';i++)
        {
            if(c[i]==pre)
                l++;
            else
            {
                l=1;
                ans++;
            }
            if(l==k)
            {
                l=0;
                pre='1';
                count++;
            }
            else
                pre=c[i];
        }
        if(count)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
