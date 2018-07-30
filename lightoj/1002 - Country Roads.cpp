#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int s, d;
    int w;
    Edge(int i1, int i2, int i3)
    {
        s = i1, d = i2, w = i3;
    }

    bool operator<(const Edge other) const
    {
        return w < other.w;
    }
};

int arr[1000];

int find(int n)
{
    if(arr[n] == n)
        return n;
    else
        return arr[n] = find(arr[n]);
}

int main()
{
    int n , e;
    cin >> n >> e  ;
    int f, t, w;
    vector<Edge> g;
    for(int i = 0; i < e; ++i)
    {
        cin >> f >> t >> w;
        Edge temp(f, t, w);
        g.push_back(temp);
    }

    sort(g.begin(), g.end());
    int min_cost = 0;
    for(int i = 0; i < 1000; ++i)
        arr[i] = i;
    vector <edge> res ;
    for(int i = 0; i < g.size(); ++i)
    {
        int par1 = find(g[i].s);
        int par2 = find(g[i].d);
        if(par1 != par2)
        {
           // min_cost += g[i].w;
            res.push_back( g[i] );
            arr[par1] = par2;
        }
    }

    cin >> t ;

    queue <int>q ;
    q.push( t );


   // cout << min_cost << endl;

    return 0;
}

