#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
 using namespace std;

int l[3000]={0};

long long int palindromes(char *seq)
{
    int k=0,i=0,palLen=0,seqLen=strlen(seq);
    while(i<seqLen)
    {
        if(i>palLen && seq[i-palLen-1]==seq[i])
        {
            palLen+=2;
            i+=1;
            continue;
        }
        l[k++]=palLen;
        int s=k-2,e=s-palLen,flag=0;
        for(int j=s;j>e;j--)
        {
            int d=j-e-1;
            if(l[j]==d)
            {
                palLen=d;
                flag=1;
                break;
            }
            l[k++]=min(d,l[j]);
        }
        if(flag==0)
        {
            palLen=1;
            i+=1;
        }
    }
    l[k++]=palLen;
    int lLen=k,s=lLen-2,e=s-(2*seqLen+1-lLen);
    for(int i=s;i>e;i--)
    {
        int d=i-e-1;
        l[k++]=min(d,l[i]);
    }
    long long int ret=0;
    for(int i=0;i<k;i++)
    {
        if(l[i]%2==1)
            ret+=(l[i]+1)/2;
        else
            ret+=(l[i])/2;
    }
    return ret;
}

int main()
{
    char s[1010];
    scanf("%s",s);
    long long int n=palindromes(s);
    printf("%lld\n",n);
    return 0;
}
