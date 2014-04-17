#include<stdio.h>
int main()
{
    int t,i;
    char c;
    scanf("%d",&t);
    c=getchar();
    while(t--)
    {
        char in[30],out[150011];
        i=0;
        scanf("%s",in);
        c=getchar();
        while((c=getchar())!='\n')
            out[i++]=c;
        out[i]='\0';
        int a[26]={0},map[26]={0},j,k;
        for(i=0;out[i]!='\0';i++)
        {
            if(out[i]>='a'&&out[i]<='z')
                a[out[i]-'a']++;
            else if(out[i]>='A'&&out[i]<='Z')
                a[out[i]-'A']++;
        }
        for(i=25;i>=0;i--)
        {
            int max=-1,index=30;
            for(j=25;j>=0;j--)
            {
                if(a[j]>max)
                {
                    max=a[j];
                    index=j;
                }
            }
            map[index]=i;
            a[index]=-1;
        }
        for(i=0;out[i]!='\0';i++)
        {
            if(out[i]>='a'&&out[i]<='z')
            {
                k=map[out[i]-'a'];
                putchar(in[k]);
            }
            else if(out[i]>='A'&&out[i]<='Z')
            {
                k=map[out[i]-'A'];
                putchar(in[k]-32);
            }
            else
                putchar(out[i]);
        }
        printf("\n");
    }
    return 0;
}
