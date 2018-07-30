#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll > g[105], co[105] ;
ll n ;

struct edge
{
    ll u,v,w;
    edge( ll u1, ll v1, ll w1)
    {
        u=u1;
        v=v1;
        w=w1;
    }
    bool operator<(const edge &p)const
    {
        return w > p.w ;
    }
} ;

ll prim( ll m )
{
    ll i,vis[105] , x,y, cost, min_cost = 0 ,  cont = 0 ;
    priority_queue < edge > q;
    for(i=0; i<g[m].size() ; i++ )
    {
        q.push( edge{m ,g[m][i], co[m][i]} );
    }
    memset(vis, 0, sizeof(vis));
    vis[m] = 1;
    while( !q.empty())
    {
        edge tem = q.top() ;
        q.pop() ;
        x = tem.u ;
        y=tem.v;

        if( vis[y] == 1)
            continue;
        vis[y] = 1;
        ++cont;
     //   cout << x << "  " << y << "   " << tem.w << endl;
        min_cost += tem.w;
        if( cont == n-1 )
        {
         //   cout << cont << "  break\n";
            break ;
        }
        for(i=0; i<g[y].size() ; i++ )
        {
            q.push( edge{y , g[y][i], co[y][i]} );
            //cout << y << "  " << g[y][i] << "   " << co[y][i] << endl;
        }
    }
 //   cout << n <<"   " <<  cont << endl ;
    return min_cost ;

}


struct edges
{
    ll u,v,w;
    edges(ll u1, ll v1, ll w1)
    {
        u=u1;
        v=v1;
        w=w1;
    }
    bool operator<(const edges &p)const
    {
        return w < p.w ;
    }
} ;

ll prims( ll m )
{

    ll i,vis[105] , x,y, cost, max_cost = 0 ,  cont = 0 ;
    priority_queue < edges > q;
    for(i=0; i<g[m].size() ; i++ )
    {
        q.push( edges{m ,g[m][i], co[m][i]} );
    }
    memset(vis, 0, sizeof(vis));
    vis[m] = 1;
    while( !q.empty())
    {
        edges tem = q.top() ;
        q.pop() ;
        x = tem.u ;
        y=tem.v;

        if( vis[y] == 1)
            continue;
        vis[y] = 1;
        ++cont;
     //   cout << x << "  " << y << "   " << tem.w << endl;
        max_cost += tem.w;
        if( cont == n-1 )
        {
         //   cout << cont << "  break\n";
            break ;
        }
        for(i=0; i<g[y].size() ; i++ )
        {
            q.push( edges{y , g[y][i], co[y][i]} );
            //cout << y << "  " << g[y][i] << "   " << co[y][i] << endl;
        }
    }
 //   cout << n <<"   " <<  cont << endl ;
    return max_cost ;

}


int main()
{
    long long int i , e, u,v ,cost , res , cas = 0, test ;
    cin >> test ;
    while( test-- )
    {

    cin >> n;
    ++n;
    while(scanf("%lld %lld %lld",&u ,&v,&cost)==3)
    {
        if( u == 0 && v == 0 && cost == 0)
            break ;
        g[u].push_back( v );
        g[v].push_back( u );
        co[u].push_back( cost );
        co[v].push_back( cost );
    }
   res = prim(0) + prims(0) ;
 //  cout << prim(0) << "     " << prims(0) << endl;
   if( res % 2 == 0)
        printf("Case %lld: %lld\n", ++cas, res/2 );
   else
        printf("Case %lld: %lld/2\n", ++cas, res );
    for(i=0; i<n ; i++ )
    {
        g[i].clear();
        co[i].clear() ;
    }

    }
    return 0;
}
