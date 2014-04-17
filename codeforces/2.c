#include<stdio.h>
int hash[100015];

int main()
{
    int m,a,b,c,n,i,temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(hash[a] != 0)
        {
            if(hash[a] == 1)
            {
                hash[b] = 2;
                hash[c] = 3;
            }
            else if(hash[a] == 2)
            {
                hash[b] = 1;
                hash[c] = 3;
            }
            else if(hash[a] == 3)
            {
                hash[b] = 1;
                hash[c] = 2;
            }
        }
        else if(hash[b] != 0)
        {
            if(hash[b] == 1)
            {
                hash[a] = 2;
                hash[c] = 3;
            }
            else if(hash[b] == 2)
            {
                hash[a] = 1;
                hash[c] = 3;
            }
            else if(hash[b] == 3)
            {
                hash[a] = 1;
                hash[c] = 2;
            }
        }
        else if(hash[c] != 0)
        {
            if(hash[c] == 1)
            {
                hash[a] = 2;
                hash[b] = 3;
            }
            else if(hash[c] == 2)
            {
                hash[a] = 1;
                hash[b] = 3;
            }
            else if(hash[c] == 3)
            {
                hash[a] = 1;
                hash[b] = 2;
            }
        }
        else
        {
            hash[a] = 1;
            hash[b] = 2;
            hash[c] = 3;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",hash[i]);
    printf("\n");
    return 0;
}
