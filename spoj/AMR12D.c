#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        int len,i,j;
        char S[100];
        scanf("%s",S);
        len=strlen(S);
        for(i=0,j=len-1;j>i;i++,j--)
            if(S[i]!=S[j])
            {
                flag=1;
                break;
            }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
