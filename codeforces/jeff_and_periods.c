#include<stdio.h>
int main()
{
    int max=0,n,a[100010],d[100010]={0},last[100010]={0},i;
    scanf("%d",&n);
//    printf("%d\n",n);
    for(i=1;i<=n;)
    {
        scanf("%d",&a[i]);
        int j=a[i];
        if(last[j]!=0)
        {
            int temp=i-last[j];
            if(d[j]==0)
                d[j]=temp;
            else if(d[j]==temp)
                d[j]=temp;
            else if(d[j]!=temp)
                d[j]=-1;
        }
        if(a[i]>max)
            max=a[i];
        last[j]=i;
        i++;
    }
    int j=0;
    for(i=1;i<=max;i++)
    {
        if(d[i]!=-1&&last[i])
            j++;
    }
    printf("%d\n",j);
    for(i=1;i<=max;i++)
    {
        if(d[i]!=-1&&last[i])
        {
            printf("%d %d\n",i,d[i]);
            d[i]=-1;
        }
    }
    return 0;
}
