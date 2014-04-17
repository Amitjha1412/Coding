#include <stdio.h>
int SubsetSum(int set[], int n, int sum,int subset[100001][101])
{
    int i,j;
    for (i = 0; i <= n; i++)
        subset[0][i] = 1;
    for (i = 1; i <= sum; i++)
        subset[i][0] = 0;
    for (i = 1; i <= sum; i++)
    {
        for (j = 1; j <= n; j++)
        {
            subset[i][j] = subset[i][j-1];
                if (i >= set[j-1])
                    subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
        }
    }
    return subset[sum][n];
}
int main()
{
    int n,k,a[111],b[111],i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int max;
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        max+=b[i];
    }
    int subseta[100001][101]={0},subsetb[100001][101]={0};
    SubsetSum(a,n,max*k,subseta);
    SubsetSum(b,n,max,subsetb);
    for(i=max*k;i>0;i--)
    {
        double z=i/k;
        if(z==(int)z)
        if(subsetb[(int)z][n]==1)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
