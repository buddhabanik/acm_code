#include <stdio.h>

#define ll long long int



ll dis[100], par[100];
ll g[1000][1000];
ll cost[1000][1000];


void bellman(ll s,ll n)
{
    ll i,j,k,v, tag =1 ;
    for(i=0; i<=n ; i++)
        par[i]=i;
    for(i=0; i<=n ; i++)
        dis[i]=9999999999999999;

    dis[s]=0;
    for(k=0; k<n; k++)
        for(i=1; i<=n ; i++)
            for(j=1; j<=n; j++)
            {
                if(g[i][j] == 1)
                {
                    if(dis[j] > dis[i] + cost[i][j])
                    {
                        dis[j]=dis[i]+cost[i][j];
                        par[j]=i;
                    }
                }
            }

    for(i=1; i<=n ; i++)
        for(j=0; j<=n; j++)
        {
            if(g[i][j] == 1)
                if(dis[j] > dis[i] + cost[i][j])
                {
                    tag=0;
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

       // return
         find_path(s,par[e]);
         printf("%lld ",e);

    }
    else
    {
            printf("path of  %lld ",e);
      //  return;
    }
}


int main()
{
    ll n,e,i,co,x,y,res,start, ed;
    scanf("%lld %lld",&n,&e);
    for(i=0; i<e ; i++)
    {
        scanf("%lld %lld %lld",&x,&y,&co);
        g[x][y] = 1;
//    g[y].push_back(x);
        cost[x][y] = co;
//    cost[y].push_back(co);
    }
//    cout << "dwdw" << endl;
    scanf("%lld %lld",&start,&ed);
    bellman( start, n);
    find_path(start,ed);

    return 0;
}

//6 6
//1 3 2
//1 4 4
//2 3 10
//3 4 1
//4 6 5
//4 5 7
//1 5


