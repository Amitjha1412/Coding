#include<stdio.h>
typedef struct points
{
    int x;
    int y;
}points;
int cmpfunc(const void * a,const void *b)
{const points *pkt_a = a;
      const points *pkt_b = b;
      if(pkt_b->x>pkt_a->x)
          return 1;
      else if(pkt_b->x==pkt_a->x)
          return(pkt_b->y-pkt_a->y);
      else
          return -1;
}
int main()
{
    int i,t,steps=0;
    points p[100010];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
        if(p[i].x)
            steps+=2;
        if(p[i].y)
            steps+=2;
        steps+=2;
    }
    qsort(p,t,sizeof(points),cmpfunc);
    printf("%d\n",steps);
    for(i=0;i<t;i++)
    {
        if(p[i].x)
        {
            printf("1 %d R\n",p[i].x);
            steps++;
        }
        if(p[i].y)
        {
            printf("1 %d U\n",p[i].y);
            steps++;
        }
        printf("2\n");
        steps++;
        if(p[i].y)
        {
            printf("1 %d D\n",p[i].y);
            steps++;
        }
        if(p[i].x)
        {
            printf("1 %d L\n",p[i].x);
            steps++;
        }
        printf("3\n");
        steps++;
    }
    return 0;
}
