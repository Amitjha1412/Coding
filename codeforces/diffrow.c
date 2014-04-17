#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    int n,max,min,min_loc,max_loc,i,j,A[10000];
    scanf("%d",&n);
    min=10000;
    max=-10000;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<min)
        {
            min=A[i];
            min_loc=i;
        }
        if(A[i]>max)
        {
            max=A[i];
            max_loc=i;
        }
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(i!=min_loc && i!=max_loc)
            A[j++]=A[i];
    }
    for(i=0;i<n-2;i++)
    {
        qsort(A,n-2,sizeof(int),cmpfunc);
    }
    printf("%d ",max);
    for(i=0;i<n-2;i++)
    {
        printf("%d ",A[i]);
    }printf("%d\n",min);
    return 0;
}

