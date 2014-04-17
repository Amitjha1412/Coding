#include<stdio.h>

double Area(int X0, int Y0, int X1, int Y1, int X2, int Y2)
{
        double dArea = ((X1 - X0)*(Y2 - Y0) - (X2 - X0)*(Y1 - Y0))/2.0;
        return (dArea > 0.0) ? dArea : -dArea;
}

int main()
{
    int n,i,imin,imax,X0,X1,X2,Y0,Y1,Y2;
    double max_area=-1,min_area=1000000000;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&X0,&Y0,&X1,&Y1,&X2,&Y2);
        double a=Area(X0,Y0,X1,Y1,X2,Y2);
        if(a>=max_area)
        {
            max_area=a;
            imax=i;
        }
        if(min_area>=a)
        {
            min_area=a;
            imin=i;
        }
    }
    printf("%d %d\n",imin,imax);
    return 0;
}
