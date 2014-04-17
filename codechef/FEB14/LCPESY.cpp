#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s1[100000],s2[100000];
        int A[1000]={0};
        int ans=0;
        scanf("%s",s1);
        scanf("%s",s2);
        for(int i=0;s1[i]!='\0';i++)
            A[s1[i]]++;
        for(int i=0;s2[i]!='\0';i++)
            if(A[s2[i]])
            {
                A[s2[i]]--;
                ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
