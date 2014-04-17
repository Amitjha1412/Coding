#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include<limits.h>
typedef struct Point
{
    int x, y,index;
}Point;

int index1=0,index2=0;
double d=FLT_MAX;

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}

void bruteForce(Point P[], int n)
{
    int i,j;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < d)
            {
                d = dist(P[i], P[j]);
                if(P[i].index>P[j].index)
                {
                    index1=P[j].index;
                    index2=P[i].index;
                }
                else
                {
                    index1=P[i].index;
                    index2=P[j].index;
                }
             //   printf("%d %d %f\n",index1,index2,min);
            }
}

double min(double x, double y)
{
    return (x < y)? x : y;
}

void stripClosest(Point strip[], int size)
{
    int i,j;
    qsort(strip, size, sizeof(Point), compareY);

    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < d; ++j)
            if (dist(strip[i],strip[j]) <d)
            {
                d = dist(strip[i], strip[j]);
                if(strip[i].index>strip[j].index)
                {
                    index1=strip[j].index;
                    index2=strip[i].index;
                }
                else
                {
                    index1=strip[i].index;
                    index2=strip[j].index;
                }
            }
}

void closestUtil(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    closestUtil(P, mid);
    closestUtil(P + mid, n-mid);

    Point strip[n];
    int j = 0,i;
    for (i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    stripClosest(strip, j);
}

void closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    closestUtil(P, n);
}
int main()
{
    int n,i;
    Point P[50001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&P[i].x,&P[i].y);
        P[i].index=i;
    }
    closest(P,n);
    printf("%d %d %0.6lf\n",index1,index2,d);
    return 0;
}
