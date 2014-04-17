#include<stdio.h>

    int f[305];
int a[400][3];

int f1(int a,int b,int c)
{
    int z = max(a,b);
    int y = max(z,c);

    int p = min(a,b);
    int q= min(p,c);

    return y - q;
}

int group(int i)
{
    int c1 = f1(a[i][0],a[i][1],a[i][2]) +  f1(a[i+1][0],a[i+1][1],a[i+1][2]) +  f1(a[i+2][0],a[i+2][1],a[i+2][2]);
    int c2 = f1(a[i][0],a[i+1][0],a[i+2][0]) +  f1(a[i][1],a[i+1][1],a[i+2][1]) +  f1(a[i][2],a[i+1][2],a[i+2][2]);

    int c = min(c1,c2);

        int z = f1(a[i][0],a[i][1],a[i+1][0]);
        int b = f1(a[i][1],a[i][2],a[i+1][2]);
        int c = f1(a[i][0],a[i+1][0],a[i+1][1]);
        int d = f1(a[i][2],a[i+1][2],a[i+1][1])
            ;

}

int calculate(int i)
{
    int p = group(i-2);
    p = p + f[i-3];

        int z = f1(a[i-1][0],a[i-1][1],a[i][0]);
        int b = f1(a[i-1][1],a[i-1][2],a[i][2]);
        int c = f1(a[i-1][0],a[i][0],a[i][1]);
        int d = f1(a[i-1][2],a[i][2],a[i][1]);
        int tmp = min((z+c),(b+d));

        int q = tmp + f[i-2];

    int r = f1(a[i][0],a[i][1],a[i][2]) + f[i-1];

    if( p < q)
    {
        if( p < r) return p;
        else return r;
    }
    else
    {
        if(q < r) return q;
        else return r;
    }
}



int main()
{
    int t,n,j,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&a[i][j]);

        f[1] = f1(a[1][0],a[1][1],a[1][2]);
        int z = f1(a[1][0],a[1][1],a[2][0]);
        int b = f1(a[1][1],a[1][2],a[2][2]);
        int c = f1(a[1][0],a[2][0],a[2][1]);
        int d = f1(a[1][2],a[2][2],a[2][1]);
        int tmp = min((z+c),(b+d));

        int x  = f[1] + f1(a[1][0],a[1][2],a[1][1]);
        f[2] = min(tmp, x);

        for(i=3;i<=n;i++)
            f[i] = calculate(i);

        printf("%d\n",f[n]);
    }
}
