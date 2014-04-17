#include<stdio.h>

int V[1009][1009],c[110],p[110],t[110];

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int z,n,k,i,v,j,w;
    scanf("%d",&z);
    for(i=1;i<=z;i++)
    {
        scanf("%d%d",&n,&k);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[j]);
            scanf("%d",&p[j]);
            scanf("%d",&t[j]);
        }
        for(w=0;w<=k;w++)
        {
            V[0][w]=0;
            if(t[1]<=w)
                V[1][w]=c[1]*p[1];
            else
                V[1][w]=0;
        }
        for(v=2;v<=n;v++)
        {
            for(w=0;w<=k;w++)
            {
                if(t[v]<=w)
                    V[v][w]=max(V[v-1][w],(c[v]*p[v]+V[v-1][w-t[v]]));
                else
                    V[v][w]=V[v-1][w];
            }
        }
        printf("%d\n",V[n][k]);
    }
    return 0;
}
