#include <stdio.h>
#include <math.h>
#define sz 100

typedef struct
{
    long x,y;
} point;

typedef struct
{
    point s,e;
} line;

line l[sz];

long MAX(long a,long b)
{
    if(a>=b)
        return a;
    return b;
}

long MIN(long a,long b)
{
    if(a<=b)
        return a;
    return b;
}

long direction(point p0,point p1, point p2)
{
    return (((p2.x-p0.x)*(p1.y-p0.y))-((p1.x-p0.x)*(p2.y-p0.y)));
}

bool on_segment(point pi,point pj,point pk)
{
    if((MIN(pi.x,pj.x)<=pk.x && pk.x<=MAX(pi.x,pj.x)) &&
            (MIN(pi.y,pj.y)<=pk.y && pk.y<=MAX(pi.y,pj.y)) )
        return true;
    return false;
}

bool segment_intersect(point p1,point p2,point p3,point p4)
{
    long d1,d2,d3,d4;

    d1=direction(p3,p4,p1);
    d2=direction(p3,p4,p2);
    d3=direction(p1,p2,p3);
    d4=direction(p1,p2,p4);

    if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&
            ((d3>0 && d4<0) || (d3<0 && d4>0)))
        return true;
    else if(d1==0 && on_segment(p3,p4,p1))
        return true;
    else if(d2==0 && on_segment(p3,p4,p2))
        return true;
    else if(d3==0 && on_segment(p1,p2,p3))
        return true;
    else if(d4==0 && on_segment(p1,p2,p4))
        return true;
    else
        return false;
}

int main()
{
    long n,t,f,count,i,j;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%ld", &n);
        count=0;
        for(i=1; i<=n; i++)
            scanf("%ld %ld %ld %ld", &l[i].s.x, &l[i].s.y, &l[i].e.x, &l[i].e.y);
        for(i=1; i<=n; i++)
        {
            for(j=1,f=0; j<=n; j++)
            {
                if(segment_intersect(l[i].s,l[i].e,l[j].s,l[j].e) && i!=j)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                count++;
            }
        }
        printf("%ld\n", count);
    }
    return 0;
}
