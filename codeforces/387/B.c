#include<stdio.h>
int main()
{
    int n,m,i,a[10000],b[10000];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    int j=0;
    for(i=0;i<n && j<m;)
    {
        if(b[j]>=a[i])
        {
            j++;
            i++;
        }
        else
            j++;
    }
    printf("%d\n",n-i);
    return 0;
}
