#include <bits/stdc++.h>
using namespace std ;

#define Max  30005
#define ll long long int
vector < ll > g[Max];
map <pair<ll, ll >, ll > m ;
ll n ;

ll bfs( ll s )
{
    ll visit[n], level[n], u, i , Mx  , indx , par[n] ;
    memset(visit, 0, sizeof(visit));
    memset( level, 0, sizeof(level));
    visit[s] = 1;
    queue <ll> q;
    q.push(s) ;
    level[s] = 0;
    while( !q.empty() )
    {
        u = q.front();
        q.pop() ;
        for(i=0; i<g[u].size() ; i++ )
        {
            if( !visit[g[u][i]] )
            {
                visit[g[u][i]] = 1;
                q.push( g[u][i] );
                level[g[u][i]] = level[u] +  m[{u, g[u][i]}]   ;
                par[g[u][i]] = u ;
            }
        }
    }
    Mx = level[0] ;
    indx = 0;
    for(i =1; i<n ; i++ )
    {
        if( level[i] >= Mx )
        {
//            if( level[i] == Mx )
//            {
//                ll x , y ;
//                x = m[{par[i], i }];
//                y = m[{par[indx], indx }];
//                if( x > y )
//                    indx = i ;
//            }
//            else
//            {
            indx = i ;
//            }
            Mx = level[i] ;
        }
    }
    return indx  ;

}

ll bfs_cost( ll s )
{
    ll visit[n], level[n], u, i , Mx  , cas =0 ;
    memset(visit, 0, sizeof(visit));
    memset( level, 0, sizeof(level));
    visit[s] = 1;
    queue <ll > q;
    q.push(s) ;
    level[s] = 0;
    while( !q.empty() )
    {
        u = q.front();
        q.pop() ;
        for(i=0; i<g[u].size() ; i++ )
        {
            if( !visit[g[u][i]] )
            {
                visit[g[u][i]] = 1;
                q.push( g[u][i] );
                level[g[u][i]] = level[u] + m[{u, g[u][i]}] ;

            }
        }
    }
    Mx = level[0] ;

    for(i = 1 ; i<n ; i++ )
    {
        if( level[i] >= Mx )
        {
            Mx = level[i] ;
        }
    }
    return Mx ;

}

int main()
{
    ll i, u,v , cost , s , test, cas =0  ;
    scanf("%lld", &test);
    while( test-- )
    {
    scanf("%lld",&n);
    for( i=0; i<n-1 ; i++ )
    {
        scanf("%lld %lld %lld", &u, &v , &cost );
        g[u].push_back(v) ;
        g[v].push_back(u);
        m[{u,v}] = cost;
        m[{v,u}] = cost ;
    }
    s = bfs(0) ;
    //cout << s << endl;
    printf("Case %lld: %lld\n", ++cas , bfs_cost( s ));
    for(i=0; i<n ; i++ )
    {
        g[i].clear();
       // c[i].clear() ;
    }
    m.clear() ;
    }
    return 0;
}
