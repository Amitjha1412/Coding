#include<stdio.h>
#include<stdlib.h>

typedef long long int lli;

inline void Scan_f(lli *a)
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
    lli i=*(lli *)a;
    lli j=*(lli *)b;
    if(j>=i)
        return 1;
    return 0;
}

int main()
{
    int n=0,i=0;
    lli a[100001],l=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       // scanf("%lld",&a[i]);
       Scan_f(&a[i]);
    qsort(a,n,sizeof(a[0]),cmpfunc);
    while(l<=a[0])
        l=l<<1;
    l=l>>1;
    int j;
    for(i=0;l>=1;l=l>>1)
    {
        int j=i;
        while(!(a[j]&l) && (j<n))
            j++;
        if(j<n)
        {
            a[i]=a[j]+a[i]-(a[j]=a[i]);
            for(j=0;j<n;j++)
                if(j!=i && (a[j]&l))
                    a[j]=a[j]^a[i];
            i++;
        }
    }
    lli ans=0;
    for(i=0;i<n;i++)
        ans=ans^a[i];
    printf("%lld\n",ans);
    return 0;
}
