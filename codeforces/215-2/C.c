#include<stdio.h>
int main()
{
    char s[100100];
    scanf("%s",s);
    int n,i;
    scanf("%d",&n);
    int count[100100][4]={0};
    for(i=0;s[i]!='\0';i++)
    {
        count[i+1][1]=count[i][1];
        count[i+1][2]=count[i][2];
        count[i+1][3]=count[i][3];
        if(s[i]=='x')
            count[i+1][1]++;
        if(s[i]=='y')
            count[i+1][2]++;
        if(s[i]=='z')
            count[i+1][3]++;
    }
    while(n--)
    {
        int l,r,j;
        scanf("%d %d",&l,&r);
        int c[4]={0};
        for(i=1;i<=3;i++)
            c[i]=count[r][i]-count[l-1][i];
        int flag=0;
        for(i=1;i<=3;i++)
        {
            for(j=i+1;j<=3;j++)
            {
                if(!(c[i]-c[j]<=1&&c[i]-c[j]>=-1))
                    flag=1;
            }
        }
        if(r-l<2)
            flag=0;
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
