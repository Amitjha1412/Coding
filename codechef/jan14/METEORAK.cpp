#include<cstdio>
#include<iostream>

using namespace std;

        #define getchar getchar_unlocked
        #define putchar putchar_unlocked
int in()
{
        char c;
        while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
        bool flag=(c=='-');
        if(flag) c=getchar();
        int x=0;
        while(c>='0'&&c<='9') {
                x=x*10+c-48;
                c=getchar();
        }
        return flag?-x:x;
}

void out(int x)
{
        if(x<0) {
                putchar('-');
                x=-x;
        }
        int len=0,data[10];
        while(x) {
                data[len++]=x%10;
                x/=10;
        }
        if(!len)
        data[len++]=0;
        while(len--) putchar(data[len]+48);
        putchar('\n');
}
bool mat[1010][1010];
int aux[1010][1010],ans[1010][1010];
int h[1010][2];
#define max(a,b)a>b?a:b
int main()
{
    int n,m,k,q;
    for(int i=0;i<1010;i++)
        for(int j=0;j<1010;j++)
        {
            mat[i][j]=1;
            aux[i][j]=ans[i][j]=0;
        }
    n=in();
    m=in();
    k=in();
    while(k--)
    {
        int a,b;
        a=in();
        b=in();
        mat[a][b]=0;
    }
    for(int j=1;j<=m;j++)
        for(int i=n,count=0;i>-0;i--)
        {
            if(mat[i][j]==0)
                count=0;
            else
            {
                count++;
                aux[i][j]=count;
            }
        }
    /*for(int i=1;i<=n;i++)
      {
      for(int j=1;j<=m;j++)
      printf("%d ",aux[i][j]);
      printf("\n");
      }*/
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<=n;j++)
        {
            h[j][0]=-1;
            h[j][1]=0;
        }
        for(int j=1,maxh=0;j<=m;j++)
        {
            int x=aux[i][j];
            maxh=max(maxh,x);
            //if(h[x][0]==-1 && x>0)
           // {
                for(int k=1;k<=x;k++)
                {
                    //if(h[x+1][0]!=-1 && x<n)
                      //  h[x][0]=h[x+1][0];
                    //else
                    if(h[k][0]==-1 && x>0)
                        h[k][0]=j;
                }
           // }
            for(int k=x+1;k<=maxh;k++)
            {
                if(h[k][0]>0)
                    h[k][1]=max(h[k][1],(j-h[k][0]));
                h[k][0]=-1;
            }
            maxh=x;
        }
        for(int k=n,maxh=0;k>0;k--)
        {
            if(h[k][0]>0)
                h[k][1]=max(h[k][1],(m-h[k][0]+1));
            maxh=max(maxh,h[k][1]);
            h[k][1]=maxh;
        }
       // for(int k=1;k<=n;k++)
         //   printf("%d ",h[k][1]);
        //printf("\n");
        for(int j=i,k=1;j<=n;j++,k++)
        {
            ans[i][j]=h[k][1]*k;
            if(i<n)
                ans[i][j]=max(ans[i][j],ans[i+1][j]);
            if(j>1)
                ans[i][j]=max(ans[i][j],ans[i][j-1]);
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        a=in();
        b=in();
        out(ans[a][b]);
    }
    return 0;
}
