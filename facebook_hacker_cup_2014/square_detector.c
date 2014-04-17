#include<stdio.h>
int main()
{
    int t,n,i,flag=0;
    int square[401]={0};
    for(i=0;i<=20;i++)
        square[i*i]=i;
    scanf("%d",&t);
    int k;
    for(k=1;k<=t;k++)
    {
        flag=0;
        int a[25][25]={0};
        int side=0,j;
        char s[100];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=0;j<n;j++)
            {
                if(s[j]=='#')
                    a[i][j]=1;
                else
                    a[i][j]=0;
                if(a[i][j]==1)
                    side++;
            }
        }
        int total=side;
        if(square[side])
        {
            side=square[side];
            for(i=0;i<n && total && flag==0;i++)
            {
                int count=0;
                for(j=0;j<n;j++)
                {
                    if(a[i][j]==1)
                    {
                        count++;
                        total--;
                        if(!(a[i][j+1]==1 || count>=side))
                        {
                            flag=1;
                            break;
                        }
                        if(!(a[i+1][j]==1 || total<=side))
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            flag=1;
        }
        if(flag==1)
            printf("Case #%d: NO\n",k);
        else if(flag==0)
            printf("Case #%d: YES\n",k);
    }
    return 0;
}
