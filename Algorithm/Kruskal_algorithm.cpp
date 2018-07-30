#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int v,e,par[100],rank[100],count,sum;
typedef struct
{
    int start, end,cost;
}edge;
edge select[100],E[100];

int  sort(const void *a,const void *b)
{
    edge *x,*y;
    x=(edge *)a;
    y=(edge *)b;
    return x->cost-y->cost;
}

void Link(int x,int y)
{
    if(rank[x]>rank[y])
    par[y]=x;
    else
    {
        par[x]=y;
        if(rank[x]==rank[y])
        ++rank[y];
    }
}

int find_set(int i)
{
    if(par[i]!=i)
    par[i]=find_set(par[i]);
    return par[i];//u can also return i. Because i/par[i] both are same........
}

void union_(int x,int y)
{
    Link(find_set(x),find_set(y));
}
void kruskal()
{
    for(int i=1;i<=e;++i)
    if(find_set(E[i].start)!=find_set(E[i].end))
    {
        union_(E[i].start,E[i].end);
        select[count++]=E[i];
    }
    return;
}

void initialize(void)
{
    int i;
    for(i=1;i<=v;++i)
    {
        par[i]=i;
        rank[i]=0;
    }
    return;
}

int main()
{
    int i,a,b;
    while(scanf("%d %d",&v,&e)==2)
    {
        count=0;
        sum=0;
        initialize();
        for(i=1;i<=e;++i)
        {
            scanf("%d %d %d",&E[i].start,&E[i].end,&E[i].cost);
        }

        qsort((void*)&E[1],e,sizeof(edge),sort);
        kruskal();
        printf("------------\n");
        for(i=0;i<count;++i)
        {
            printf("%d %d %d\n",select[i].start,select[i].end,select[i].cost);
            sum+=select[i].cost;
        }
        printf("Total min cost is: %d\n\n",sum);
    }
    return 0;
}

/*
Input:
12 17
1 2 2
2 3 1
3 4 3
1 5 6
2 6 2
3 7 2
4 8 5
5 6 4
6 7 1
7 8 3
5 9 5
6 10 2
7 11 4
8 12 4
9 10 2
10 11 3
11 12 6
Output:
------------
2 3 1
6 7 1
9 10 2
6 10 2
2 6 2
1 2 2
10 11 3
7 8 3
3 4 3
5 6 4
8 12 4
Total min cost is: 27

*/
