#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#define gc() getchar_unlocked()
int isSpaceChar(char c) {
    return c == ' ' || c == '\n' || c == '\r' ;
}
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isSpaceChar(ch))
        ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
long long int a[1000000];
long long int power(long long int a, long long int b)
{
  long long int result = 1;
  while (b)
  {
    if (b&1)
    {
      result *= a;
    }
    b >>=1 ;
    a *= a;
  }

  return result;
}
long long int getMid(long long int s, long long int e)
{
    return s + (e -s)/2;
}
long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    long long int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) + getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
void updateValueUtil(long long int *st, long long int ss, long long int se, long long int i, long long int diff, long long int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        long long int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(long long int a[], long long int *st, long long int n, long long int i, long long int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
long long int diff = new_val - a[i];
    a[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
long long int getSum(long long int *st, long long int n, long long int qs, long long int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
long long int constructSTUtil(long long int a[], long long int ss, long long int se, long long int *st, long long int si)
{
    if (ss == se)
    {
        st[si] = a[ss];
        return a[ss];
    }
    long long int mid = getMid(ss, se);
    st[si] =  constructSTUtil(a, ss, mid, st, si*2+1) + constructSTUtil(a, mid+1, se, st, si*2+2);
    return st[si];
}
long long int *constructST(long long int a[], long long int n)
{
    long long int x = (long long int)(ceil(log2(n)));
    long long int max_size = 2*(long long int)power((long long int)2, x) - 1;
    long long int *st=malloc(sizeof(long long int)*max_size);
    constructSTUtil(a, 0, n-1, st, 0);
    return st;
}
int main()
{
    long long int n,q,i;
    scanf("%lld %lld",&n,&q);
    for(i=0;i<n;i++)
    {
       int  z=FAST_IO();
       a[i]=(long long int)z;
    }
    long long int *st=constructST(a,n);
    while(q--)
    {
        char Q[10];
        long long int x,y;
        scanf("%s %lld %lld",Q,&x,&y);
        if(Q[0]=='G')
            updateValue(a,st,n,x,a[x]+y);
        else if(Q[0]=='T')
            updateValue(a,st,n,x,a[x]-y);
        else
            printf("%lld\n",getSum(st,n,x,y));
    }
    return 0;
}
