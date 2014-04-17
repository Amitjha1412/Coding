#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
    int s;
    int f;
    int c;
}node;
int cmp(const void *a,const void *b)
{
    node *x=(node *)a;
    node *y=(node *)b;
    if((x->c)==(y->c))
        return (x->f)-(y->f);
    return (x->c)-(y->c);
}
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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        node p[100100];
        int n,k;
       // scanf("%d %d",&n,&k);
        n=in();
        k=in();
        for(int i=0;i<n;i++)
        {
            //scanf("%d %d %d",&(p[i].s),&(p[i].f),&(p[i].c));
            p[i].s=in();
            p[i].f=in();
            p[i].c=in();
        }
        qsort(p,n,sizeof(int)*3,cmp);
        int count=0,curr=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(p[i].c==curr && p[i].s>=l)
            {
                count++;
                l=p[i].f;
            }
            if(p[i].c!=curr)
            {
                count++;
                curr=p[i].c;
                l=p[i].f;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
