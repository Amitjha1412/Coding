#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t;
    long long int l,d,s,c,a;
    scanf("%d",&t);
    while(t--)
    {
        cin>>l>>d>>s>>c;
        a=s;
        c=1+c;
        d=d-1;
        while(d)
        {
            if(d%2==1)
                a=a*c;
            c=c*c;
            d=d/2;
            if(a>=l)
                break;
        }
        if(a>=l)
            cout<<"ALIVE AND KICKING"<<endl;
        else
            cout<<"DEAD AND ROTTING"<<endl;
    }
    return 0;
}
