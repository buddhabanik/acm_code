#include <bits/stdc++.h>
using namespace std;

vector <int> g[505];
int  n , res ;

int bfs(int s , int d)
{
    int vis[505] , le[505], i , u, v, mx , lnx;
    memset( vis, 0, sizeof(vis));
    memset( le, 0 , sizeof(le) );
    vis[s] = 1;
    le[s] = 0 ;
    queue <int> q;
    q.push(s);
    while( !q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<g[u].size() ; i++ )
        {
            v=g[u][i] ;
            if(vis[v] == 0 )
            {
                vis[v] = 1;
                q.push( v );
                le[v] = le[u]+1 ;
            }
        }
    }

    lnx = -1 ;
    mx = 0 ;
    for(i=0 ; i<n ; i++)
    {
        if(i != s && le[i] > mx && i != d )
        {
            mx = le[i] ;
            lnx = i ;
        }
    }

    if( lnx == -1 )
    {
        res += le[d] ;
        lnx = d ;
    }
    else
      res += mx ;

    return lnx ;
}


void bfs2(int s , int d)
{
    int vis[505] , le[505], i , u, v ;
    memset( vis, 0, sizeof(vis));
    memset( le, 0 , sizeof(le) );
    vis[s] = 1;
    le[s] = 0 ;
    queue <int> q;
    q.push(s);
    while( !q.empty())
    {
        u=q.front();
        q.pop();
        if( u == d )
        {
            cout << "inside " << d <<  "   "<<   le[d] << endl ;
            res += le[d] ;
            return ;
        }
        cout << "for   "<< u << endl ;
        for(i=0; i<g[u].size() ; i++ )
        {
            v=g[u][i] ;

            if(vis[v] == 0 )
            {
                vis[v] = 1;
                q.push( v );
                le[v] = le[u]+1 ;
                cout << v << "    " << le[v] << endl;
            }
        }
    }
}


int main()
{
    int  e, u,v,i, ds, s , d, test, cas = 0  ;
    scanf("%d",&test) ;
    while(test--)
    {

    scanf("%d %d",&n ,&e);
    for(i=0; i<e ; i++)
    {
        scanf("%d %d",&u, &v) ;
        g[u].push_back(v);
        g[v].push_back( u );
    }
    scanf("%d %d",&s,&d);
    res = 0 ;
    ds = bfs(s, d );
    cout << res  << "   " << ds << endl;
    bfs2(ds , d ) ;
    printf("Case %d: %d\n", ++cas ,res) ;
    for(i=0; i<n ; i++)
       g[i].clear() ;

    }
    return  0 ;
}
