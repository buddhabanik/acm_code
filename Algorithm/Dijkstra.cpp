//dijkstra_by_myself
//non-directed graph.....
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define s scanf
#define p printf
//#define ll  long long int

vector<long long int >ver[50];
vector<long long int  >cost[50];

long long int   par[50],dist[50];

struct data
{
    long long int   address,dis;
    data(long long int   a,long long int   b)
    {
        address=a;
        dis=b;
    }
    bool operator<(const data &x)const
    {
        return dis>x.dis;
    }
};

long long int   dijkstra(long long int   start,long long int   end)
{
    dist[start]=0;
    priority_queue<data>q;

    long long int   sz,u,v,i;
    q.push(data(start,dist[start]));
    while(!q.empty())
    {
        data temp=q.top();
        q.pop();
        u=temp.address;
        //v=temp.dis;
        if(u==end)
        return dist[end];
        sz=ver[u].size();
        for(i=0;i<sz;++i)
        {
            v=ver[u][i];
            long long int  t=dist[u]+cost[u][i];
            if(dist[v]>t)
            {
                dist[v]=t;
                q.push(data(v,dist[v]));
                par[v]=u;
            }
        }
    }
    return -1;
}

void show_path(long long int  start,long long int end)
{
    if( start == end)
    {
        cout << end << endl;
        return;
    }
    else
    {
        cout<< end << endl;
        show_path( start, par[end] );
    }
    return ;
}

int  main()
{
    long long int   a,b,c,d,e,n,i,j,k,start,end,ans;
    while(s("%lld %lld",&n,&e)==2)
    {
        for(i=1;i<=e;++i)
        {
            s("%lld %lld %lld",&a,&b,&c);
            ver[a].push_back(b);
            ver[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        memset(par,0,sizeof(par));
        memset(dist,63,sizeof(dist));
        s("%lld %lld",&start,&end);
        ans=dijkstra(start,end);

        if(ans==-1)
        p("Impossible.\n");
        else
        p("Minimum distance is: %lld\n",ans);
        show_path(start,end);




        for(i=1;i<=n;++i)
        {
            ver[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
/*
Input:
5 6
1 3 10
1 2 25
1 3 40
2 5 50
3 5 50
4 5 70
1 5
output:
Minimum distance is: 75
*/
