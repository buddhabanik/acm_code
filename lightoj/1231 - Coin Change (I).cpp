#include <bits/stdc++.h>
using namespace std;

int c[1005],f[1005],make, n ,dp[105][1005];

int rec(int i, int w)
{
    if( i >= n )
    {
        if(w == 0)
            return 1;
        else
            return 0;
    }
    if( dp[i][w] != -1)
        return dp[i][w];
    int r = 0;
    for(int k = 0; k <= f[i]; ++k)
    {
        if(w - c[i] * k >= 0)
        {
            r += rec(i + 1, w - c[i] * k);
            if( r > 100000007)
                r %= 100000007;
        }
        else
            break;
    }
    return dp[i][w] = r;
}

int main()
{
    int i,j,k,x,test,cas=0;

    cin >> test;
    while(test--)
    {
        cin >> n >> make;
        for(i=0; i<n ; i++)
        {
            cin >> c[i];
        }
        for(i=0; i<n ; i++)
            cin >> f[i];
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", ++cas, rec(0,make));
    }
    return 0;
}
