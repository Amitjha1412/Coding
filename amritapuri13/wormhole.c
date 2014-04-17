#include<stdio.h>
#include<stdlib.h>

inline void Scan_f(long long int *a)
{
    char c = 0;
    while(c<33)
        //c = fgetc_unlocked(stdin);
        c = getc(stdin);
    *a = 0;
    while(c>33)
    {
        *a = *a*10 + c - '0';
        //c = fgetc_unlocked(stdin);
        c = getc(stdin);
    }
}

int cmpfunc (const void *a,const void *b)
{
    long long int i=*(long long int *)a;
    long long int j=*(long long int *)b;
    if(j>=i)
        return 1;
    return 0;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        long long int sum=0,a[10001];
        int i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            Scan_f(&a[i]);
        qsort(a,n,sizeof(long long int),cmpfunc);
        for(i=0;i<n;i++)
            sum+=a[i];
        int flag=0,ans=-1;
        for(i=0;i<n-2;i++)
        {
            if((2*a[i])<sum)
            {
                flag=1;
                ans=n-i;
                break;
            }
            else
                sum=sum-a[i];
        }
        if(flag==1)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
