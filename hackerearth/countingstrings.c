#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,temp=0;
        char M[1000010];
        long long int ans=0;
        scanf("%s",M);
        for(i=0;M[i]!='\0';i++)
        {
            if(M[i]=='a'||M[i]=='z')
            {
                ans=ans+(i+1);
                temp=i+1;
            }
            else
                ans=ans+temp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
