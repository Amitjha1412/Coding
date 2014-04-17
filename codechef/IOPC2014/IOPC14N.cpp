#include<cstdio>
#include<iostream>
#include<limits.h>
#define min(a,b)a>b?b:a
using namespace std;
int n[100100]={0};
char str[100100];
int main()
{
    int t,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        scanf("%d",&m);
        int min=INT_MAX;
        for(int i=1;str[i-1]!='\0';i++)
        {
            n[i]=0;
            if(str[i-1]=='A')
                n[i]=n[i-1]+1;
            else
                n[i]=n[i-1];
            if(i>=m)
            {
                int d=n[i]-n[i-m];
                int a=m-d;
                min=min(a,min);
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
