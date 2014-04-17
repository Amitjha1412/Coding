#include<stdio.h>
#define min(a,b) a>b?b:a
int main()
{
    int n,l,r,q1,q2,i,j,w[1000000],p1,p2,flag;
    scanf("%d %d %d %d %d",&n,&l,&r,&q1,&q2);
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    i=1;j=n;
    p1=w[1]*l;
    i++;
    p1+=w[n]*r;
    j--;
    flag=1;
    while(i<=j)
    {
        int temp1,temp2;
        if(flag==0)
        {
            temp1=w[i]*l+q1;
            temp2=w[j]*r;
            if(temp1>temp2)
            {
                j--;
                p1+=temp2;
                flag=1;
            }
            else
            {
                i++;
                p1+=temp1;
            }
        }
        else
        {
            temp1=w[i]*l;
            temp2=w[j]*r+q2;
            if(temp1>temp2)
            {
                j--;
                p1+=temp2;
            }
            else
            {
                i++;
                p1+=temp1;
                flag=0;
            }
        }
    }


    i=1;j=n;
    p2=w[n]*r;
    j--;
    p2+=w[1]*l;
    i++;
    flag=0;
    while(i<=j)
    {
        int temp1,temp2;
        if(flag==0)
        {
            temp1=w[i]*l+q1;
            temp2=w[j]*r;
            if(temp1>temp2)
            {
                j--;
                p2+=temp2;
                flag=1;
            }
            else
            {
                i++;
                p2+=temp1;
            }
        }
        else
        {
            temp1=w[i]*l;
            temp2=w[j]*r+q2;
            if(temp1>temp2)
            {
                j--;
                p2+=temp2;
            }
            else
            {
                i++;
                p2+=temp1;
                flag=0;
            }
        }
    }
    printf("%d\n",min(p1,p2));
    return 0;
}
