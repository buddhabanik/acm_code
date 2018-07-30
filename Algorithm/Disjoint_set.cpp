//Disjointset......
#include<cstdio>
using namespace std;
int v,e,par[100],rank[100];
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
int find_set(int i)
{
    if(par[i]!=i)
    par[i]=find_set(par[i]);
    return par[i];
    //u can also return i. Because i/par[i] both are same........
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
void union_(int x,int y)
{
    Link(find_set(x),find_set(y));
}
int main()
{
    int i,a,b;
    while(scanf("%d %d",&v,&e)==2)
    {
        initialize();
        for(i=1;i<=e;++i)
        {
            scanf("%d %d",&a,&b);
            if(find_set(a)!=find_set(b))
            {
                union_(a,b);
                printf("Linked\n");
            }
            else
            printf("Not Linked\n");
        }
    }
    return 0;
}

/*
Input-Output:
10 8
1 2
Linked
2 3
Linked
1 3
Not Linked
2 4
Linked
5 6
Linked
5 4
Linked
4 6
Not Linked
8 9
Linked
*/
