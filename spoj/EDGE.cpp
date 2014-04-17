#include<cstdio>
#include<cstring>
#include<iostream>
#define R 1
#define L 2
#define U 3
#define D 4
using namespace std;
int main()
{
    char in[2000];
    while(scanf("%s",in)!=EOF)
    {
        int m,x,y;
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        x=310;
        y=420;
        m=R;
        for(int i=0;in[i]!='\0';i++)
        {
            if(in[i]=='A')
            {
                if(m==R)
                {
                    m=D;
                    y=y-10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==D)
                {
                    m=L;
                    x=x-10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==L)
                {
                    m=U;
                    y=y+10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==U)
                {
                    m=R;
                    x=x+10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
            }
            else if(in[i]=='V')
            {
                if(m==R)
                {
                    m=U;
                    y=y+10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==D)
                {
                    m=R;
                    x=x+10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==L)
                {
                    m=D;
                    y=y-10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
                else if(m==U)
                {
                    m=L;
                    x=x-10;
                    if(x>=0 && y>=0)
                        printf("%d %d lineto\n",x,y);
                    else
                        break;
                }
            }
        }
        printf("stroke\n");
        printf("showpage\n");
    }
    return 0;
}
