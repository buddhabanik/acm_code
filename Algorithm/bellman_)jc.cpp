#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<ll>g[1000];
vector<ll>cost[1000];
ll dis[100], par[100];



void bellman(ll s,ll n)
{

    ll i,j,k,v, tag =1 ;
    for(i=0; i<=n ;i++)
        par[i]=i;
    cout << "SDS" << endl;
    memset(dis, 63, sizeof(dis));
    dis[s]=0;
    for(k=0; k<n; k++)
        for(i=1; i<=n ; i++)
            for(j=0; j<g[i].size(); j++)
            {
                v=g[i][j];
                if(dis[v] > dis[i] + cost[i][j])
                {
                    dis[v]=dis[i]+cost[i][j];
                    par[v]=i;
                }
            }

    for(i=1; i<=n ; i++)
        for(j=0; j<g[i].size(); j++)
        {
            v=g[i][j];
            if(dis[v] > dis[i] + cost[i][j])
            {
                tag=0;
                    cout << "000SDS" << endl;
            }
        }

    if(tag == 1)
     for(i=1; i<=n; i++)
         printf("%lld -> %lld\n",i,dis[i]);
    else
        printf("negative cycle\n");
}

void find_path(ll s,ll e)
{
    if(par[e] != e)
    {
        cout << e <<"  ";
        return find_path(s ,par[e]);

    }
    else
    {
        cout << e << endl;
        return;
    }
}


int main()
{
    ll n,e,i,co,x,y,res,start, ed;
    scanf("%lld %lld",&n,&e);
    for(i=0; i<e ; i++)
    {
        scanf("%lld %lld %lld",&x,&y,&co);
        g[x].push_back(y);
//    g[y].push_back(x);
        cost[x].push_back(co);
//    cost[y].push_back(co);
    }
//    cout << "dwdw" << endl;
    scanf("%lld %lld",&start,&ed);
    bellman( start, n);
    find_path(start,ed);

    return 0;
}

