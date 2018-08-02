#include <bits/stdc++.h>
using namespace std;

vector<int>g[1000];
vector<int>cost[1000];
int vis[100];

 struct edge{
    int u,v,dis;
    edge(int _u, int _v,int _dis)
    {
        u=_u;
        v=_v;
        dis=_dis;
    }
    edge(){}
    bool operator < (const edge &x)const
       {
         return dis > x.dis;
       }
};

int p_mst(int start, int n)
{
    int i,sum=0, cont=0,u,v;
    priority_queue<edge>q;
    for(i=0; i<g[start].size(); i++)
    {
        //        q.push(edge(start, g[start][i], cost[start][i]));
        edge tem;
        tem.u=start;
        tem.v=g[start][i];
        tem.dis=cost[start][i];

        q.push(tem);
    }
    vis[start]=1;

    while(!q.empty())
    {
         edge tem=q.top();
        q.pop();
        u=tem.u;
        v=tem.v;
        if(vis[v] == 1)
            continue;
        cont++;
        sum += tem.dis;

        if(cont == n-1)
            return sum;
        vis[v]=1;

        for(i=0; i<g[v].size(); i++)
        {
            q.push(edge(v,g[v][i],cost[v][i]));
        }
    }
    return sum;

}


int main()
{
    int n,e,i,co,x,y,res;
    scanf("%d %d",&n,&e);
    for(i=0; i<e ; i++)
    {
    scanf("%d %d %d",&x,&y,&co);
    g[x].push_back(y);
    g[y].push_back(x);
    cost[x].push_back(co);
    cost[y].push_back(co);
    }

    res=p_mst(1,n);
    printf("%d\n",res);


    return 0;
}
