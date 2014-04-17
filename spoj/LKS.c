#include<stdio.h>
void knapsack(int n,int W,int weight[],int v[]);
int C[2000001];
int main()
{
    int i,n,W,weight[501],v[501];
    scanf("%d %d",&W,&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&v[i],&weight[i]);
    knapsack(n,W,weight,v);
    return 0;
}
void knapsack(int n,int W,int weight[],int v[])
{
    int i,w;
    for(i = 0; i <= W; i++){
        C[i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(w=W;w>=0;w--)
            if(weight[i]<=w)
                if(v[i]+C[w-weight[i]]>C[w])
                    C[w]=v[i]+C[w-weight[i]];
    }
        printf("%d\n",C[W]);
}
