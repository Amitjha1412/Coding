#include<stdio.h>

#define max(a,b) a>b?a:b
int main()
{
    int t,size,i,j,k,l,m,n,u,v;
    char a[104][104];
    scanf("%d",&t);
    while(t--)
    {
        size = 0;
        char ch;
        scanf("%d %d",&n,&m);
        ch = getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                a[i][j] = getchar();
            ch = getchar();
        }

        int p=1,q=1,flag;
        while(p<=n)
        {
        //            printf("c\n");
            for(i=0;i<n;i++)
            {
                //    printf("b\n");
                q=1;
                while(q<=m)
                {
           //         printf("a\n");
                    for(j=0;j<m;j++)
                    {
                        for(k=0;k<n;k++)
                        {
                            for(l=0;l<m;l++)
                            {
                                flag=0;
                                if( !(i==k && j==l) && (i+p-1)<n && (k+p-1)<n && (j+q-1)<m && (l+q-1)<m)
                                {
                                    for(u=0;(u<p && flag==0);u++)
                                        for(v=0;v<q;v++)
                                            if(a[i+u][j+v]!=a[k+u][l+v])
                                            {
                                            //    if(i==0 && j==0 && k==1 && l==0 && p==1 &&  q==1 ) printf("asdsd\n");
                                                flag=1;
                                                break;
                                            }
                                }
                                else
                                    flag = 1;
                                if(flag == 0)
                                {
                                //    printf("%d %d %d %d %d %d\n",i,j,k,l,p,q);
                                    size  = max(size,(p*q));
                                    break;
                                }
                            }
                        }
                    }
                    q++;
                }
            }
            p++;
        }
        printf("%d\n",size);
    }
    return 0;
}
