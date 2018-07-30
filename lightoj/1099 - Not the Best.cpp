#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define s scanf
#define p printf
#define ll long long int
vector<ll >ver[50];
vector<ll >cost[50];
ll  par[50],dist[50];

struct data
{
    ll  address,dis;
    data(ll  a,ll  b)
    {
        address=a;
        dis=b;
    }
    bool operator<(const data &x)const
    {
        return dis>x.dis;
    }
};
ll  dijkstra(ll  start,ll  end)
{
    dist[start]=0;
    priority_queue<data>q;

    ll  sz,u,v,i;
    q.push(data(start,dist[start]));
    while(!q.empty())
    {
        data temp=q.top();
        q.pop();
        u=temp.address;

        if(u==end)
        return dist[end];
        sz=ver[u].size();
        for(i=0;i<sz;++i)
        {
            v=ver[u][i];
            ll  t=dist[u]+cost[u][i];
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
int  main()
{
    ll  a,b,c,d,e,n,i,j,k,start,end,ans;
    while(s("%lld %lld",&n,&e)==2)
    {
        for(i=1;i<=e;++i)
        {
            s("%lld %lld %lld ",&a,&b,&c);
            ver[a].push_back(b);
            ver[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        memset(par,0,sizeof(par));
        memset(dist,63,sizeof(dist));
        s("%lld %lld",&start,&end);
        ans=dijkstra( 1 ,n );

        if(ans==-1)
        p("Impossible.\n");
        else
        p("Minimum distance is: %lld\n",ans);
        for(i=1;i<=n;++i)
        {
            ver[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

