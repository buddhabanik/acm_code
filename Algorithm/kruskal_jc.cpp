#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,dis;
    bool operator < (const edge &p)const
    {
        return dis < p.dis;
    }
};
edge ed[1000];
int par[100];

int find(int n)
{
    if(par[n] == n)
        return n;
    else
       find(par[n]);
}

int k_mst(int n,int vt)
{
    int u,v,dis,i,find_u,find_v, sum=0, cont=0;
    sort(ed, ed+vt);

    for(i=1; i<=n ; i++)
        par[i]=i;

    for(i=0; i<vt ; i++)
    {
        u=ed[i].u;
        v=ed[i].v;
        dis=ed[i].dis;
        find_u=find(u);
        find_v=find(v);

        if( find_u != find_v )
        {
            par[find_v] = find_u;
            sum += dis;
            cont++;
            if(cont == n-1)
                return sum;
        }
    }
    return sum;

}

int main()
{
    int u,v,dis,i,n, res ;
    scanf("%d %d",&n,&v);
    for(i=0; i<v ; i++)
    {
        scanf("%d %d %d",&ed[i].u,&ed[i].v,&ed[i].dis);
    }

//
//    for(i=0; i<v ; i++)
//    {
//        printf("                %d %d %d\n",ed[i].u, ed[i].v, ed[i].dis);
//    }
    res = k_mst(n,v);
    printf("%d\n",res);

    return 0;
}

